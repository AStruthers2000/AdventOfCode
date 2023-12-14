#include "Year2023_Day12.h"

string Year2023_Day12::Problem1()
{
    ReadLines();
    int64_t possible_arrangements = 0;
    for(const auto& record : records)
    {
        const int64_t placement_count = FindSpringPlacement(record.broken_spring_record, record.contiguous_springs);//ExploreSpringPlacement(record);
        possible_arrangements += placement_count;
    }
    return to_string(possible_arrangements);
}

string Year2023_Day12::Problem2()
{
    ReadLines();
    int64_t possible_arrangements = 0;
    for(const auto& record : records)
    {
        string str_record; //= record.broken_spring_record;
        for(int i = 0; i < 4; i++)
        {
            str_record += record.broken_spring_record + '?';
        }
        str_record += record.broken_spring_record;
        
        vector<int> groups; //= record.contiguous_springs;
        for(int i = 0; i < 5; i++)
        {
            for(const auto& g : record.contiguous_springs)
            {
                groups.push_back(g);
            }
        }
        const int64_t placement_count = FindSpringPlacement(str_record, groups);//ExploreSpringPlacement(record);
        possible_arrangements += placement_count;
    }
    return to_string(possible_arrangements / 2);
}

void Year2023_Day12::ReadLines()
{
    for(const auto& line : lines)
    {
        vector<string> split_line = SplitLineByToken(line, ' ');

        vector<int> numbers;
        for(const auto& c : SplitLineByToken(split_line[1], ','))
        {
            numbers.push_back(stoi(c));
        }
        SpringPlacement s = {split_line[0], numbers};
        records.push_back(s);
    }
}

namespace std {
    template <>
    struct hash<vector<int>> {
        size_t operator()(const vector<int>& v) const {
            hash<int> hasher;
            size_t result = 0;
            for (int i : v) {
                result ^= hasher(i) + 0x9e3779b9 + (result << 6) + (result >> 2);
            }
            return result;
        }
    };
}

int64_t Year2023_Day12::FindSpringPlacement(const string& record, const vector<int>& groups) {
    // Check if the result is already memoized
    const auto memo_key = std::make_pair(record, groups);
    const auto memo_it = memo.find(memo_key);
    if (memo_it != memo.end())
        return memo_it->second;
    
    if (groups.empty())
    {
        const int64_t result = (record.find('#') == std::string::npos) ? 1 : 0;
        memo[memo_key] = result; // Memoize the result
        return result;
    }

    if (record.empty())
        return 0;

    const char next_character = record[0];
    const int next_group = groups[0];

    auto pound = [&]()
    {
        string this_group = record.substr(0, next_group);
        replace(this_group.begin(), this_group.end(), '?', '#');

        if (this_group != string(next_group, '#'))
            return static_cast<int64_t>(0);

        if (static_cast<int>(record.size()) == next_group)
            return static_cast<int64_t>(groups.size() == 1 ? 1 : 0);

        if (record[next_group] == '?' || record[next_group] == '.')
        {
            const int64_t result = FindSpringPlacement(record.substr(next_group + 1), {groups.begin() + 1, groups.end()});
            memo[memo_key] = result;
            return result;
        }

        return static_cast<int64_t>(0);
    };

    auto dot = [&]()
    {
        const int64_t result = FindSpringPlacement(record.substr(1), groups);
        memo[memo_key] = result;
        return result;
    };

    int64_t out = 0;

    if (next_character == '#')
        out = pound();
    else if (next_character == '.')
        out = dot();
    else if (next_character == '?')
        out = dot() + pound();
    else
        cerr << "Oops" << endl;
    
    memo[memo_key] = out;
    return out;
}
