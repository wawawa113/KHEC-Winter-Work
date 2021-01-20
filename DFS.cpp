#include <vector>
#include <utility>
#include <iostream>
#include "map_data/map.cpp"
using coordinate = std::pair<int, int>;

namespace domain
{
    void DFS(map maze, coordinate now, coordinate goal, map &visited, long long depth, long long &ANSWER_DEPTH, std::vector<map> &data)
    {
        if (depth == 0)
        {
            visited = maze;
        }
        std::vector<coordinate> visitable;
        int x = now.first;
        int y = now.second;
        if (now == goal)
        {
            ANSWER_DEPTH = depth;
            return;
        }

        if (visited.at(y).at(x) != 0)
        {
            return;
        }
        else
        {
            visited.at(y).at(x) = depth + 2;
        }
        data.push_back(visited);

        if (maze.at(y).at(x - 1) == 0)
        {
            visitable.push_back(std::make_pair(x - 1, y));
        }
        if (maze.at(y).at(x + 1) == 0)
        {
            visitable.push_back(std::make_pair(x + 1, y));
        }
        if (maze.at(y - 1).at(x) == 0)
        {
            visitable.push_back(std::make_pair(x, y - 1));
        }
        if (maze.at(y + 1).at(x) == 0)
        {
            visitable.push_back(std::make_pair(x, y + 1));
        }

        for (int i = 0; i < visitable.size(); i++)
        {
            int tx = visitable[i].first;
            int ty = visitable[i].second;
            DFS(maze, visitable.at(i), goal, visited, depth + 1,ANSWER_DEPTH,data);
        }
    }
} // namespace domain