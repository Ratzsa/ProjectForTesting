#include <gtest/gtest.h>

extern "C"
{
    #include "shapes.h"
}

class RectangleCircumferenceTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

class RectangleAreaTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

class CircleCircumferenceTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

class CircleAreaTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

class TriangleCircumferenceTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

class TriangleAreaTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

TEST_F(RectangleCircumferenceTest,WhenInput5point9And7point30ShouldReturnCircumference26point40)
{
    float a = 5.9;
    float b = 7.30;
    float result;
    result = rectangleCircum(a, b);
    ASSERT_FLOAT_EQ(result, 26.4);
}

TEST_F(RectangleAreaTest,WhenInput8point2And13point47ShouldReturnArea110point45)
{
    float a = 8.2;
    float b = 13.47;
    float result = rectangleArea(a, b);
    ASSERT_FLOAT_EQ(result, 110.454);
}

TEST_F(CircleCircumferenceTest,WhenInputRadius7ShouldReturnCircumference43point9823)
{
    float r = 7;
    float result = circleCircum(r);
    ASSERT_FLOAT_EQ(result, 43.9823);
}

TEST_F(CircleAreaTest,WhenInputRadius13point7ShouldReturnArea589point64551)
{
    float r = 13.7;
    float result = circleArea(r);
    ASSERT_FLOAT_EQ(result, 589.64551);
}

TEST_F(TriangleCircumferenceTest,WhenInput5point32And8point76And10point2489ShouldReturnCircumference24point3289)
{
    float a = 5.32;
    float b = 8.76;
    float c = 10.2489;
    float result = triangleCircum(a, b, c);
    ASSERT_FLOAT_EQ(result, 24.3289);
}

TEST_F(TriangleAreaTest,Text)
{
    float a = 9.13;
    float b = 11.78;
    float result = triangleArea(a, b);
    ASSERT_FLOAT_EQ(result, 53.7757);
}