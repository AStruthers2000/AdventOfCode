#pragma once
#include "../../Problem.h"

class Year2023_Day14 : public Problem
{
public:
    Year2023_Day14() : Problem("Year 2023 Day 14: ")
    {
        filepath = R"(./2023/Day14/)";
    }

    string Problem1() override;
    string Problem2() override;
};
