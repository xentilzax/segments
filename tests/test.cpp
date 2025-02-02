#include <gtest/gtest.h>
#include "segments/Segment3D.h"

TEST(Segment3DTests, TestDistance) {
    Point3D p1(0, 0, 0), p2(1, 0, 0), p3(0, 1, 0), p4(1, 1, 0);
    Segment3D s1(p1, p2);
    Segment3D s2(p3, p4);

    ASSERT_NEAR(s1.distance(s2), 1.0, 1e-6);
}

TEST(Segment3DTests, TestParallelSegments) {
    Point3D p1(0, 0, 0), p2(2, 0, 0), p3(0, 1, 0), p4(2, 1, 0);
    Segment3D s1(p1, p2);
    Segment3D s2(p3, p4);

    ASSERT_NEAR(s1.distance(s2), 1.0, 1e-6);
}
