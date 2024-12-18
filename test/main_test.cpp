#include <gtest/gtest.h>
#include <../inc/Operations.hpp>

TEST(ExampleTest, CheckAddfunction)
{

    int a = 5;
    int b = 10;
    addOperation(a, b);
}
TEST(ExampleTest, CheckAddfunction_1)
{

    int a = 50;
    int b = 10;
    addOperation(a, b);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}