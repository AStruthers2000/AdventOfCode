#include "Year2022_Day6.h"

string Year2022_Day6::Problem1()
{
    const int start_of_packet = FindFirstUniqueCharSequenceOfLength(4);
    return to_string(start_of_packet + 1);
}

string Year2022_Day6::Problem2()
{
    const int start_of_message = FindFirstUniqueCharSequenceOfLength(14);
    return to_string(start_of_message + 1);
}

int Year2022_Day6::FindFirstUniqueCharSequenceOfLength(int length) const
{
    const string datastream = lines[0];
    for(size_t i = length - 1; i < datastream.size(); i++)
    {
        unordered_set<char> marker;
        for(int j = 0; j < length; j++)
        {
            marker.emplace(datastream[i-j]);
        }
        if(static_cast<int>(marker.size()) == length)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}
