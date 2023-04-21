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

class ParallelogramCircumferenceTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

class ParallelogramAreaTest : public testing::Test
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

TEST_F(TriangleAreaTest,WhenInput9point13And11point78ShouldReturnArea53point7757)
{
    float a = 9.13;
    float b = 11.78;
    float result = triangleArea(a, b);
    ASSERT_FLOAT_EQ(result, 53.7757);
}

TEST_F(ParallelogramCircumferenceTest,Text)
{
    float a = 7;
    float b = 4.31;
    float result = parallelogramCircum(a, b);
    ASSERT_FLOAT_EQ(result, 22.62);
}

TEST_F(ParallelogramAreaTest,Text)
{
    float a = 8.7;
    float h = 9.2;
    float result = parallelogramArea(a, h);
    ASSERT_FLOAT_EQ(result, 80.04);
}