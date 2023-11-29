#pragma once
#include "../../Problem.h"

class Year2022_Day4 : public Problem
{
public:
    Year2022_Day4() : Problem("2022 Day 4")
    {
        filepath = R"(./2022/Day4/)";
    }
    
    float Problem1() override;
    float Problem2() override;

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
