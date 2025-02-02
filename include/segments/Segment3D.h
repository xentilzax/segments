#pragma once
#include "segments/Vector3D.h"

class Segment3D
{
public:
    Vector3D start, end;

    Segment3D(const Vector3D &start, const Vector3D &end)
        : start(start), end(end) {}

    double distance(const Segment3D &other) const;
    double distance(const Vector3D &point) const;
};
