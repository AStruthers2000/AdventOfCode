#include "Year2022_Day4.h"

float Year2022_Day4::Problem1()
{
    int overlap_count = 0;
    for(const auto& line : lines)
    {
        Schedule elf_1 = ReadSchedule(SplitLineByToken(line, ',')[0]);
        Schedule elf_2 = ReadSchedule(SplitLineByToken(line, ',')[1]);
        overlap_count += CheckSchedulesForTotalOverlap(elf_1, elf_2);
    }
    
    return static_cast<float>(overlap_count);
}

float Year2022_Day4::Problem2()
{
    int overlap_count = 0;
    for(const auto& line : lines)
    {
        Schedule elf_1 = ReadSchedule(SplitLineByToken(line, ',')[0]);
        Schedule elf_2 = ReadSchedule(SplitLineByToken(line, ',')[1]);
        overlap_count += CheckSchedulesForAnyOverlap(elf_1, elf_2);
    }

    return static_cast<float>(overlap_count);
}

Year2022_Day4::Schedule Year2022_Day4::ReadSchedule(const string& elf_schedule) const
{
    const Schedule s = {
        stoi(SplitLineByToken(elf_schedule, '-')[0]),
        stoi(SplitLineByToken(elf_schedule, '-')[1])
    };
    return s;
}

bool Year2022_Day4::CheckSchedulesForTotalOverlap(const Schedule& elf_1, const Schedule& elf_2) const
{
    return (elf_1.begin <= elf_2.begin && elf_1.end >= elf_2.end) ||
        (elf_2.begin <= elf_1.begin && elf_2.end >= elf_1.end);
}

bool Year2022_Day4::CheckSchedulesForAnyOverlap(const Schedule& elf_1, const Schedule& elf_2) const
{
    if(CheckSchedulesForTotalOverlap(elf_1, elf_2)) return true;

    return (elf_1.end >= elf_2.begin && elf_1.begin <= elf_2.begin) ||
        (elf_2.end >= elf_1.begin && elf_2.begin <= elf_1.begin);
}
