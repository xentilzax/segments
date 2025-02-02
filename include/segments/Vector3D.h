#pragma once
#include "segments/Point3D.h"

class Vector3D : public Point3D
{
public:
    Vector3D(const Point3D &point)
        : Point3D(point) {}
    Vector3D(double x = 0, double y = 0, double z = 0)
        : Point3D(x, y, z) {}
    Vector3D(const Point3D &start, const Point3D &end)
        : Point3D(end.x - start.x, end.y - start.y, end.z - start.z) {}

    double dot(const Vector3D &other) const;
    double length() const;

    Vector3D operator+(const Vector3D &other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }
    
    Vector3D operator-(const Vector3D &other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D operator*(double a) const {
        return Vector3D(x * a, y * a, z *a);
    }
};
