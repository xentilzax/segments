#include <gtest/gtest.h>
#include <cmath>
#include "segments/Segment3D.h"

// zero size segment
TEST(Segment3DTests, TestZeroSize) {
    //two zero size segment
    Point3D p1(0, 0, 0), p2(-1, 1, 0), p3(1, 1, 0);
    Segment3D s1(p1, p1);
    ASSERT_NEAR(s1.distance(s1), 0, 1e-6);

    // zero size segment(point) and segment making plane
    Segment3D s3(p2, p3);
    ASSERT_NEAR(s1.distance(s3), 1, 1e-6);
    ASSERT_NEAR(s3.distance(s1), 1, 1e-6);

    // zero size segment and segment on one line
    Point3D p4(1, 1, 1), p5(2, 2, 2);
    Segment3D s4(p4, p5);
    ASSERT_NEAR(s4.distance(s1), std::sqrt(3), 1e-6);
    ASSERT_NEAR(s1.distance(s4), std::sqrt(3), 1e-6);

    // zero size segment inside segment
    Point3D p6(0, 1, 0);
    Segment3D s5(p6, p6);
    ASSERT_NEAR(s1.distance(s5), 1, 1e-6);
    ASSERT_NEAR(s5.distance(s1), 1, 1e-6);
}

// parallel = sements in one plane
TEST(Segment3DTests, TestParallelSegments) {
    Point3D p1(-1, 1, 10), p2(1, 1, 10), p3(0, -1, 11), p4(2, -1, 11);
    Segment3D s1(p1, p2);
    Segment3D s2(p3, p4);
    ASSERT_NEAR(s1.distance(s2), std::sqrt(5), 1e-6);
    ASSERT_NEAR(s2.distance(s1), std::sqrt(5), 1e-6);

    // one segment biggest other segment
    Point3D p5(-3, 1, 10), p6(3, 1, 10);
    Segment3D s4(p5, p6);
    ASSERT_NEAR(s4.distance(s2), std::sqrt(5), 1e-6);
    ASSERT_NEAR(s2.distance(s4), std::sqrt(5), 1e-6);

    //segments by one line
    Point3D p7(1, 1, 1), p8(2, 2, 2), p9(3, 3, 3), p0(4, 4, 4);
    Segment3D s5(p7, p8);
    Segment3D s6(p9, p0);
    ASSERT_NEAR(s5.distance(s6), std::sqrt(3), 1e-6);
    ASSERT_NEAR(s6.distance(s5), std::sqrt(3), 1e-6);

    // segments by one line and cross
    Segment3D s7(p7, p9);
    Segment3D s8(p0, p8);
    ASSERT_NEAR(s7.distance(s8), 0, 1e-6);
    ASSERT_NEAR(s8.distance(s7), 0, 1e-6);

    // crossed segments in one plane
    Point3D a1(1, 1, 1), a2(2, 2, 2), b1(2, 1, 1.5), b2(1, 2, 1.5);
    Segment3D a(a1, a2);
    Segment3D b(b1, b2);
    ASSERT_NEAR(a.distance(b), 0, 1e-6);
    ASSERT_NEAR(b.distance(a), 0, 1e-6);
}

// segments 
TEST(Segment3DTests, TestDistance) {
    // cross point inside segments
    Point3D p1(0, -1, 1), p2(0, 1, 1), p3(-1, 0, 2), p4(1, 0, 2);
    Segment3D a(p1, p2);
    Segment3D b(p3, p4);

    ASSERT_NEAR(b.distance(a), 1.0, 1e-6);
    ASSERT_NEAR(a.distance(b), 1.0, 1e-6);

    // cross point outside segments
    Point3D c1(2, -1, 1), c2(2, 1, 1);
    Segment3D c(c1, c2);
    ASSERT_NEAR(b.distance(c), std::sqrt(2), 1e-6);
    ASSERT_NEAR(c.distance(b), std::sqrt(2), 1e-6);
}
