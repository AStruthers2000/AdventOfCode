#pragma once
#include <set>

#include "../../Problem.h"

class Year2023_Day11 : public Problem
{
public:
    Year2023_Day11() : Problem("Year 2023 Day 11: Cosmic Expansion")
    {
        filepath = R"(./2023/Day11/)";
    }
    
    string Problem1() override;
    string Problem2() override;

private:
    struct Galaxy
    {
        string galaxy_name;
        int galaxy_num = 0;
        int x;
        int y;
        map<Galaxy*, int64_t> distances;

        bool operator==(const Galaxy& other) const
        {
            return x == other.x && y == other.y;
        }
        
        bool operator!=(const Galaxy& other) const
        {
            return !(x == other.x && y == other.y);
        }

        bool operator<(const Galaxy& other) const
        {
            return galaxy_num < other.galaxy_num;
        }
    };
    vector<Galaxy> galaxies;
    set<pair<Galaxy*, Galaxy*>> galaxy_pairs;
    vector<vector<char>> universe;
    void ReadUniverse();
    void ExpandUniverse(int n_times);
    void FindGalaxies();
    void CalculateDistances();
    void FindPairs();
    int64_t CalculateSumsOfPairs();
    int64_t ManhattanDistance(const Galaxy* me, const Galaxy* other) const;
    void AddRow(int row, char c);
    void AddCol(int col, char c);
    vector<char> GetRow(int row) const;
    vector<char> GetCol(int col) const;

    vector<Galaxy*> GetAllGalaxiesToRight(int col);
    vector<Galaxy*> GetAllGalaxiesBelow(int row);

    void PrintUniverse() const;
};
