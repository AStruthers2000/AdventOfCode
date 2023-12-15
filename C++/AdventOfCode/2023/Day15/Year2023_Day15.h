#pragma once
#include "../../Problem.h"

class Year2023_Day15 : public Problem
{
public:
    Year2023_Day15() : Problem("Year 2023 Day 15: Lens Library")
    {
        filepath = R"(./2023/Day15/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    enum HashPrime
    {
        HashPrime_Default = 17,
    };

    enum BoxCount
    {
        BoxCount_Default = 256
    };

    enum HashOperation
    {
        Remove,
        Add
    };
    
    struct StringHash
    {
        string unhashed_string;
        string label;
        HashOperation operation;
        int focal_length = -1;
        //vector<char> characters;
        //vector<int> ascii_chars;
        int hashed_value;
    };

    struct Box
    {
        vector<StringHash> lenses;
    };

    vector<StringHash> hashes;
    Box boxes[BoxCount_Default];
    
    void LoadHashes();

    static int HashString(const string& s);

    void ManualArrangementProcedure();
    bool IsLensPresent(const string& label, int box_num) const;
    int WhereIsLensPresent(const string& label, int box_num) const;
};
