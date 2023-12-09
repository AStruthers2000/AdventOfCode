#include "Year2023_Day9.h"

string Year2023_Day9::Problem1()
{
    LoadAllSequences();
    
    int sum_history = 0;
    
    for(const auto& sequence : all_sequences)
    {
        sum_history += *(sequence.end()-1) + GetNextSequence(sequence, false);
    }
    
    return to_string(sum_history);
}

string Year2023_Day9::Problem2()
{
    LoadAllSequences();
    
    int sum_history = 0;
    
    for(const auto& sequence : all_sequences)
    {
        sum_history += *sequence.begin() - GetNextSequence(sequence, true);;
    }
    return to_string(sum_history);
}

int Year2023_Day9::GetNextSequence(const vector<int>& sequence, bool prepend)
{
    vector<int> difference;
    for(size_t i = 1; i < sequence.size(); i++)
    {
        difference.push_back(sequence[i] - sequence[i-1]);
    }

    if(IsVectorEntirelyN(difference, 0)) return 0;
    
    const int n = prepend ? *difference.begin() : *(difference.end()-1);
    if(prepend) return n - GetNextSequence(difference, prepend);
    return n + GetNextSequence(difference, prepend);
    
}

void Year2023_Day9::LoadAllSequences()
{
    all_sequences.clear();
    
    for(const auto& line : lines)
    {
        vector<int> s;
        vector<string> l = SplitLineByToken(line, ' ');
        s.reserve(l.size());
        for(const auto& i : l)
        {
            s.push_back(stoi(i));
        }
        all_sequences.push_back(s);
    }
}
