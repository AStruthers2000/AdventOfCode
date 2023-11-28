#include "Year2022_Day3.h"



float Year2022_Day3::Problem1()
{
    int duplicate_item_sum = 0;
    for(const auto& line : lines)
    {
        const char same_item = FindMatchingRucksackItem(SplitRucksackInTwo(line));
        duplicate_item_sum += GetItemOrder(same_item);
    }
    return static_cast<float>(duplicate_item_sum);
}

float Year2022_Day3::Problem2()
{
    return 0;
}

vector<string> Year2022_Day3::SplitRucksackInTwo(const string& rucksack) const
{
    vector<string> rucksack_split;
    rucksack_split.reserve(2);

    const int half_point = static_cast<int>(rucksack.size()) / 2;

    const string upper_half = rucksack.substr(0, half_point);
    const string lower_half = rucksack.substr(half_point);

    rucksack_split.push_back(upper_half);
    rucksack_split.push_back(lower_half);

    return rucksack_split;
}

char Year2022_Day3::FindMatchingRucksackItem(vector<string> rucksack) const
{
    const unordered_multiset<char> upper(rucksack[0].begin(), rucksack[0].end());
    const unordered_multiset<char> lower(rucksack[1].begin(), rucksack[1].end());

    for(char c : upper)
    {
        if(lower.count(c)) return c;
    }

    cout << "No item found between: " << rucksack[0] << " and " << rucksack[1] << endl;
    return 0;
}

int Year2022_Day3::GetItemOrder(const char item) const
{
    int result;
    const int i = static_cast<unsigned char>(item);
    if(i >= 97)
    {
        result = i - 96;
    }
    else
    {
        result = i - 38;
    }
    return result;
}
