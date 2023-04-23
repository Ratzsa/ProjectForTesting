#include <gtest/gtest.h>
#include <cmath>
#include <limits>
#include <iostream>

extern "C"
{
    #include "calculator.h"
}

class CalculatorTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

TEST_F(CalculatorTest,Input128point77And34point5AndPlusShouldReturn163point27)
{
    float a = 128.77;
    float b = 34.5;
    char o = '+';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(163.27, result);
}

TEST_F(CalculatorTest,Input128point77AndNegative34point5AndPlusShouldReturn94point27)
{
    float a = 128.77;
    float b = -34.5;
    char o = '+';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(94.27, result);
}

TEST_F(CalculatorTest,Input128point77And34point5AndMinusShouldReturn94point27)
{
    float a = 128.77;
    float b = 34.5;
    char o = '-';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(94.27, result);
}

TEST_F(CalculatorTest,Input128point77AndNegative34point5AndMinusShouldReturn163point27)
{
    float a = 128.77;
    float b = -34.5;
    char o = '-';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(163.27, result);
}

TEST_F(CalculatorTest,Input128point77And34point5AndTimesShouldReturn4442point565)
{
    float a = 128.77;
    float b = 34.5;
    char o = '*';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(4442.565, result);
}

TEST_F(CalculatorTest,Input128point77AndNegative34point5AndTimesShouldReturnNegative4442point565)
{
    float a = 128.77;
    float b = -34.5;
    char o = '*';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(-4442.565, result);
}

TEST_F(CalculatorTest,InputZeroAnd34point5AndTimesShouldReturnZero)
{
    float a = 128.77;
    float b = 0;
    char o = '*';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(0, result);
}

TEST_F(CalculatorTest,Input128point77AndZeroAndTimesShouldReturnZero)
{
    float a = 128.77;
    float b = 0;
    char o = '*';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(0, result);
}

TEST_F(CalculatorTest,Input128point77And34point5AndDividedByShouldReturn3point7325rounded)
{
    float a = 128.77;
    float b = 34.5;
    char o = '/';
    float result;
    result = round(calculation(a, b, o) * 10000) / 10000;
    ASSERT_FLOAT_EQ(3.7325, result);
}

TEST_F(CalculatorTest,InputNegative128point77And34point5AndDividedByShouldReturnNegative3point7325rounded)
{
    float a = -128.77;
    float b = 34.5;
    char o = '/';
    float result;
    result = round(calculation(a, b, o) * 10000) / 10000;
    ASSERT_FLOAT_EQ(-3.7325, result);
}

TEST_F(CalculatorTest,Input128point77AndNegative34point5AndDividedByShouldReturnNegative3point7325rounded)
{
    float a = 128.77;
    float b = -34.5;
    char o = '/';
    float result;
    result = round(calculation(a, b, o) * 10000) / 10000;
    ASSERT_FLOAT_EQ(-3.7325, result);
}

TEST_F(CalculatorTest,InputZeroAnd34point5AndDividedByShouldReturnZero)
{
    float a = 0;
    float b = 34.5;
    char o = '/';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(0, result);
}

TEST_F(CalculatorTest,Input128point77AndZeroAndDividedByShouldReturnINFINITY)
{
    float a = 128.77;
    float b = 0;
    char o = '/';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(INFINITY, result);
}

TEST_F(CalculatorTest,Input128point77And34point5AndModulusShouldReturn26)
{
    float a = 128.77;
    float b = 34.5;
    char o = '%';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(26, result);
}

TEST_F(CalculatorTest,InputNegative128point77And34point5AndModulusShouldReturnNegative26)
{
    float a = -128.77;
    float b = 34.5;
    char o = '%';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(-26, result);
}

TEST_F(CalculatorTest,Input128point77AndNegative34point5AndModulusShouldReturn26)
{
    float a = 128.77;
    float b = -34.5;
    char o = '%';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(26, result);
}

TEST_F(CalculatorTest,InputZeroAnd34point5AndModulusShouldReturn26)
{
    float a = 0;
    float b = 34.5;
    char o = '%';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(0, result);
}

/* NOT ABLE TO MODULUS 0
TEST_F(CalculatorTest,Input128point77AndZeroAndModulusShouldReturn26)
{
    float a = 128.77;
    float b = 0;
    char o = '%';
    float result;
    result = calculation(a, b, o);
    ASSERT_FLOAT_EQ(result, 0);
}
*/