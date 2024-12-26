#include <gtest/gtest.h>
#include "lib/lib.hpp"

TEST (trueTest, first) {
    Segment3D first = {{1,0,0}, {1,1,0}};
    Segment3D second = {{0,1,0}, {1,-1,0}};
    Vector3D result;
    bool resBoll = Intersect::Intersect(first, second, result);

    EXPECT_EQ(resBoll, 1);
    EXPECT_EQ((result == Vector3D(1, -1, 0)), 1);
}

TEST (trueTest, second) {
    Segment3D first = {{1,1,1}, {3,3,3}};
    Segment3D second = {{0,0,0}, {1,1,-1}};
    Vector3D result;
    bool resBoll = Intersect::Intersect(first, second, result);

    EXPECT_EQ(resBoll, 1);
    EXPECT_EQ((result == Vector3D(0, 0, 0)), 1);
}

TEST (trueTest, third) {
    Segment3D first = {{3, -3, 2}, {2,-2,4}};
    Segment3D second = {{-1, 4, -26}, {2, 0, -20}};
    Vector3D result;
    bool resBoll = Intersect::Intersect(first, second, result);

    EXPECT_EQ(resBoll, 1);
    EXPECT_EQ((result == Vector3D(8, -8, -8)), 1);
}

TEST (falseTest, first) {
    Segment3D first = {{1,0,0}, {1,1,0}};
    Segment3D second = {{0,0,1}, {1,0,1}};
    Vector3D result;
    bool resBoll = Intersect::Intersect(first, second, result);

    EXPECT_EQ(resBoll, 0);
}

TEST (falseTest, second) {
    Segment3D first = {{2,2,2}, {1,0,1}};
    Segment3D second = {{1, 2, 1}, {0,1,1}};
    Vector3D result;
    bool resBoll = Intersect::Intersect(first, second, result);

    EXPECT_EQ(resBoll, 0);
}

TEST (falseTest, third) {
    Segment3D first = {{4,4,4}, {1,0,0}};
    Segment3D second = {{4,0,4}, {0,1,0}};
    Vector3D result;
    bool resBoll = Intersect::Intersect(first, second, result);
    
    EXPECT_EQ(resBoll, 0);
}

// std::cout<<"this is answer = "<<result.getx()<<result.gety()<<result.getz()<<" "<<resBoll<<std::endl;
    