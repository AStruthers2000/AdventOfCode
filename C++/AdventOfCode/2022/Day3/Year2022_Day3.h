#pragma once
#include "../../Problem.h"

class Year2022_Day3 : public Problem
{
public:
    Year2022_Day3() : Problem("2022 Day 3 - Rucksack Reorganization")
    {
        filepath = R"(./2022/Day3/)";
    }
    
    string Problem1() override;
    string Problem2() override;

private:
    vector<string> SplitRucksackInTwo(const string& rucksack) const;
    char FindMatchingRucksackItem(vector<string> rucksack) const;
    char FindBadgeFromRucksacks(vector<string> rucksacks) const;
    int GetItemOrder(char item) const;
};
