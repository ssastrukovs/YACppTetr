#include "main.h"
#include <iostream>
#include <gtest/gtest.h>

namespace project {

TEST(FooTest, Eq0) {
    EXPECT_EQ(0, 0);
    std::cout << "Test good 2\n";
}
    
}

int main (int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}