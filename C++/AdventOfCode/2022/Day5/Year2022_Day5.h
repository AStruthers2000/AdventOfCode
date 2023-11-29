#pragma once
#include "../../Problem.h"

class Year2022_Day5 : public Problem
{
public:
    Year2022_Day5() : Problem("2022 Day 5")
    {
        filepath = R"(./2022/Day5/)";
    }

    float Problem1() override;
    float Problem2() override;
};
