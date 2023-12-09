#pragma once
#include "../../Problem.h"

class Year2023_Day9 : public Problem
{
public:
    Year2023_Day9() : Problem("Year 2023 Day 9: Mirage Maintenance")
    {
        filepath = R"(./2023/Day9/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    int GetNextSequence(const vector<int>& sequence, bool prepend);

    vector<vector<int>> all_sequences;
    void LoadAllSequences();
};