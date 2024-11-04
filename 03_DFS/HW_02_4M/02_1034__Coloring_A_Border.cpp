#include <bits\stdc++.h>
#include <unordered_set>
using namespace std;

class Solution
{
    vector <pair<int, int>> connected_component;

    bool isValid(int row, int col, int rows_size, int cols_size)
    {
        if (row < 0 || row > rows_size)
            return false;
        else if (col < 0 || col > cols_size)
            return false;

        return true;
    }
    void DFS(vector<vector<int>> &grid,
             vector<vector<bool>> &visited, int color, int sr, int sc)
    {
        if (visited[sr][sc] || grid[sr][sc] != color)
            return;
        connected_component.push_back({sr, sc});
        visited[sr][sc] = true;
        // left r , c - 1
        if (isValid(sr, sc - 1, grid.size() - 1, grid[0].size() - 1))
        {
            DFS(grid, visited, color, sr, sc - 1);
        }
        // right r , c + 1
        if (isValid(sr, sc + 1, grid.size() - 1, grid[0].size() - 1))
        {
            DFS(grid, visited, color, sr, sc + 1);
        }
        // up r - 1
        if (isValid(sr - 1, sc, grid.size() - 1, grid[0].size() - 1))
        {
            DFS(grid, visited, color, sr - 1, sc);
        }
        // down
        if (isValid(sr + 1, sc, grid.size() - 1, grid[0].size() - 1))
        {
            DFS(grid, visited, color, sr + 1, sc);
        }

        // check nighbours and DFS on them
    }

    bool is_borader(int row, int col, int current_color, vector<vector<int>> &grid)
    {
        // check if is non border
        if (row == 0 || row == grid.size()-1 || col == 0 || col == grid[0].size()-1)
        {
            return true;
        }
        if (grid[row][col - 1] == current_color &&
            grid[row][col + 1] == current_color &&
            grid[row + 1][col] == current_color &&
            grid[row - 1][col] == current_color)
        {
            return false;
        }
        return true;
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int new_color)
    {
        int old_color_value = grid[row][col];
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int lable = 0;
        // get connected compontents

                    DFS(grid, visited, old_color_value, row, col);


        // color the border
        // if the cell not surrounded with same color from 4 directions
        // it is a border
        // save the results in a new 
        vector<vector<int>> result(grid);
        for (auto cell : connected_component)
        {

                if (is_borader(cell.first, cell.second, old_color_value, grid))
                {
                    result[cell.first][cell.second] = new_color;
                }

        }
        return result;
    };
};

void TestColorBorder(vector<vector<int>> grid, int row, int col, int color)
{
    Solution *solution = new Solution;
    auto result = solution->colorBorder(grid, row, col, color);
    for (auto row : result)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    TestColorBorder({{1, 1},
                     {1, 2}},
                    0, 0, 3);

    TestColorBorder({{1, 2, 2},
                     {2, 3, 2}},
                    0, 1, 3);

    TestColorBorder({{1,1,1},
                    {1,1,1},
                    {1,1,1}}, 1, 1, 2);

    TestColorBorder({{1, 1, 1, 1, 1, 1, 1, 0},
                    {1, 0, 0, 0, 0, 1, 1, 0},
                    {1, 0, 1 ,0, 1, 1, 1, 0},
                    {1, 0, 0, 0, 0, 1, 0, 1},
                    {1, 1, 1, 1, 1, 1, 1, 0}}, 1, 1, 2);

    TestColorBorder({{2,1,3,2,1,1,2},
                     {1,2,3,1,2,1,2},
                     {1,2,1,2,2,2,2},
                     {2,1,2,2,2,2,2},
                     {2,3,3,3,2,1,2}} , 4, 4, 3);
    return 0;
}
