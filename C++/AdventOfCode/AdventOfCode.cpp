#include <vector>

#include "Problem.h"
#include "2022/Day1/Year2022_Day1.h"
#include "2022/Day2/Year2022_Day2.h"
#include "2022/Day3/Year2022_Day3.h"
#include "2022/Day4/Year2022_Day4.h"
#include "2022/Day5/Year2022_Day5.h"
#include "2022/Day6/Year2022_Day6.h"
#include "2022/Day7/Year2022_Day7.h"
#include "2022/Day8/Year2022_Day8.h"
#include "2023/Day1/Year2023_Day1.h"
#include "2023/Day2/Year2023_Day2.h"
#include "2023/Day3/Year2023_Day3.h"
using namespace std;

enum
{
    FIRST_YEAR = 2022
};

enum ProblemState
{
    Test,
    Full
};

constexpr ProblemState state = Full;
constexpr int year = 2023;
constexpr int day = 3;

int main(int argc, char* argv[])
{
    const vector<vector<Problem*>> problems = {
        //2022 problems
        {
            new Year2022_Day1(), new Year2022_Day2(), new Year2022_Day3(), new Year2022_Day4(), new Year2022_Day5(),
            new Year2022_Day6(), new Year2022_Day7(), new Year2022_Day8()
        },

        //2023 problems
        {
            new Year2023_Day1(), new Year2023_Day2(), new Year2023_Day3()
        }
    };

    int problem_year = year;
    int problem_day = day;
    ProblemState problem_state = state;
    
    if(argc == 3)
    {
        const int arg_year = strtol(argv[1], nullptr, 10);
        const int arg_day = strtol(argv[2], nullptr, 10);
        problem_year = arg_year;
        problem_day = arg_day;
        problem_state = Full;
    }
    
    if(static_cast<int>(problems.size()) > problem_year - FIRST_YEAR &&
        static_cast<int>(problems[problem_year - FIRST_YEAR].size()) > problem_day - 1)
    {
        const auto problem = problems[problem_year - FIRST_YEAR][problem_day - 1];

        cout << "Solving " << problem->GetProblemName() << endl;
        problem->ReadFromFile(problem_state  == Test ? "test.txt" : "input.txt");
        cout << "Solution to problem 1:\t" << problem->Problem1() << endl;
        cout << "--------------------" << endl;
        cout << "Solution to problem 2:\t" << problem->Problem2() << endl;
        cout << "====================" << endl;
    }
    else
    {
        cout << "Problem " << problem_day << " for year " << problem_year << " doesn't seem to exist yet" << endl;
    }
    return 0;
}
