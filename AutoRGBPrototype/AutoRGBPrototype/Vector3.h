#pragma once

/****************************************************************************
 *
 * Vector3
 *
 * Taken from the DirectX SimpleMath library
 *
 ****************************************************************************/

#include <DirectXMath.h>

using namespace DirectX;

struct Vector3 : public XMFLOAT3
{
    Vector3() noexcept : XMFLOAT3(0.f, 0.f, 0.f) {}
    constexpr explicit Vector3(float ix) noexcept : XMFLOAT3(ix, ix, ix) {}
    constexpr Vector3(float ix, float iy, float iz) noexcept : XMFLOAT3(ix, iy, iz) {}
    explicit Vector3(_In_reads_(3) const float* pArray) noexcept : XMFLOAT3(pArray) {}
    Vector3(FXMVECTOR V) noexcept { XMStoreFloat3(this, V); }
    Vector3(const XMFLOAT3& V) noexcept { this->x = V.x; this->y = V.y; this->z = V.z; }
    explicit Vector3(const XMVECTORF32& F) noexcept { this->x = F.f[0]; this->y = F.f[1]; this->z = F.f[2]; }

    Vector3(const Vector3&) = default;
    Vector3& operator=(const Vector3&) = default;

    Vector3(Vector3&&) = default;
    Vector3& operator=(Vector3&&) = default;

    operator XMVECTOR() const noexcept { return XMLoadFloat3(this); }

    // Comparison operators
    bool operator == (const Vector3& V) const noexcept;
    bool operator != (const Vector3& V) const noexcept;

    // Assignment operators
    Vector3& operator= (const XMVECTORF32& F) noexcept { x = F.f[0]; y = F.f[1]; z = F.f[2]; return *this; }
    Vector3& operator+= (const Vector3& V) noexcept;
    Vector3& operator-= (const Vector3& V) noexcept;
    Vector3& operator*= (const Vector3& V) noexcept;
    Vector3& operator*= (float S) noexcept;
    Vector3& operator/= (float S) noexcept;

    // Unary operators
    Vector3 operator+ () const noexcept { return *this; }
    Vector3 operator- () const noexcept;

    // Vector operations
    bool InBounds(const Vector3& Bounds) const noexcept;

    float Length() const noexcept;
    float LengthSquared() const noexcept;

    float Dot(const Vector3& V) const noexcept;
    void Cross(const Vector3& V, Vector3& result) const noexcept;
    Vector3 Cross(const Vector3& V) const noexcept;

    void Normalize() noexcept;
    void Normalize(Vector3& result) const noexcept;

    void Clamp(const Vector3& vmin, const Vector3& vmax) noexcept;
    void Clamp(const Vector3& vmin, const Vector3& vmax, Vector3& result) const noexcept;

    // Static functions
    static float Distance(const Vector3& v1, const Vector3& v2) noexcept;
    static float DistanceSquared(const Vector3& v1, const Vector3& v2) noexcept;

    static void Min(const Vector3& v1, const Vector3& v2, Vector3& result) noexcept;
    static Vector3 Min(const Vector3& v1, const Vector3& v2) noexcept;

    static void Max(const Vector3& v1, const Vector3& v2, Vector3& result) noexcept;
    static Vector3 Max(const Vector3& v1, const Vector3& v2) noexcept;

    // Constants
    static const Vector3 Zero;
    static const Vector3 One;
    static const Vector3 UnitX;
    static const Vector3 UnitY;
    static const Vector3 UnitZ;
    static const Vector3 Up;
    static const Vector3 Down;
    static const Vector3 Right;
    static const Vector3 Left;
    static const Vector3 Forward;
    static const Vector3 Backward;
};

// Binary operators
Vector3 operator+ (const Vector3& V1, const Vector3& V2) noexcept;
Vector3 operator- (const Vector3& V1, const Vector3& V2) noexcept;
Vector3 operator* (const Vector3& V1, const Vector3& V2) noexcept;
Vector3 operator* (const Vector3& V, float S) noexcept;
Vector3 operator/ (const Vector3& V1, const Vector3& V2) noexcept;
Vector3 operator/ (const Vector3& V, float S) noexcept;
Vector3 operator* (float S, const Vector3& V) noexcept;
