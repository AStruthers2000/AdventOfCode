#pragma once
#include "../../Problem.h"

class Year2022_Day6 : public Problem
{
public:
    Year2022_Day6() : Problem("2022 Day 6 - Tuning Trouble")
    {
        filepath = R"(./2022/Day6/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    int FindFirstUniqueCharSequenceOfLength(int length) const;
};
