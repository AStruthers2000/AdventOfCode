#include "Year2023_Day6.h"

string Year2023_Day6::Problem1()
{
    ParseSpacedInput();
    int64_t margin_of_error = 1;
    for(auto& race : races)
    {
        race.FindHoldTimes();
        margin_of_error *= race.num_viable_holds;
    }
    return to_string(margin_of_error);
}

string Year2023_Day6::Problem2()
{
    ParseBigRace();
    big_race.FindHoldTimes();
    return to_string(big_race.num_viable_holds);
}

void Year2023_Day6::ParseSpacedInput()
{
    vector<string> salted_times = SplitLineByToken(lines[0], ' ');
    salted_times = {salted_times.begin() + 1, salted_times.end()};
    vector<string> salted_distances = SplitLineByToken(lines[1], ' ');
    salted_distances = {salted_distances.begin() + 1, salted_distances.end()};
    
    vector<int> times;
    vector<int> distances;

    for(const auto& time : salted_times)
    {
        if(!time.empty()) times.push_back(stoi(time)); 
    }

    for(const auto& distance : salted_distances)
    {
        if(!distance.empty()) distances.push_back(stoi(distance)); 
    }

    for(size_t i = 0; i < times.size(); i++)
    {
        races.push_back({times[i], distances[i], times[i]/2});
    }
}

void Year2023_Day6::ParseBigRace()
{
    vector<string> salted_times = SplitLineByToken(lines[0], ' ');
    salted_times = {salted_times.begin() + 1, salted_times.end()};
    vector<string> salted_distances = SplitLineByToken(lines[1], ' ');
    salted_distances = {salted_distances.begin() + 1, salted_distances.end()};
    
    string time;
    string distance;

    for(const auto& t : salted_times)
    {
        if(!t.empty()) time += t; 
    }

    for(const auto& d : salted_distances)
    {
        if(!d.empty()) distance += d; 
    }

    const int64_t t = strtoll(time.c_str(), nullptr, 10);
    const int64_t d = strtoll(distance.c_str(), nullptr, 10);
    big_race = {t, d, t / 2};
}
