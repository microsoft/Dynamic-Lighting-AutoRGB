/****************************************************************************
 *
 * Vector3 
 * 
 * Taken from the DirectX SimpleMath library
 *
 ****************************************************************************/
         
#include "Vector3.h"

 //------------------------------------------------------------------------------
 // Comparision operators
 //------------------------------------------------------------------------------

bool Vector3::operator == (const Vector3& V) const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&V);
    return XMVector3Equal(v1, v2);
}

bool Vector3::operator != (const Vector3& V) const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&V);
    return XMVector3NotEqual(v1, v2);
}

//------------------------------------------------------------------------------
// Assignment operators
//------------------------------------------------------------------------------

Vector3& Vector3::operator+= (const Vector3& V) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&V);
    const XMVECTOR X = XMVectorAdd(v1, v2);
    XMStoreFloat3(this, X);
    return *this;
}

Vector3& Vector3::operator-= (const Vector3& V) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&V);
    const XMVECTOR X = XMVectorSubtract(v1, v2);
    XMStoreFloat3(this, X);
    return *this;
}

Vector3& Vector3::operator*= (const Vector3& V) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&V);
    const XMVECTOR X = XMVectorMultiply(v1, v2);
    XMStoreFloat3(this, X);
    return *this;
}

Vector3& Vector3::operator*= (float S) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR X = XMVectorScale(v1, S);
    XMStoreFloat3(this, X);
    return *this;
}

Vector3& Vector3::operator/= (float S) noexcept
{
    using namespace DirectX;
    assert(S != 0.0f);
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR X = XMVectorScale(v1, 1.f / S);
    XMStoreFloat3(this, X);
    return *this;
}

//------------------------------------------------------------------------------
// Urnary operators
//------------------------------------------------------------------------------

Vector3 Vector3::operator- () const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR X = XMVectorNegate(v1);
    Vector3 R;
    XMStoreFloat3(&R, X);
    return R;
}

//------------------------------------------------------------------------------
// Binary operators
//------------------------------------------------------------------------------

Vector3 operator+ (const Vector3& V1, const Vector3& V2) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(&V1);
    const XMVECTOR v2 = XMLoadFloat3(&V2);
    const XMVECTOR X = XMVectorAdd(v1, v2);
    Vector3 R;
    XMStoreFloat3(&R, X);
    return R;
}

Vector3 operator- (const Vector3& V1, const Vector3& V2) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(&V1);
    const XMVECTOR v2 = XMLoadFloat3(&V2);
    const XMVECTOR X = XMVectorSubtract(v1, v2);
    Vector3 R;
    XMStoreFloat3(&R, X);
    return R;
}

Vector3 operator* (const Vector3& V1, const Vector3& V2) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(&V1);
    const XMVECTOR v2 = XMLoadFloat3(&V2);
    const XMVECTOR X = XMVectorMultiply(v1, v2);
    Vector3 R;
    XMStoreFloat3(&R, X);
    return R;
}

Vector3 operator* (const Vector3& V, float S) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(&V);
    const XMVECTOR X = XMVectorScale(v1, S);
    Vector3 R;
    XMStoreFloat3(&R, X);
    return R;
}

Vector3 operator/ (const Vector3& V1, const Vector3& V2) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(&V1);
    const XMVECTOR v2 = XMLoadFloat3(&V2);
    const XMVECTOR X = XMVectorDivide(v1, v2);
    Vector3 R;
    XMStoreFloat3(&R, X);
    return R;
}

Vector3 operator/ (const Vector3& V, float S) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(&V);
    const XMVECTOR X = XMVectorScale(v1, 1.f / S);
    Vector3 R;
    XMStoreFloat3(&R, X);
    return R;
}

Vector3 operator* (float S, const Vector3& V) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(&V);
    const XMVECTOR X = XMVectorScale(v1, S);
    Vector3 R;
    XMStoreFloat3(&R, X);
    return R;
}

//------------------------------------------------------------------------------
// Vector operations
//------------------------------------------------------------------------------

bool Vector3::InBounds(const Vector3& Bounds) const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&Bounds);
    return XMVector3InBounds(v1, v2);
}

float Vector3::Length() const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR X = XMVector3Length(v1);
    return XMVectorGetX(X);
}

float Vector3::LengthSquared() const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR X = XMVector3LengthSq(v1);
    return XMVectorGetX(X);
}

float Vector3::Dot(const Vector3& V) const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&V);
    const XMVECTOR X = XMVector3Dot(v1, v2);
    return XMVectorGetX(X);
}

void Vector3::Cross(const Vector3& V, Vector3& result) const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&V);
    const XMVECTOR R = XMVector3Cross(v1, v2);
    XMStoreFloat3(&result, R);
}

Vector3 Vector3::Cross(const Vector3& V) const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&V);
    const XMVECTOR R = XMVector3Cross(v1, v2);

    Vector3 result;
    XMStoreFloat3(&result, R);
    return result;
}

void Vector3::Normalize() noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR X = XMVector3Normalize(v1);
    XMStoreFloat3(this, X);
}

void Vector3::Normalize(Vector3& result) const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR X = XMVector3Normalize(v1);
    XMStoreFloat3(&result, X);
}

void Vector3::Clamp(const Vector3& vmin, const Vector3& vmax) noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&vmin);
    const XMVECTOR v3 = XMLoadFloat3(&vmax);
    const XMVECTOR X = XMVectorClamp(v1, v2, v3);
    XMStoreFloat3(this, X);
}

void Vector3::Clamp(const Vector3& vmin, const Vector3& vmax, Vector3& result) const noexcept
{
    using namespace DirectX;
    const XMVECTOR v1 = XMLoadFloat3(this);
    const XMVECTOR v2 = XMLoadFloat3(&vmin);
    const XMVECTOR v3 = XMLoadFloat3(&vmax);
    const XMVECTOR X = XMVectorClamp(v1, v2, v3);
    XMStoreFloat3(&result, X);
}

//------------------------------------------------------------------------------
// Static functions
//------------------------------------------------------------------------------

float Vector3::Distance(const Vector3& v1, const Vector3& v2) noexcept
{
    using namespace DirectX;
    const XMVECTOR x1 = XMLoadFloat3(&v1);
    const XMVECTOR x2 = XMLoadFloat3(&v2);
    const XMVECTOR V = XMVectorSubtract(x2, x1);
    const XMVECTOR X = XMVector3Length(V);
    return XMVectorGetX(X);
}

float Vector3::DistanceSquared(const Vector3& v1, const Vector3& v2) noexcept
{
    using namespace DirectX;
    const XMVECTOR x1 = XMLoadFloat3(&v1);
    const XMVECTOR x2 = XMLoadFloat3(&v2);
    const XMVECTOR V = XMVectorSubtract(x2, x1);
    const XMVECTOR X = XMVector3LengthSq(V);
    return XMVectorGetX(X);
}

void Vector3::Min(const Vector3& v1, const Vector3& v2, Vector3& result) noexcept
{
    using namespace DirectX;
    const XMVECTOR x1 = XMLoadFloat3(&v1);
    const XMVECTOR x2 = XMLoadFloat3(&v2);
    const XMVECTOR X = XMVectorMin(x1, x2);
    XMStoreFloat3(&result, X);
}

Vector3 Vector3::Min(const Vector3& v1, const Vector3& v2) noexcept
{
    using namespace DirectX;
    const XMVECTOR x1 = XMLoadFloat3(&v1);
    const XMVECTOR x2 = XMLoadFloat3(&v2);
    const XMVECTOR X = XMVectorMin(x1, x2);

    Vector3 result;
    XMStoreFloat3(&result, X);
    return result;
}

void Vector3::Max(const Vector3& v1, const Vector3& v2, Vector3& result) noexcept
{
    using namespace DirectX;
    const XMVECTOR x1 = XMLoadFloat3(&v1);
    const XMVECTOR x2 = XMLoadFloat3(&v2);
    const XMVECTOR X = XMVectorMax(x1, x2);
    XMStoreFloat3(&result, X);
}

Vector3 Vector3::Max(const Vector3& v1, const Vector3& v2) noexcept
{
    using namespace DirectX;
    const XMVECTOR x1 = XMLoadFloat3(&v1);
    const XMVECTOR x2 = XMLoadFloat3(&v2);
    const XMVECTOR X = XMVectorMax(x1, x2);

    Vector3 result;
    XMStoreFloat3(&result, X);
    return result;
}