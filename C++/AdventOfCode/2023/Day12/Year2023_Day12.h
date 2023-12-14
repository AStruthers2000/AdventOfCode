#pragma once
#include <unordered_map>

#include "../../Problem.h"

class Year2023_Day12 : public Problem
{
public:
    Year2023_Day12() : Problem("Year 2023 Day 12: Hot Springs")
    {
        filepath = R"(./2023/Day12/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    struct SpringPlacement
    {
        string broken_spring_record;
        vector<int> contiguous_springs;
    };

    

    map<pair<string, vector<int>>, int64_t> memo;
    vector<SpringPlacement> records;
    
    void ReadLines();
    int64_t FindSpringPlacement(const string& record, const vector<int>& groups);
};
