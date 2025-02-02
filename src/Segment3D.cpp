#include "segments/Vector3D.h"
#include "segments/Segment3D.h"

double Segment3D::distance(const Segment3D &other) const
{
    Vector3D u(end - start);
    Vector3D v(other.end - other.start);
    Vector3D w(other.start - start);

    double a = u.dot(u); // Squared length of u
    double b = u.dot(v); // u · v
    double c = v.dot(v); // Squared length of v
    double d = u.dot(w); // u · w
    double e = v.dot(w); // v · w

    double D = a * c - b * b;

    if (D == 0)
    {
        // if segments make plane => parallel
        double d1 = distance(other.start);
        double d2 = distance(other.end);
        return d1 < d2 ? d1 : d2;
    }

    // Расчет параметров, которые нужны для нахождения ближайшей точки на обоих отрезках
    double s = b * e - c * d;
    double t = a * e - b * d;
    s /= D;
    t /= D;

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

    double proj = w.dot(u) / u.dot(u);
    if (proj < 0)
        return Vector3D(point, start).length();
    if (proj > 1)
        return Vector3D(point, end).length();

    Point3D closestPoint = start + u * proj;
    return Vector3D(point, closestPoint).length();
}
