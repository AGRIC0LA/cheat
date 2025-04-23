#include "d3d11.h"
#include "kiero/kiero.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"
#include "cvar.h"
#include "menu.h"
#include "font.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace dx_hook {
	ImFont* font;
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	HWND window;
	WNDPROC wndproc_o;
	ID3D11RenderTargetView* main_render_target_view;

	void imgui_init() {
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
		ImGui_ImplWin32_Init(window);
		ImGui_ImplDX11_Init(device, context);

		static const ImWchar glyph_range[] = {
		  0x0020,
		  0xFFFF,
		  0,
		};

		font = io.Fonts->AddFontFromMemoryTTF(&font_array, sizeof(font_array), 14, 0, glyph_range);
	}

	LRESULT __stdcall wndproc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
			return true;

		return CallWindowProc(wndproc_o, hWnd, uMsg, wParam, lParam);
	}

	typedef HRESULT(__stdcall* present_t)(IDXGISwapChain*, UINT, UINT);
	present_t present_o;
	HRESULT present_hk(IDXGISwapChain* swap_chain, UINT rdx, UINT r8) {
		static bool is_inited = false;
		if (!is_inited) {
			if (SUCCEEDED(swap_chain->GetDevice(__uuidof(ID3D11Device), (void**)&device))) {
				device->GetImmediateContext(&context);
				DXGI_SWAP_CHAIN_DESC sd;
				swap_chain->GetDesc(&sd);
				window = sd.OutputWindow;
				ID3D11Texture2D* pBackBuffer;
				swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
				device->CreateRenderTargetView(pBackBuffer, NULL, &main_render_target_view);
				pBackBuffer->Release();
				wndproc_o = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)wndproc);
				imgui_init();
				is_inited = true;
			}
			else
				return present_o(swap_chain, rdx, r8);
		}

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		ImGui::PushFont(font);

		menu::draw_menu();
		cvar::draw_esp();

		ImGui::PopFont();
		ImGui::Render();

		context->OMSetRenderTargets(1, &main_render_target_view, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		return present_o(swap_chain, rdx, r8);
	}

	typedef HRESULT(__stdcall* resize_buffer_t)(IDXGISwapChain* p_swap_chain, UINT buffer_count, UINT widt, UINT height, DXGI_FORMAT new_format, UINT swap_chain_flags);
	resize_buffer_t resize_buffer_o;
	HRESULT resize_buffer_hk(IDXGISwapChain* p_swap_chain, UINT buffer_count, UINT widt, UINT height, DXGI_FORMAT new_format, UINT swap_chain_flags) {
		if (main_render_target_view) {
			context->OMSetRenderTargets(0, 0, 0);
			main_render_target_view->Release();
		}

		HRESULT resizeBuffers = resize_buffer_o(p_swap_chain, buffer_count, widt, height, new_format, swap_chain_flags);

		ID3D11Texture2D* pBuffer;
		HRESULT pSwapChainBuffer = p_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBuffer);

		HRESULT pDeviceRenderTarget = device->CreateRenderTargetView(pBuffer, NULL, &main_render_target_view);

		pBuffer->Release();

		context->OMSetRenderTargets(1, &main_render_target_view, NULL);

		return resizeBuffers;
	}
}