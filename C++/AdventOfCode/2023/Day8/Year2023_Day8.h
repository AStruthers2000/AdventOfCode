#pragma once
#include "../../Problem.h"

class Year2023_Day8 : public Problem
{
public:
    Year2023_Day8() : Problem("Year 2023 Day 8: ")
    {
        filepath = R"(./2023/Day8/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    
};
