#include "Year2023_Day13.h"

string Year2023_Day13::Problem1()
{
    LoadPatterns();
    int sum = 0;
    int count = 1;
    for(auto& p : patterns)
    {
        p.reflection = Horizontal;
        
        auto transpose_p = p;
        transpose_p.pattern = TransposePattern(p.pattern);
        transpose_p.reflection = Vertical;
        
        FindReflection(&p);
        FindReflection(&transpose_p);

        if(p.reflection_point != -1)
        {
            //cout << "Grid " << count << " has horizontal reflection at index " << p.reflection_point << endl;
            sum += p.reflection_point * p.reflection;
        }

        if(transpose_p.reflection_point != -1)
        {
            //cout << "Grid " << count << " has vertical reflection at index " << transpose_p.reflection_point << endl;
            sum += transpose_p.reflection_point * transpose_p.reflection;
        }
        count++;
        //cout << (p.reflection == Horizontal ? "Horizontal" : "Vertical") << " reflection at index " << p.reflection_point << endl;
    }
    return to_string(sum);
}

string Year2023_Day13::Problem2()
{
    LoadPatterns();
    int sum = 0;
    int count = 1;
    for(auto& p : patterns)
    {
        p.reflection = Horizontal;
        
        auto transpose_p = p;
        transpose_p.pattern = TransposePattern(p.pattern);
        transpose_p.reflection = Vertical;
        
        FindSmudge(&p);
        FindSmudge(&transpose_p);

        if(p.reflection_point != -1)
        {
            //cout << "Grid " << count << " has horizontal reflection at index " << p.reflection_point << endl;
            sum += p.reflection_point * p.reflection;
        }

        if(transpose_p.reflection_point != -1)
        {
            //cout << "Grid " << count << " has vertical reflection at index " << transpose_p.reflection_point << endl;
            sum += transpose_p.reflection_point * transpose_p.reflection;
        }
        count++;
        //cout << (p.reflection == Horizontal ? "Horizontal" : "Vertical") << " reflection at index " << p.reflection_point << endl;
    }
    return to_string(sum);
}

void Year2023_Day13::LoadPatterns()
{
    patterns.clear();
    
    vector<string> pattern;
    for(const auto& line : lines)
    {
        if(line.empty())
        {
            const Pattern p = {pattern, Default, -1};
            patterns.push_back(p);
            pattern.clear();
            continue;
        }
        pattern.push_back(line);
    }
    const Pattern p = {pattern, Default, -1};
    patterns.push_back(p);
    pattern.clear();
}

void Year2023_Day13::FindReflection(Pattern* p)
{
    const auto grid = p->pattern;
    vector<int> encodedGrid;
    encodedGrid.reserve(grid.size());
    for (const auto& line : grid)
    {
        encodedGrid.push_back(ConvertLineToInt(line));
    }

    for (size_t i = 1; i < grid.size(); ++i)
    {
        vector<int> left(encodedGrid.begin(), encodedGrid.begin() + static_cast<int>(i));
        reverse(left.begin(), left.end());
        vector<int> right(encodedGrid.begin() + static_cast<int>(i), encodedGrid.end());

        const size_t length = min(left.size(), right.size());
        left.resize(length);
        right.resize(length);

        if (left == right)
        {
            p->reflection_point = static_cast<int>(i);
        }
    }
}

void Year2023_Day13::FindSmudge(Pattern* p)
{
    const auto grid = p->pattern;
    vector<int> encodedGrid;
    encodedGrid.reserve(grid.size());
    for (const auto& line : grid)
    {
        encodedGrid.push_back(ConvertLineToInt(line));
    }

    for (size_t i = 1; i < grid.size(); ++i)
    {
        vector<int> left(encodedGrid.begin(), encodedGrid.begin() + static_cast<int>(i));
        reverse(left.begin(), left.end());
        vector<int> right(encodedGrid.begin() + static_cast<int>(i), encodedGrid.end());

        const size_t length = min(left.size(), right.size());
        left.resize(length);
        right.resize(length);

        std::vector<int> diff;
        for (size_t j = 0; j < length; ++j)
        {
            if (left[j] != right[j]) {
                diff.push_back(left[j] ^ right[j]);
            }
        }

        if (diff.size() == 1 && IsNumberPowerOfTwo(diff[0]))
        {
            p->reflection_point = static_cast<int>(i);
        }
    }
}

int Year2023_Day13::ConvertLineToInt(const string& gridLine)
{
    string line = gridLine;
    replace(line.begin(), line.end(), '.', '0');
    replace(line.begin(), line.end(), '#', '1');

    return std::stoi(line, nullptr, 2);
}

vector<string> Year2023_Day13::TransposePattern(const vector<string>& grid)
{
    vector<string> result;
    result.resize(grid[0].size());

    for (size_t i = 0; i < grid[0].size(); ++i)
    {
        for (const auto& row : grid)
        {
            result[i].push_back(row[i]);
        }
    }

    return result;
}

