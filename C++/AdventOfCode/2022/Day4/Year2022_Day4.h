﻿#pragma once
#include "../../Problem.h"

class Year2022_Day4 : public Problem
{
public:
    Year2022_Day4() : Problem("Year 2022 Day 4: Camp Cleanup")
    {
        filepath = R"(./2022/Day4/)";
    }
    
    string Problem1() override;
    string Problem2() override;

private:
    struct Schedule
    {
        int begin;
        int end;
    };

    Schedule ReadSchedule(const string& elf_schedule) const;
    bool CheckSchedulesForTotalOverlap(const Schedule& elf_1, const Schedule& elf_2) const;
    bool CheckSchedulesForAnyOverlap(const Schedule& elf_1, const Schedule& elf_2) const;
};
