#pragma once
#include <map>
#include <queue>
#include <stack>

#include "../../Problem.h"

class Year2022_Day5 : public Problem
{
public:
    Year2022_Day5() : Problem("2022 Day 5")
    {
        filepath = R"(./2022/Day5/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    map<int, deque<string>> boxes;
    struct MoveInstruction
    {
        int from;
        int to;
        int number_to_move;
    };

    vector<MoveInstruction> instructions;

    void ParseInput();
    vector<string> SplitStringIntoBoxes(string line);
    MoveInstruction ParseInstruction(string line);
};