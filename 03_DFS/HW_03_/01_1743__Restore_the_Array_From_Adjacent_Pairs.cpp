
/*problem: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs */

#include <bits\stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nums;
    unordered_set<int> visited;
    void DFS(unordered_map<int, vector<int>>& graph, int next) {
        if (visited.find(next) != visited.end()) {
            return;
        }
        nums.push_back(next);
        visited.insert(next);
        for (size_t i = 0; i < graph[next].size(); ++i) {
            DFS(graph, graph[next][i]);
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_set<int> start;
        unordered_map<int, vector<int>> graph;
        for (auto num_pari : adjacentPairs) {
            graph[num_pari[0]].push_back(num_pari[1]);
            graph[num_pari[1]].push_back(num_pari[0]);

            if (start.find(num_pari[0]) == start.end()) {
                start.insert(num_pari[0]);
            } else {
                start.erase(num_pari[0]);
            }
            if (start.find(num_pari[1]) == start.end()) {
                start.insert(num_pari[1]);
            } else {
                start.erase(num_pari[1]);
            }
        }

        int next = *start.begin();
        DFS(graph, next);

        return nums;
    }
};

void testRestoreArray(vector<vector<int>> adjacentPairs) {
    Solution* sol = new Solution();
    auto result = sol->restoreArray(adjacentPairs);

    for (auto element : result) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    testRestoreArray({{2, 1}, {3, 4}, {3, 2}});
    testRestoreArray({{4, -2}, {1, 4}, {-3, 1}});
    return 0;
}
