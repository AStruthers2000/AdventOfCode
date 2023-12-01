#pragma once
#include "../../Problem.h"

class Year2022_Day2 : public Problem
{
public:
    Year2022_Day2() : Problem("Year 2022 Day 2: Rock Paper Scissors")
    {
        filepath = R"(./2022/Day2/)";
    }
    
    string Problem1() override;
    string Problem2() override;

private:
    enum RPS_Move
    {
        Rock = 1,
        Paper = 2,
        Scissors = 3,
    };

    enum RPS_State
    {
        Undefined = -1,
        Lose = 0,
        Tie = 3,
        Win = 6,
    };

    struct RPS_Round
    {
        RPS_Move opponent_move;
        RPS_Move my_move;
        RPS_State round_result;
    };

    vector<RPS_Round> GetRounds() const;
    RPS_State GetState(RPS_Move my_move, RPS_Move opponent_move) const;
    RPS_Move GetMoveThatResultsInState(RPS_Move opponent_move, RPS_State state) const;
    RPS_State ConvertMoveToState(RPS_Move move) const;

    void UnitTestState() const;
};
