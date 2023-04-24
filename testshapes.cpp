#include <gtest/gtest.h>

extern "C"
{
    #include "shapes.h"
    #include "checkinputs.h"
}

class ShapesCircumferenceTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

class ShapesAreaTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

class ShapesInputTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};


TEST_F(ShapesCircumferenceTest,RectangleWhenInput5point9And7point30ShouldReturnCircumference26point40)
{
    float a = 5.9;
    float b = 7.30;
    float result;
    result = rectangleCircum(a, b);
    ASSERT_FLOAT_EQ(26.4, result);
}

TEST_F(ShapesAreaTest,RectangleWhenInput8point2And13point47ShouldReturnArea110point45)
{
    float a = 8.2;
    float b = 13.47;
    float result = rectangleArea(a, b);
    ASSERT_FLOAT_EQ(110.454, result);
}

TEST_F(ShapesCircumferenceTest,CircleWhenInputRadius7ShouldReturnCircumference43point9823)
{
    float r = 7;
    float result = circleCircum(r);
    ASSERT_FLOAT_EQ(43.9823, result);
}

TEST_F(ShapesAreaTest,CircleWhenInputRadius13point7ShouldReturnArea589point64551)
{
    float r = 13.7;
    float result = circleArea(r);
    ASSERT_FLOAT_EQ(589.64551, result);
}

TEST_F(ShapesCircumferenceTest,TriangleWhenInput5point32And8point76And10point2489ShouldReturnCircumference24point3289)
{
    float a = 5.32;
    float b = 8.76;
    float c = 10.2489;
    float result = triangleCircum(a, b, c);
    ASSERT_FLOAT_EQ(24.3289, result);
}

TEST_F(ShapesAreaTest,TriangleWhenInput9point13And11point78ShouldReturnArea53point7757)
{
    float a = 9.13;
    float b = 11.78;
    float result = triangleArea(a, b);
    ASSERT_FLOAT_EQ(53.7757, result);
}

TEST_F(ShapesCircumferenceTest,ParallelogramWhenInput7And4point31ShouldReturnCircumference22point62)
{
    float a = 7;
    float b = 4.31;
    float result = parallelogramCircum(a, b);
    ASSERT_FLOAT_EQ(22.62, result);
}

TEST_F(ShapesAreaTest,ParallelogramWhenInput8point7And9point2ShouldReturnArea80point04)
{
    float a = 8.7;
    float h = 9.2;
    float result = parallelogramArea(a, h);
    ASSERT_FLOAT_EQ(80.04, result);
}

TEST_F(ShapesInputTest,ShapesWhenInputNormalNumberShouldReturnTrue)
{
    char input[] = "1234";
    bool returnValue = checkInputs(input);
    ASSERT_TRUE(returnValue);
}

TEST_F(ShapesInputTest,ShapesWhenInputLetterWithinNumbersShouldReturnFalse)
{
    char input[] = "12a34";
    bool returnValue = checkInputs(input);
    ASSERT_FALSE(returnValue);
}

TEST_F(ShapesInputTest,ShapesWhenInputOperatorWithinNumbersShouldReturnFalse)
{
    char input[] = "12-34";
    bool returnValue = checkInputs(input);
    ASSERT_FALSE(returnValue);
}