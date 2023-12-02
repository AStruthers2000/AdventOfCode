#include "Year2023_Day1.h"

#include <map>

string Year2023_Day1::Problem1()
{
    int sum_of_calibrations = 0;
    for(const auto& line : lines)
    {
        const vector<int> calibration = FindNumber(line);
        const int combo = stoi(to_string(calibration[0]) + to_string(calibration[1]));
        sum_of_calibrations += combo;
    }
    return to_string(sum_of_calibrations);
}

string Year2023_Day1::Problem2()
{
    int sum_of_calibrations = 0;
    for(const auto& line : lines)
    {
        string parsed_line = ParseWordsToInts(line);
        const vector<int> calibration = FindNumber(parsed_line);
        /*cout << "Line:        " << line << endl;
        cout << "Parsed:      " << parsed_line << endl;
        cout << "Calibration: " << calibration[0] << calibration[1] << endl;
        cout << "=================================================" << endl;*/
        const int combo = stoi(to_string(calibration[0]) + to_string(calibration[1]));
        sum_of_calibrations += combo;
    }
    return to_string(sum_of_calibrations);
}

vector<int> Year2023_Day1::FindNumber(const string& line)
{
    vector<int> digits;
    for (const char& i : line)
    {
        if(isdigit(i))
        {
            digits.push_back(i - '0');
        }
    }
    vector<int> first_last = {digits[0], digits[digits.size()-1]};
    return first_last;
}

string Year2023_Day1::ParseWordsToInts(const string& line)
{
    string parsed_line = line;
    const map<string, string> words_to_ints = {
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"},
    };
    for(size_t i = 0; i < parsed_line.size(); i++)
    {
        for(const auto& mapped_word : words_to_ints)
        {
            string sub = parsed_line.substr(i, mapped_word.first.size());
            if(sub == mapped_word.first)
            {
                parsed_line.replace(i+1, sub.size()-2, mapped_word.second);
            }
        }
    }
    return parsed_line;
}
