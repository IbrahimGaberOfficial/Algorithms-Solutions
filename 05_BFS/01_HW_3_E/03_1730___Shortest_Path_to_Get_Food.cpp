#include <bits\stdc++.h>
using namespace std;

class Solution {
private:
    typedef vector<vector<char>> GRAPH;
    const int OO = 10000000;  // A big value expressing infinity

    bool isvalid(int r, int c, GRAPH &matrix) {
        if (r < 0 || r >= (int)matrix.size())
            return false;
        if (c < 0 || c >= (int)matrix[0].size())
            return false;
        return true;
    }

    int BFS(GRAPH &adjList, int sr, int sc) {
        // vector<int> len(adjList.size(), OO);
        vector<vector<bool>> visited(adjList.size(),
                                     vector<bool>(adjList[0].size(), false));
        int dr[]{-1, 0, 1, 0};  // Delta for: up, right, down, left
        int dc[]{0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        // len[start] = 0;
        visited[sr][sc] = true;
        for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
            while (sz--) {
                int sr = q.front().first;
                int sc = q.front().second;
                int cur_r, cur_c;
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    cur_r = sr + dr[d];
                    cur_c = sc + dc[d];
                    if (isvalid(cur_r, cur_c, adjList)) {
                        char cur = adjList[cur_r][cur_c];
                        if (cur == '#')
                            return level + 1;
                        if (cur == 'X')
                            continue;
                        if (!visited[cur_r][cur_c]) {
                            q.push({cur_r, cur_c});

                            visited[cur_r][cur_c] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
    // Implicit: jump to 4 neighbors

public:
    int getFood(vector<vector<char>> &matrix) {
        int steps;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++)

                if (matrix[i][j] == '*') {
                    steps = BFS(matrix, i, j);
                    return steps;
                }
        }

        return steps;
    }
};
void test_solution(vector<vector<char>> matrix) {
    Solution *sol = new Solution();
    cout << sol->getFood(matrix) << endl;
}
int main() {
    test_solution({{'X', 'X', 'X', 'X', 'X', 'X'},
                   {'X', '*', 'O', 'O', 'O', 'X'},
                   {'X', 'O', 'O', '#', 'O', 'X'},
                   {'X', 'X', 'X', 'X', 'X', 'X'}});

    test_solution({   {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                      {'X', '*', 'O', 'X', 'O', '#', 'O', 'X'},
                      {'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X'},
                      {'X', 'O', 'O', 'O', 'O', '#', 'O', 'X'},
                      {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}});
    return 0;
}
