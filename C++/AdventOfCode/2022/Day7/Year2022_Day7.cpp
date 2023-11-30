#include "Year2022_Day7.h"

string Year2022_Day7::Problem1()
{
    ParseFile();
    int sum = 0;
    VisitSubfolders(head, &sum);
    return to_string(sum);
}

string Year2022_Day7::Problem2()
{
    return "";
}


void Year2022_Day7::ParseFile()
{
    Folder* current = head;
    for(size_t i = 0; i < lines.size(); )
    {
        string line = lines[i];
        if(line[0] == '$')
        {
            i+=2;
            const string dir = SplitLineByToken(line, ' ')[2];
            if(dir == "/") current = head;
            else if(dir == "..")
            {
                current = current->parent;
                i--;
            }
            else
            {
                current = LookUpFolderByName(current, dir);
            }
            
            while((line = lines[i])[0] != '$')
            {
                if(line[0] == 'd')
                {
                    const string folder_name = SplitLineByToken(line, ' ')[1];
                    auto new_folder = new Folder{current, folder_name, {}, {}};
                    current->subfolders.push_back(new_folder);
                }
                else
                {
                    const int file_size = stoi(SplitLineByToken(line, ' ')[0]);
                    const string file_name = SplitLineByToken(line, ' ')[1];
                    current->files.push_back(File{file_size, file_name});

                    Folder* traverse = current;
                    while(traverse != nullptr)
                    {
                        traverse->sum_of_sizes += file_size;
                        traverse = traverse->parent;
                    }
                }
                i++;
                if(i >= lines.size()) break;
            }
        }
    }
}

Year2022_Day7::Folder* Year2022_Day7::LookUpFolderByName(const Folder* current, const string& name) const
{
    for(const auto& subdir : current->subfolders)
    {
        if(subdir->folder_name == name) return subdir;
    }
    return new Folder{};
}

void Year2022_Day7::VisitSubfolders(const Folder* current, int* sum)
{
    if(current->sum_of_sizes <= MAX_FOLDER_SIZE)
    {
        *sum += current->sum_of_sizes;
    }
    
    for(const auto folder : current->subfolders)
    {
        VisitSubfolders(folder, sum);
    }
}