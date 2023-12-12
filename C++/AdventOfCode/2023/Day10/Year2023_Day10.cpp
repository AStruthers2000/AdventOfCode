#include "Year2023_Day10.h"



string Year2023_Day10::Problem1()
{
    ReadMaze();
    const vector<MazeCoord> start_tiles = GetValidSurroundingPipes(start);
    //TraverseMaze(default_coord, start_tiles[0]);
    TraverseMaze();
    cout << endl;
    return to_string((loop.size()+1)/2);
}

string Year2023_Day10::Problem2()
{
    ReadMaze();
    PrintMaze();
    ConvertLoopToBound();
    PrintMaze();
    const int inside_tiles = CheckGroundPointsInMaze();
    PrintMaze();
    return to_string(inside_tiles);
}

void Year2023_Day10::ReadMaze()
{
    if(!maze.empty()) return;
    
    for(size_t row = 0; row < lines.size(); row++)
    {
        vector<char> cur_line;
        for(size_t col = 0; col < lines[row].size(); col++)
        {
            cur_line.push_back(lines[row][col]);
            if(lines[row][col] == 'S')
            {
                start = {static_cast<int>(row), static_cast<int>(col), 'S'};
            }
        }
        maze.push_back(cur_line);
    }
}

void Year2023_Day10::TraverseMaze(MazeCoord prev, MazeCoord cur)
{
    
    const vector<MazeCoord> surrounding = GetValidSurroundingPipes(cur);
    for(const auto& t : surrounding)
    {
        if(t != prev && t != start)
        {
            loop.push_back(cur);
            TraverseMaze(cur, t);
        }

        if(t == start && prev != default_coord)
        {
            loop.push_back(cur);
            return;
        }
    }
}

void Year2023_Day10::TraverseMaze()
{
    MazeCoord prev = default_coord;
    MazeCoord cur = GetValidSurroundingPipes(start)[0];

    bool back_at_end = false;
    while(!back_at_end)
    {
        const vector<MazeCoord> surrounding = GetValidSurroundingPipes(cur);
        for(const auto& t : surrounding)
        {
            if(t != prev && t != start)
            {
                loop.push_back(cur);
                prev = cur;
                cur = t;
                break;
            }

            if(t == start && prev != default_coord)
            {
                loop.push_back(cur);
                back_at_end = true;
                break;
            }
        }
    }

    cout << endl;
}

vector<Year2023_Day10::MazeCoord> Year2023_Day10::GetValidSurroundingPipes(MazeCoord cur)
{
    vector<MazeCoord> valid;
    MazeCoord north; 
    MazeCoord south;
    MazeCoord east;
    MazeCoord west; 
    if(cur.row - 1 >= 0)
    {
        north = {cur.row - 1, cur.col, maze[cur.row - 1][cur.col]};
    }
    if(cur.row + 1 < static_cast<int>(maze.size()))
    {
        south = {cur.row + 1, cur.col, maze[cur.row + 1][cur.col]};
    }
    if(cur.col - 1 >= 0)
    {
        west = {cur.row, cur.col - 1, maze[cur.row][cur.col - 1]};
    }
    if(cur.col + 1 < static_cast<int>(maze[cur.row].size()))
    {
        east = {cur.row, cur.col + 1, maze[cur.row][cur.col + 1]};
    }
    switch(cur.maze_tile)
    {
    case '|':
        valid.push_back(north);
        valid.push_back(south);
        break;
    case '-':
        valid.push_back(east);
        valid.push_back(west);
        break;
    case 'L':
        valid.push_back(north);
        valid.push_back(east);
        break;
    case 'J':
        valid.push_back(north);
        valid.push_back(west);
        break;
    case '7':
        valid.push_back(south);
        valid.push_back(west);
        break;
    case 'F':
        valid.push_back(south);
        valid.push_back(east);
        break;
    case 'S':
        for(const auto& c : {north, south, east, west})
        {
            if(c.row != -1 && c.col != -1)
            {
                vector<MazeCoord> surrounding = GetValidSurroundingPipes(c);
                for(const auto& m : surrounding)
                {
                    if(m == cur)
                    {
                        valid.push_back(c);
                    }
                }
            }
        }
        break;
    default:
        //cout << "Somehow exited the maze..." << endl;
        break;
    }
    return valid;
}

void Year2023_Day10::ConvertLoopToBound()
{
    for(const auto& coord : loop)
    {
        const char c = maze[coord.row][coord.col];
        if(c == '|' || c == 'L' || c == 'J')
            maze[coord.row][coord.col] = '!';
        else
            maze[coord.row][coord.col] = LOOP_BOUND;
    }

    maze[start.row][start.col] = '!';
    for (auto& row : maze)
    {
        //row.insert(row.begin(), '.');
        //row.push_back('.');
        for(int col = 0; col < static_cast<int>(maze[0].size()); col++)
        {
            if(row[col] != LOOP_BOUND && row[col] != '!')
            {
                row[col] = '.';
            }
        }
    }
}

int Year2023_Day10::CheckGroundPointsInMaze()
{
    int inside_tiles = 0;
    bool inside_maze = false;
    for(int row = 0; row < static_cast<int>(maze.size()); row++)
    {
        for(int col = 0; col < static_cast<int>(maze[0].size()); col++)
        {
            const char tile = maze[row][col];
            if(tile == '!')
            {
                inside_maze = !inside_maze;
                continue;
            }

            if(tile == '.')
            {
                if(inside_maze )
                {
                    maze[row][col] = '^';
                    inside_tiles++;
                }
                else
                {
                    maze[row][col] = 'O';
                }
            }
            /*
            if(tile != '.') continue;
            vector<char> subset_left = {maze[row].begin(), maze[row].begin() + col};
            vector<char> subset_right = {maze[row].begin() + col + 1, maze[row].end()};
            const int count_left = CountOccurrencesOfCharInString(subset_left, LOOP_BOUND);
            const int count_right = CountOccurrencesOfCharInString(subset_right, LOOP_BOUND);

            //if(*maze[row].begin() == LOOP_BOUND && count_left%2==0) count_left++;
            //if(*(maze[row].end()-1) == LOOP_BOUND && count_right%2==0) count_right++;

            if(count_left%2 != 0 && count_right%2 != 0)//CountOccurrencesOfCharInString(walls, '.') > 0)
            {
                cout << "Tile ("<<row<<", "<<col<<") inside loop" << endl;
                maze[row][col] = 'i';
                inside_tiles++;
            }
            else
            {
                maze[row][col] = 'O';
            }
            */
            
            //cout << endl;
        }
        inside_maze = false;
    }

    return inside_tiles;
}

void Year2023_Day10::PrintMaze()
{
    cout << "Maze: " << endl;
    for(const auto& row : maze)
    {
        for(const auto& col : row)
        {
            cout << col;
        }
        cout<<endl;
    }
}
