#include <chrono>
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
#include "2023/Day10/Year2023_Day10.h"
#include "2023/Day2/Year2023_Day2.h"
#include "2023/Day3/Year2023_Day3.h"
#include "2023/Day4/Year2023_Day4.h"
#include "2023/Day5/Year2023_Day5.h"
#include "2023/Day6/Year2023_Day6.h"
#include "2023/Day7/Year2023_Day7.h"
#include "2023/Day8/Year2023_Day8.h"
#include "2023/Day9/Year2023_Day9.h"
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

constexpr ProblemState state = Test;
constexpr int year = 2023;
constexpr int day = 10;

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
            new Year2023_Day1(), new Year2023_Day2(), new Year2023_Day3(), new Year2023_Day4(), new Year2023_Day5(),
            new Year2023_Day6(), new Year2023_Day7(), new Year2023_Day8(), new Year2023_Day9(), new Year2023_Day10()
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
        auto start = chrono::high_resolution_clock::now();
        cout << "Solution to problem 1:\t" << problem->Problem1() << endl;
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Problem 1 took " << static_cast<double>(duration.count()) / 1e+6 << " seconds to execute" << endl ;
        cout << "--------------------" << endl;
        start = chrono::high_resolution_clock::now();
        cout << "Solution to problem 2:\t" << problem->Problem2() << endl;
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Problem 2 took " << static_cast<double>(duration.count()) / 1e+6 << " seconds to execute" << endl ;
        cout << "====================" << endl;
    }
    else
    {
        cout << "Problem " << problem_day << " for year " << problem_year << " doesn't seem to exist yet" << endl;
    }
    return 0;
}
