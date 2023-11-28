#include "Problem.h"

void Problem::ReadFromFile(const string& filename)
{
    ifstream file(filepath + filename);
    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    else
    {
        cerr << "Failed to read file at " << filepath + filename << endl;
        exit(-1);
    }
}

vector<string> Problem::SplitLineByToken(const string& line, const char token) const
{
    vector<string> split;
    string word;
    istringstream iss(line);
    while(getline(iss, word, token))
    {
        split.push_back(word);
    }
    return split;
}
