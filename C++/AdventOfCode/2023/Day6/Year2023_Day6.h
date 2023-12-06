#pragma once
#include <map>

#include "../../Problem.h"

class Year2023_Day6 : public Problem
{
public:
    Year2023_Day6() : Problem("Year 2023 Day 6: Wait For It")
    {
        filepath = R"(./2023/Day6/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    struct Race
    {
        int64_t time = 0;
        int64_t distance = 0;
        int64_t midpoint = 0;
        int64_t num_viable_holds = 0;

        void FindHoldTimes()
        {
            int64_t viable_hold_count = 0;
            int64_t hold = midpoint;
            while(true)
            {
                if(GetDistanceFromHoldTime(hold) > distance)
                {
                    viable_hold_count++;
                    hold--;
                }
                else
                {
                    break;
                }
            }
            if(time % 2 == 0) viable_hold_count += viable_hold_count - 1;
            else viable_hold_count *= 2;

            num_viable_holds = viable_hold_count;
        }

        int64_t GetDistanceFromHoldTime(const int64_t hold) const
        {
            return (time - hold) * hold;
        }
    };
    
    vector<Race> races;
    Race big_race;
    void ParseSpacedInput();
    void ParseBigRace();
};
