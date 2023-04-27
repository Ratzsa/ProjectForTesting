#include <gtest/gtest.h>

enum resultList { LOSE, DRAW, WIN };
enum handList { EMPTY, ROCK, PAPER, SCISSORS};

extern "C"
{
    #include "gamecode.h"
    #include "checkinputs.h"
}

class RPSTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

class RPSMenuInputTest : public testing::Test
{
protected:
    void SetUp() override
    {
        // initialize
    }
};

TEST_F(RPSTest,WhenInputPlayerROCKAndComputerROCKShouldReturnDRAWForThePlayer)
{
    int res = gameMechanics(ROCK, ROCK);
    ASSERT_EQ(DRAW, res);
}

TEST_F(RPSTest,WhenInputPlayerROCKAndComputerPAPERShouldReturnLOSEForThePlayer)
{
    int res = gameMechanics(ROCK, PAPER);
    ASSERT_EQ(LOSE, res);
}

TEST_F(RPSTest,WhenInputPlayerROCKAndComputerSCISSORSShouldReturnWINForThePlayer)
{
    int res = gameMechanics(ROCK, SCISSORS);
    ASSERT_EQ(WIN, res);
}

TEST_F(RPSTest,WhenInputPlayerPAPERAndComputerROCKShouldReturnWINForThePlayer)
{
    int res = gameMechanics(PAPER, ROCK);
    ASSERT_EQ(WIN, res);
}

TEST_F(RPSTest,WhenInputPlayerPAPERAndComputerPAPERShouldReturnDRAWForThePlayer)
{
    int res = gameMechanics(PAPER, PAPER);
    ASSERT_EQ(DRAW, res);
}

TEST_F(RPSTest,WhenInputPlayerPAPERAndComputerSCISSORSShouldReturnLOSEForThePlayer)
{
    int res = gameMechanics(PAPER, SCISSORS);
    ASSERT_EQ(LOSE, res);
}

TEST_F(RPSTest,WhenInputPlayerSCISSORSAndComputerROCKShouldReturnLOSEForThePlayer)
{
    int res = gameMechanics(SCISSORS, ROCK);
    ASSERT_EQ(LOSE, res);
}

TEST_F(RPSTest,WhenInputPlayerSCISSORSAndComputerPAPERShouldReturnWINForThePlayer)
{
    int res = gameMechanics(SCISSORS, PAPER);
    ASSERT_EQ(WIN, res);
}

TEST_F(RPSTest,WhenInputPlayerSCISSORSAndComputerSCISSORSShouldReturnDRAWForThePlayer)
{
    int res = gameMechanics(SCISSORS, SCISSORS);
    ASSERT_EQ(DRAW, res);
}

TEST_F(RPSMenuInputTest,RPSMenuWhenInputOver3ShouldReturnFalse)
{
    char input[] = "4";
    bool correctInput = gameMenuCheck(input);
    ASSERT_FALSE(correctInput);
}

TEST_F(RPSMenuInputTest,RPSMenuWhenInputUnder1ShouldReturnFalse)
{
    char input[] = "0";
    bool correctInput = gameMenuCheck(input);
    ASSERT_FALSE(correctInput);
}

TEST_F(RPSMenuInputTest,RPSMenuWhenInputNegative1ShouldReturnFalse)
{
    char input[] = "-1";
    bool correctInput = gameMenuCheck(input);
    ASSERT_FALSE(correctInput);
}

TEST_F(RPSMenuInputTest,RPSMenuWhenInputOperatorShouldReturnFalse)
{
    char input[] = "+";
    bool correctInput = gameMenuCheck(input);
    ASSERT_FALSE(correctInput);
}

TEST_F(RPSMenuInputTest,RPSMenuWhenInputTwoDigitsShouldReturnFalse)
{
    char input[] = "10";
    bool correctInput = gameMenuCheck(input);
    ASSERT_FALSE(correctInput);
}

TEST_F(RPSMenuInputTest,RPSMenuWhenInputLetterShouldReturnFalse)
{
    char input[] = "a";
    bool correctInput = gameMenuCheck(input);
    ASSERT_FALSE(correctInput);
}

TEST_F(RPSMenuInputTest,RPSMenuWhenInputDigitFollowedByLetterShouldReturnFalse)
{
    char input[] = "1a";
    bool correctInput = gameMenuCheck(input);
    ASSERT_FALSE(correctInput);
}

TEST_F(RPSMenuInputTest,RPSMenuWhenInput2ShouldReturnTrue)
{
    char input[] = "2";
    bool correctInput = gameMenuCheck(input);
    ASSERT_TRUE(correctInput);
}