#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_set>
#include <map>

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
    string filepath;

    vector<string> SplitLineByToken(const string& line, char token) const;
    uint64_t gcd(uint64_t a, uint64_t b);
    uint64_t lcm(uint64_t a, uint64_t b);
    uint64_t lcm(const vector<int>& nums);
    bool IsVectorEntirelyN(const vector<int>& v, int n);
    bool IsVectorEntirelyN(const vector<char>& v, char element);
    int CountOccurrencesOfCharInString(const vector<char>& str, const char& c);
    
private:
    string _problem_name;
};