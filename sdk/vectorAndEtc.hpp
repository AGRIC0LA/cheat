#pragma once
#include "../imgui/imgui.h"
#include <iostream>

struct Vector3
{
	float x, y, z;
    Vector3(float x_ = 0, float y_ = 0, float z_ = 0){
        x = x_;
        y = y_;
        z = z_;
    }

    Vector3 operator-(Vector3 other) {
        return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
    }

	float Distance(Vector3& b)
	{
		Vector3 vector = Vector3(x - b.x, y - b.y, z - b.z);
		return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
	}

    static Vector3 Cross(Vector3 lhs, Vector3 rhs) {
        return Vector3(lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z,
            lhs.x * rhs.y - lhs.y * rhs.x);
    }

    static float Magnitude(Vector3 vector) { return (float)sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z); }

    static Vector3 Normalize(Vector3 value)
    {
        float mag = Magnitude(value);
        if (mag > 0.00001F)
            return Vector3(value.x / mag, value.y / mag, value.z / mag);
        else
            return Vector3(0, 0, 0);
    }

    friend std::ostream& operator<<(std::ostream& ostream, Vector3& vector) {
        return ostream << vector.x << " " << vector.y << " " << vector.z ;
    }
};


struct Vector2 {
    float x, y;
    Vector2(float x_ = 0, float y_ = 0) {
        x = x_;
        y = y_;
    }

    Vector2(Vector3& vec) {
        this->x = vec.x;
        this->y = vec.y;
    }
};


struct Color
{
	float r, g, b, a;

    Color(float r_ = 0, float g_ = 0, float b_ = 0, float a_ = 0){
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }

    ImColor convert() {
        return ImColor(r, g, b, a);
    } 

    friend std::ostream& operator<<(std::ostream& ostream, Color& color) {
        return ostream << color.r << " " << color.g << " " << color.b << " " << color.a;
    }
};

struct Quaternion
{
	float x, y, z, w;
    static Quaternion QuaternionLookRotation(Vector3 forward, Vector3 up)
    {
        Vector3::Normalize(forward);

        Vector3 vector = Vector3::Normalize(forward);
        Vector3 vector2 = Vector3::Normalize(Vector3::Cross(up, vector));
        Vector3 vector3 = Vector3::Cross(vector, vector2);
        auto m00 = vector2.x;
        auto m01 = vector2.y;
        auto m02 = vector2.z;
        auto m10 = vector3.x;
        auto m11 = vector3.y;
        auto m12 = vector3.z;
        auto m20 = vector.x;
        auto m21 = vector.y;
        auto m22 = vector.z;


        float num8 = (m00 + m11) + m22;
        auto quaternion = Quaternion();
        if (num8 > 0.f)
        {
            auto num = (float)sqrt(num8 + 1.f);
            quaternion.w = num * 0.5f;
            num = 0.5f / num;
            quaternion.x = (m12 - m21) * num;
            quaternion.y = (m20 - m02) * num;
            quaternion.z = (m01 - m10) * num;
            return quaternion;
        }
        if ((m00 >= m11) && (m00 >= m22))
        {
            auto num7 = (float)sqrt(((1.f + m00) - m11) - m22);
            auto num4 = 0.5f / num7;
            quaternion.x = 0.5f * num7;
            quaternion.y = (m01 + m10) * num4;
            quaternion.z = (m02 + m20) * num4;
            quaternion.w = (m12 - m21) * num4;
            return quaternion;
        }
        if (m11 > m22)
        {
            auto num6 = (float)sqrt(((1.f + m11) - m00) - m22);
            auto num3 = 0.5f / num6;
            quaternion.x = (m10 + m01) * num3;
            quaternion.y = 0.5f * num6;
            quaternion.z = (m21 + m12) * num3;
            quaternion.w = (m20 - m02) * num3;
            return quaternion;
        }
        auto num5 = (float)sqrt(((1.f + m22) - m00) - m11);
        auto num2 = 0.5f / num5;
        quaternion.x = (m20 + m02) * num2;
        quaternion.y = (m21 + m12) * num2;
        quaternion.z = 0.5f * num5;
        quaternion.w = (m01 - m10) * num2;
        return quaternion;
    }   

    friend std::ostream& operator<<(std::ostream& ostream, Quaternion& quaternion) {
        return ostream << quaternion.x << " " << quaternion.y << " " << quaternion.z << " " << quaternion.w;
    }
};

inline float screen_distance(Vector2 p1, Vector2 p2) {
    float diffY = p1.y - p2.y;
    float diffX = p1.x - p2.x;
    return sqrt((diffY * diffY) + (diffX * diffX));
}