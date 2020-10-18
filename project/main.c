/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Oct 2020 06:34:15 AM EDT
 ************************************************************************/

#include <stdio.h>
#include <src/test.h>

int add(int a, int b) {
    return a+b;
}

TEST(func, add) {
    EXPECT_EQ(add(3,4), 7);
    EXPECT_EQ(add(3,2), 5);
    EXPECT_EQ(add(5,6), 11);
    EXPECT_EQ(add(5,5), 10);
}

TEST(func, add2) {
    EXPECT_EQ(add(5,6), 10);
    EXPECT_GT(add(5,6), 9);
    EXPECT_GE(add(4,8), 20);
    EXPECT_EQ(add(5,6), 10);
}

TEST(func, add3) {
    EXPECT_EQ(add(5,6), 10);
    EXPECT_LT(add(1,2), 0);
    EXPECT_NE(add(1,2), -1);
    EXPECT_GT(add(3,2), 0);
}


int main(int argc, char** argv) {
    return RUN_ALL_TESTS();
}
