#pragma once
#include "../../Problem.h"

constexpr int MAX_FOLDER_SIZE = 100000;
constexpr int TOTAL_DISK_SPACE = 70000000;
constexpr int REQUIRED_SPACE = 30000000;

class Year2022_Day7 : public Problem
{
public:
    Year2022_Day7() : Problem("Year 2022 Day 7: No Space Left On Device")
    {
        filepath = R"(./2022/Day7/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    struct File
    {
        int size;
        string name;
    };
    
    struct Folder
    {
        Folder* parent;
        string folder_name;
        vector<Folder*> subfolders;
        vector<File> files;
        int sum_of_sizes = 0;

        bool operator<(const Folder& a) const
        {
            return sum_of_sizes < a.sum_of_sizes;
        }
    };

    static bool CompareFolderBySize(const Folder* a, const Folder* b)
    {
        return (a->sum_of_sizes < b->sum_of_sizes);
    }

    Folder* head = new Folder{nullptr, "/", {}, {}};
    Folder* LookUpFolderByName(const Folder* current, const string& name) const;

    void ParseFile();
    void VisitSubfolders(const Folder* current, int* sum);
    void VisitSubfolders(const Folder* current, int size_needed, vector<const Folder*> &could_delete);
};
