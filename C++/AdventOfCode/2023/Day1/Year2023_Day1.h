#pragma once
#include "../../Problem.h"

class Year2023_Day1 : public Problem
{
public:
    Year2023_Day1() : Problem("Year 2023 Day 1: Trebuchet?!")
    {
        filepath = R"(./2023/Day1/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    vector<int> FindNumber(const string& line);
    string ParseWordsToInts(const string& line);
};
