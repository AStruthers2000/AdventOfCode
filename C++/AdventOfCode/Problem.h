#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_set>

using namespace std;

//#define filepath R"(.\Days\)"

class Problem
{
public:
    Problem(const string& name)
    {
        _problem_name = name;
    }

    Problem() = default;
    virtual ~Problem() = default;

    void ReadFromFile(const string& filename);
    virtual string Problem1() = 0;
    virtual string Problem2() = 0;
    virtual string GetProblemName() { return _problem_name; }

protected:
    vector<string> lines;

    vector<string> SplitLineByToken(const string& line, char token) const;
    string filepath;
    
private:
    string _problem_name;
};