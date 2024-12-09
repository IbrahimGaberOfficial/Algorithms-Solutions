#include <bits\stdc++.h>
using namespace std;

const int INF = 2147483647;
class Solution {
private:
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
    }
};

void TestWallsAndGates(vector<vector<int>> rooms) {
    Solution* sol = new Solution();
    sol->wallsAndGates(rooms);
    for (auto row : rooms) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}
int main() {
    TestWallsAndGates(
        {{INF, -1, 0, INF},
         {INF, INF, INF, -1},
         {INF, -1, INF, -1},
         {0, -1, INF, INF}});

        return 0;
}
