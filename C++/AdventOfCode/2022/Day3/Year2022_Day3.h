#pragma once
#include "../../Problem.h"

class Year2022_Day3 : public Problem
{
public:
    Year2022_Day3() : Problem("2022 Day 3")
    {
        filepath = R"(./2022/Day3/)";
    }
    
    float Problem1() override;
    float Problem2() override;

private:
    vector<string> SplitRucksackInTwo(const string& rucksack) const;
    char FindMatchingRucksackItem(vector<string> rucksack) const;
    int GetItemOrder(char item) const;
};
