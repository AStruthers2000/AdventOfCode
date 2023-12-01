#pragma once
#include "../../Problem.h"

class Year2022_Day8 : public Problem
{
public:
    Year2022_Day8() : Problem("Year 2022 Day 8: Treetop Tree House")
    {
        filepath = R"(./2022/Day8/)";
    }

    string Problem1() override;
    string Problem2() override;
};
