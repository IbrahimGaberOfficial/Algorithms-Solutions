#include <bits\stdc++.h>
using namespace std;

class Solution
{
    vector<vector<pair<int, int>>> connected_components;
    bool isValid(int row, int col, int rows_size, int cols_size)
    {
        if (row < 0 || row > rows_size)
            return false;
        else if (col < 0 || col > cols_size)
            return false;

        return true;
    }
    void DFS(vector<vector<int>> &grid, vector<vector<bool>> &visited, int color, int sr, int sc, int lable)
    {
        if (visited[sr][sc] || grid[sr][sc] != color)
            return;
        connected_components[lable].push_back({sr, sc});
        visited[sr][sc] = true;
        // left r , c - 1
        if (isValid(sr, sc - 1, grid.size() - 1, grid[0].size() - 1))
        {
            DFS(grid, visited, color, sr, sc - 1, lable);
        }
        // right r , c + 1
        if (isValid(sr, sc + 1, grid.size() - 1, grid[0].size() - 1))
        {
            DFS(grid, visited, color, sr, sc + 1, lable);
        }
        // up r - 1
        if (isValid(sr - 1, sc, grid.size() - 1, grid[0].size() - 1))
        {
            DFS(grid, visited, color, sr - 1, sc, lable);
        }
        // down
        if (isValid(sr + 1, sc, grid.size() - 1, grid[0].size() - 1))
        {
            DFS(grid, visited, color, sr + 1, sc, lable);
        }

        // check nighbours and DFS on them
    }

    bool is_borader(int row, int col, vector<vector<int>> &grid)
    {
        // check if is non border
        if (row == 0 || row == grid.size() - 1 || col == 0 || col == grid[0].size() - 1)
        {
            return true;
        }
        return false;
    }

public:

    int closedIsland(vector<vector<int>> &grid)
    {

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int lable = 0;
        // get connected compontents
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!(visited[i][j] || grid[i][j] != 0)){
                    connected_components.emplace_back();
                    DFS(grid, visited, 0, i, j, lable);
                    lable++;
                }
            }
        }
        lable = 0;
        bool closed = false;
        // check if any element touuches the boundries

        for (auto connected_component : connected_components)
        {
            for (auto cell : connected_component)
            {

                if (is_borader(cell.first, cell.second, grid))
                {
                    closed = false;
                    break;
                }
                closed = true;
            }
            lable += closed;

        }
        return lable;
    };
};

void testClosedIsland(vector<vector<int>> grid)
{
    Solution *sol = new Solution();
    int result = sol->closedIsland(grid);
    cout << result << endl;
}
int main()
{
    testClosedIsland({{1,1,1,1,1,1,1,0},
                      {1,0,0,0,0,1,1,0},
                      {1,0,1,0,1,1,1,0},
                      {1,0,0,0,0,1,0,1},
                      {1,1,1,1,1,1,1,0}});

    testClosedIsland({{0,0,1,0,0},
                      {0,1,0,1,0},
                      {0,1,1,1,0}});                  

    testClosedIsland({{1,1,1,1,1,1,1},
                      {1,0,0,0,0,0,1},
                      {1,0,1,1,1,0,1},
                      {1,0,1,0,1,0,1},
                      {1,0,1,1,1,0,1},
                      {1,0,0,0,0,0,1},
                      {1,1,1,1,1,1,1}});        

    return 0;
}
