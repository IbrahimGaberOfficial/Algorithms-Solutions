#include <bits\stdc++.h>
using namespace std;

class Solution {
    const int OO = 10000000;  // A big value expressing infinity
    int BFS(vector<int>& nums, int start, int goal) {
        queue<int> q;
        bool visited[1001] = {};
        int next = 0;
        q.push(start);

        for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
            while (sz--) {
                int cur = q.front();
                q.pop();
                if (cur >= 0 & cur <= 1000) {
                    for (int i = 0;i < nums.size(); ++i) {
                        for (int j = 0; j < 3; ++j) {
                            // x + nums[i]
                            if (j == 0)
                                next = cur + nums[i];
                            // x - nums[i]
                            else if (j == 1)
                                next = cur - nums[i];
                            // x ^ nums[i] (bitwise-XOR)
                            else if (j == 2)
                                next = cur ^ nums[i];

                            if (next == goal)
                                return level + 1;
                            if(next < 0 || next > 1000 || visited[next])
                                continue;
                            q.push(next);
                        }
                    }
                    
                }
            }
        }

        return -1;
    }

public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int result = BFS(nums, start, goal);
        return result;
    }
};

void Test_minimumOperations(vector<int> nums, int start, int goal) {
    Solution* sol = new Solution();
    int result = sol->minimumOperations(nums, start, goal);
    cout << result << endl;
}
int main() {
    Test_minimumOperations({2, 4, 12}, 2, 12);
    Test_minimumOperations({3, 5, 7}, 0, -4);
    Test_minimumOperations({2, 8, 16}, 0, 1);
    return 0;
}
