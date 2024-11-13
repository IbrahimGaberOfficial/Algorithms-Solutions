#include <bits\stdc++.h>
using namespace std;

class Solution {
    unordered_set<int> visited;
    void DFS(unordered_map<int,vector<int>>& graph, int next, int &count) {
        if (visited.find(next) != visited.end()) {
            return;
        }
        count++;
        visited.insert(next);
        for (size_t i = 0; i < graph[next].size(); ++i) {
            DFS(graph, graph[next][i], count);
        }
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int max_num = 0;
        int curr = 0;
        int next = 0;
        int count = 0;
        unordered_map<int, vector<int>> graph;

        for (size_t i = 0; i < nums.size(); i++) {
            curr = nums[i];
            graph[curr] = {};
            // if have prev
            int prev = curr - 1;
            if (graph.find(prev) != graph.end()) {
                graph[curr].push_back(prev);
                graph[prev].push_back(curr);
            }
            // if have next
            next = curr + 1;

            if (graph.find(next) != graph.end()) {
                graph[curr].push_back(next);
                graph[next].push_back(curr);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            curr = nums[i];
            count = 0;
            DFS(graph, curr, count);
            max_num = max(max_num, count);

        }

        return max_num;
    }
};

void testLongestConsecutive(vector<int>nums){
    Solution *sol = new Solution();
    auto result = sol->longestConsecutive(nums);
    cout << result << endl;
}
int main() {
    testLongestConsecutive({100,4,200,1,3,2});
    testLongestConsecutive({0,3,7,2,5,8,4,6,0,1});
    return 0;
}
