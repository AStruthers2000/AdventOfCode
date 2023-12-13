#include "Problem.h"

#include <numeric>

void Problem::ReadFromFile(const string& filename)
{
    ifstream file(filepath + filename);
    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    else
    {
        cerr << "Failed to read file at " << filepath + filename << endl;
        exit(-1);
    }
}

vector<string> Problem::SplitLineByToken(const string& line, const char token) const
{
    vector<string> split;
    string word;
    istringstream iss(line);
    while(getline(iss, word, token))
    {
        split.push_back(word);
    }
    return split;
}

uint64_t Problem::gcd(const uint64_t a, const uint64_t b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

uint64_t Problem::lcm(const uint64_t a, const uint64_t b)
{
    return a * b / gcd(a, b);
}

uint64_t Problem::lcm(const vector<int>& nums)
{
    if (nums.empty()) return 0;

    uint64_t result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
    {
        result = lcm(result, nums[i]);
    }
    return result;
}

bool Problem::IsVectorEntirelyN(const vector<int>& v, int n)
{
    return all_of(v.begin(),
                  v.end(),
                  [n](const int i) { return i==n; });
}

bool Problem::IsVectorEntirelyN(const vector<char>& v, char element)
{
    return all_of(v.begin(),
                  v.end(),
                  [element](const char c){return c == element; });
}

int Problem::CountOccurrencesOfCharInString(const vector<char>& str, const char& c)
{
    return static_cast<int>(count(str.begin(), str.end(), c));
}
