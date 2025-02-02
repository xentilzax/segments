#include "segments/Segment3D.h"
#include <iostream>

int main() {
    Point3D p1(0, 0, 0), p2(1, 0, 0), p3(0, 1, 0), p4(1, 1, 0);
    Segment3D s1(p1, p2);
    Segment3D s2(p3, p4);

    std::cout << "Distance between segments: " << s1.distance(s2) << std::endl;
    return 0;
}
