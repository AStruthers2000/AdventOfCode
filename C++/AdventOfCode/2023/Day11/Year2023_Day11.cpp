#include "Year2023_Day11.h"

#include <assert.h>
#include <chrono>

string Year2023_Day11::Problem1()
{
    ReadUniverse();
    FindGalaxies();
    ExpandUniverse(1);
    FindPairs();
    
    const int64_t answer = CalculateSumsOfPairs();
    return to_string(answer);
}

string Year2023_Day11::Problem2()
{
    ReadUniverse();
    FindGalaxies();
    ExpandUniverse(999999);
    FindPairs();
    
    const int64_t answer = CalculateSumsOfPairs();
    return to_string(answer);
}


void Year2023_Day11::ReadUniverse()
{
    if(!universe.empty()) universe.clear();
    
    for(const auto& line : lines)
    {
        vector<char> row;
        for(const auto& c : line)
        {
            row.push_back(c);
        }
        universe.push_back(row);
    }
}

void Year2023_Day11::ExpandUniverse(const int n_times)
{
    if(n_times < 1) cerr << "C'mon, be serious. We can't expand the universe less than 1 time." << endl;
    
    int expansion_offset = 0;
    for(size_t i = 0; i < universe.size(); i++)
    {
        if(IsVectorEntirelyN(GetRow(static_cast<int>(i)), '.'))
        {
            vector<Galaxy*> bottom = GetAllGalaxiesBelow(static_cast<int>(i) + expansion_offset);
            for(const auto& g : bottom)
            {
                g->x += n_times;
            }
            expansion_offset += n_times;
        }
    }

    expansion_offset = 0;
    for(size_t i = 0; i < universe[0].size(); i++)
    {
        if(IsVectorEntirelyN(GetCol(static_cast<int>(i)), '.'))
        {
            vector<Galaxy*> right = GetAllGalaxiesToRight(static_cast<int>(i) + expansion_offset);
            for(const auto& g : right)
            {
                g->y += n_times;
            }
            expansion_offset += n_times;
        }
    }
}

void Year2023_Day11::FindGalaxies()
{
    galaxies.clear();
    galaxy_pairs.clear();
    
    for(size_t row = 0; row < universe.size(); row++)
    {
        for(size_t col = 0; col < universe[0].size(); col++)
        {
            const char c = universe[row][col];
            if(c == '#')
            {
                const int num = static_cast<int>(galaxies.size() + 1);
                const string name = "Galaxy " + to_string(num);
                Galaxy g = {name, num, static_cast<int>(row), static_cast<int>(col), {}};
                galaxies.push_back(g);
            }
        }
    }
}

void Year2023_Day11::CalculateDistances()
{
    for(auto& me : galaxies)
    {
        for(auto& other : galaxies)
        {
            if(me != other)
            {
                const int64_t d = ManhattanDistance(&me, &other);
                me.distances[&other] = d;
                other.distances[&me] = d;
            }
        }
    }
}

void Year2023_Day11::FindPairs()
{
    galaxy_pairs.clear();
    vector<Galaxy> nodes = galaxies;
    sort(nodes.begin(), nodes.end());
    for(size_t i = 0; i < nodes.size(); i++)
    {
        for(size_t j = i + 1; j < nodes.size(); j++)
        {
            pair<Galaxy*, Galaxy*> pair;
            Galaxy* g1 = &galaxies[i];
            Galaxy* g2 = &galaxies[j];
            const int64_t d = ManhattanDistance(g1, g2);
            g1->distances[g2] = d;
            g2->distances[g1] = d;
                
            if(g1 < g2) pair = {g1, g2};
            else pair = {g2, g1};
            galaxy_pairs.emplace(pair);
        }
    }
}

int64_t Year2023_Day11::CalculateSumsOfPairs()
{
    int64_t sum_of_distances = 0;
    for(const auto& s : galaxy_pairs)
    {
        sum_of_distances += ManhattanDistance(s.first, s.second);
    }

    return sum_of_distances;
}

int64_t Year2023_Day11::ManhattanDistance(const Galaxy* me, const Galaxy* other) const
{
    return abs(me->x - other->x) + abs(me->y - other->y);
}

void Year2023_Day11::AddRow(const int row, const char c)
{
    const vector<char> new_row(universe[0].size(), c);
    universe.insert(universe.begin() + row, new_row);
}

void Year2023_Day11::AddCol(const int col, const char c)
{
    for(auto& row : universe)
    {
        row.insert(row.begin() + col, c);
    }
}

vector<char> Year2023_Day11::GetRow(const int row) const
{
    return universe[row];
}

vector<char> Year2023_Day11::GetCol(const int col) const
{
    vector<char> new_col;
    new_col.reserve(universe.size());
    for(const auto& row : universe)
    {
        new_col.push_back(row[col]);
    }
    return new_col;
}

vector<Year2023_Day11::Galaxy*> Year2023_Day11::GetAllGalaxiesToRight(const int col)
{
    vector<Galaxy*> right_galaxies;
    for(auto& galaxy : galaxies)
    {
        if(galaxy.y > col)
        {
            right_galaxies.push_back(&galaxy);
        }
    }
    return right_galaxies;
}

vector<Year2023_Day11::Galaxy*> Year2023_Day11::GetAllGalaxiesBelow(const int row)
{
    vector<Galaxy*> bottom_galaxies;
    for(auto& galaxy : galaxies)
    {
        if(galaxy.x > row)
        {
            bottom_galaxies.push_back(&galaxy);
        }
    }
    return bottom_galaxies;
}

void Year2023_Day11::PrintUniverse() const
{
    for(const auto& row : universe)
    {
        for(const auto& c : row)
        {
            cout << c;
        }
        cout << endl;
    }
}
