#include <cmath>
#include "segments/Vector3D.h"

double Vector3D::dot(const Vector3D &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

double Vector3D::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}
