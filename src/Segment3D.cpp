#include "segments/Vector3D.h"
#include "segments/Segment3D.h"

#define LIKE_ZERO 1e-6 

double Segment3D::distance(const Segment3D &other) const
{
    Vector3D u(end - start);
    Vector3D v(other.end - other.start);
    Vector3D w(start - other.start);

    double a = u.dot(u); // Squared length of u
    double b = u.dot(v); // u · v
    double c = v.dot(v); // Squared length of v
    double d = u.dot(w); // u · w
    double e = v.dot(w); // v · w

    if (a < LIKE_ZERO and c < LIKE_ZERO) {
        return Vector3D(start, other.start).length();
    }

    if (a < LIKE_ZERO) {
        return other.distance(*this);
    }

    double D = a * c - b * b;

    if (D < LIKE_ZERO)
    {
        // if segments make plane => parallel
        double d1 = distance(other.start);
        double d2 = distance(other.end);
        double r = d1 < d2 ? d1 : d2;
        double d3 = other.distance(start);
        double d4 = other.distance(end);
        r = r < d3 ? r : d3;
        r = r < d4 ? r : d4;
        return r;
    }

    // Расчет параметров, которые нужны для нахождения ближайшей точки на обоих отрезках
    double s = (b * e - c * d) / D;
    double t = (a * e - b * d) / D;

    if (s < 0)
        s = 0;
    else if (s > 1)
        s = 1;

    if (t < 0)
        t = 0;
    else if (t > 1)
        t = 1;

    Point3D closestPointOnFirst = start + u * s;
    Point3D closestPointOnSecond = other.start + v * t;

    return Vector3D(closestPointOnFirst, closestPointOnSecond).length();
}

double Segment3D::distance(const Vector3D &point) const
{
    Vector3D u(start, end);
    Vector3D w(start, point);
    double D = u.dot(u);
    // if source vector is zero, then find distance beetween point and vector
    if (D < LIKE_ZERO) {
        return Vector3D(point, start).length();
    }
    double proj = w.dot(u) / u.dot(u);
    if (proj < 0)
        return Vector3D(point, start).length();
    if (proj > 1)
        return Vector3D(point, end).length();

    Point3D closestPoint = start + u * proj;
    return Vector3D(point, closestPoint).length();
}
