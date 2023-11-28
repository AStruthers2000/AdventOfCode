#include "Year2022_Day1.h"

float Year2022_Day1::Problem1()
{
    auto calorie_sums = GetCalorieSums();
    const int solution = *max_element(calorie_sums.begin(), calorie_sums.end());
    return static_cast<float>(solution);
}

float Year2022_Day1::Problem2()
{
    auto calorie_sums = GetCalorieSums();
    stable_sort(calorie_sums.begin(), calorie_sums.end(), greater<>());
    const int solution = calorie_sums[0] + calorie_sums[1] + calorie_sums[2];
    return static_cast<float>(solution);
}

vector<int> Year2022_Day1::GetCalorieSums() const
{
    int calorie_sum = 0;
    vector<int> per_elf_calories;
    for(const auto& line : lines)
    {
        if(!line.empty())
        {
            const int calorie = stoi(line);
            calorie_sum += calorie;
        }
        else
        {
            per_elf_calories.push_back(calorie_sum);
            calorie_sum = 0;
        }
    }
    per_elf_calories.push_back(calorie_sum);
    
    return per_elf_calories;
}
