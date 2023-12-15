#pragma once
#include "../../Problem.h"

class Year2023_Day13 : public Problem
{
public:
    Year2023_Day13() : Problem("Year 2023 Day 13: Point of Incidence")
    {
        filepath = R"(./2023/Day13/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    enum ReflectionType
    {
        Default = 0,
        Vertical = 1,
        Horizontal = 100
    };
    struct Pattern
    {
        vector<string> pattern;
        ReflectionType reflection;
        int reflection_point;
    };
    vector<Pattern> patterns;
    void LoadPatterns();

    void FindReflection(Pattern* p);
    void FindSmudge(Pattern* p);
    
    int ConvertLineToInt(const std::string& gridLine);
    vector<string> TransposePattern(const vector<string>& grid);
};

