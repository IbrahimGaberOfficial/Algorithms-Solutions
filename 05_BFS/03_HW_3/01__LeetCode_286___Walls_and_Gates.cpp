#include <bits\stdc++.h>
using namespace std;

const int INF = 2147483647;
class Solution {
private:
    // Delta for: up, right, down, left
    int dr[4]{-1, 0, 1, 0};
    int dc[4]{0, 1, 0, -1};
    bool isvalid(int r, int c, vector<vector<int>> &matrix) {
        if (r < 0 || r >= (int)matrix.size())
            return false;
        if (c < 0 || c >= (int)matrix[0].size())
            return false;
        if (matrix[r][c] != INF)
            return false;
        return true;
    }

    void BFS_v2(vector<vector<int>> &rooms, queue<pair<int, int>> &cells, vector<vector<bool>> &visited) {
        int visitLimit = cells.size();

        for (int level = 0, sz = cells.size(); !cells.empty(); ++level, sz = cells.size()) {
            while (sz--) {
                auto cur = cells.front();
                int r = cur.first, c = cur.second;
                cells.pop();

                // the four nighbours  up, right, down, left
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (!isvalid(nr, nc, rooms) || visited[nr][nc])
                        continue;
                    visited[nr][nc] = true;
                    cells.push({nr, nc});
                    
                    rooms[nr][nc] = level + 1;
                }
            }
        }
    }

public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        if (rooms.size() == 0)
            return;
        queue<pair<int, int>> cells;
         vector<vector<bool>> visited(rooms.size(), vector<bool>(rooms[0].size(), false));
        for (int r = 0; r < rooms.size(); r++) {
            for (int c = 0; c < rooms[0].size(); c++) {
                if(rooms[r][c] == 0){
                    cells.push({r, c});
                    visited[r][c] = true;
                }
            }
        }
        BFS_v2(rooms, cells, visited);
    }
};

void TestWallsAndGates(vector<vector<int>> rooms) {
    Solution *sol = new Solution();
    sol->wallsAndGates(rooms);
    for (auto row : rooms) {
        for (auto cell : row) {
            cout << setw(5) <<  cell << " ";
        }
        cout << endl;
    }
}
int main() {
    TestWallsAndGates(
        {{INF, -1,  0,   INF},
         {INF, INF, INF, -1},
         {INF, -1,  INF, -1},
         {0,   -1,  INF, INF}});

    return 0;
}
