#pragma once

#include "../../Problem.h"

class Year2022_Day1 : public Problem
{
public:
    Year2022_Day1() : Problem("2022 Day 1 - Calorie Counting")
    {
        filepath = R"(./2022/Day1/)";
    }
    
    string Problem1() override;
    string Problem2() override;

private:
    vector<int> GetCalorieSums() const;
};
