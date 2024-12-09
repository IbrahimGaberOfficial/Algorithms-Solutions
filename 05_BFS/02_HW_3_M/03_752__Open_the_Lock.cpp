#include <bits\stdc++.h>

#include <unordered_set>
using namespace std;

class Solution {
    const int OO = 10000000;  // A big value expressing infinity
    int BFS(unordered_set<int>& deadends, int start, int goal) {
        queue<int> q;
        bool visited[10000] = {};
        int digits[4] = {0};
        int next = 0;
        int tmp = 0;
        q.push(start);

        for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
            while (sz--) {
                int cur = q.front();
                digits[0] = cur % 10;
                digits[1] = (cur % 100) / 10;
                digits[2] = (cur % 1000) / 100;
                digits[3] = (cur % 100000) / 1000;

                q.pop();
                for (int j = 0; j < 4; ++j) {
                    // +1
                    tmp = digits[j];
                    int next_digit = (digits[j] + 1) % 10;
                    int prev_digit = digits[j] == 0 ? 9 : (digits[j] - 1);

                    digits[j] = next_digit;

                    next =
                        digits[0] + digits[1] * 10 + digits[2] * 100 + digits[3] * 1000;
                    if (next == goal)
                        return level + 1;
                    if (visited[next] || (deadends.find(next) != deadends.end())) {
                    } else {
                        visited[next] = true;
                        q.push(next);
                    }

                    digits[j] = prev_digit;
                    next =
                        digits[0] + digits[1] * 10 + digits[2] * 100 + digits[3] * 1000;
                    if (next == goal)
                        return level + 1;
                    if (visited[next] || (deadends.find(next) != deadends.end())) {
                    } else {
                        visited[next] = true;
                        q.push(next);
                    }
                    digits[j] = tmp;
                }
            }
        }
        return -1;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000")
            return 0;
        unordered_set<int> deadends_int;
        for (size_t i = 0; i < deadends.size(); ++i) {
            deadends_int.insert(stoi(deadends[i]));
        }
        if(deadends_int.find(0) != deadends_int.end())
            return - 1;

        int result = BFS(deadends_int, 0000, stoi(target));
        return result;
    }
};

void Test_openLock(vector<string> deadends, string target) {
    Solution* sol = new Solution();
    int result = sol->openLock(deadends, target);
    cout << result << endl;
}
int main() {
    Test_openLock({"0201","0101","0102","1212","2002"}, "0202");
    Test_openLock({"8888"}, "0009");
    Test_openLock({"8887","8889","8878","8898","8788","8988","7888","9888"}, "8888");
    Test_openLock({"0000"}, "8888");
    return 0;
}
