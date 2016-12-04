
#include "../Point.h"
#include <gtest/gtest.h>

class PointTest : public :: testing::Test {

};

/**
 * Checks the basic overloading methods of the class
 */
TEST_F(PointTest, basicTest) {

    Point p1(1, 4);
    Point p2(5, 1);

    // Check == overloading
    ASSERT_TRUE(p1 == Point(1, 4));
    EXPECT_FALSE(p1 == p2);

    // Check print overloading
    testing::internal::CaptureStdout();
    std::cout << "(1, 4)";
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output == "(1, 4)");

}