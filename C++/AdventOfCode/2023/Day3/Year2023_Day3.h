#pragma once
#include "../../Problem.h"

class Year2023_Day3 : public Problem
{
public:
    Year2023_Day3() : Problem("Year 2023 Day 3: Gear Ratios")
    {
        filepath = R"(./2023/Day3/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    vector<vector<char>> ParseEngine();
    vector<vector<char>> engine_schematic;
    bool LocalSearch(int col, int row);
    int GetNumberAroundSymbol(const int col, const int row) const;
    bool IsValidPosition(const int col, const int row) const
    {
        return !(col < 0 || row < 0 || col > col_max || row > row_max);
    }
    int row_max = 0;
    int col_max = 0;
};

//vector<vector<char>> Year2023_Day3::ParseEngine();
