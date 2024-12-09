#include <bits\stdc++.h>
using namespace std;

class Solution {
private:
    const int OO = 10000000;  // A big value expressing infinity
    bool isValidPosition(int size, int position) {
        if (position < 0 || position > size - 1)
            return false;
        return true;
    }
    bool BFS(vector<int>& adjList, int start) {
        vector<int> len(adjList.size(), OO);
        queue<int> q;
        q.push(start);
        len[start] = 0;

        for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
            while (sz--) {
                int cur = q.front();
                q.pop();
                if(adjList[cur] == 0)
                    return true;
                int left_pos = cur - adjList[cur];
                int right_pos = cur + adjList[cur];

                if (isValidPosition(adjList.size(), left_pos)) {
                    if (len[left_pos] == OO) {  // never visited
                        q.push(left_pos);
                        len[left_pos] = level + 1;
                    }
                }
                if (isValidPosition(adjList.size(), right_pos)) {
                    if (len[right_pos] == OO) {  // never visited
                        q.push(right_pos);
                        len[right_pos] = level + 1;
                    }
                }
            }
        }

        return false;
    }

public:
    bool canReach(vector<int> &arr, int start) {
        return BFS(arr, start);
    }
};

void testSolution(vector<int> arr, int start){
     bool result = false;
    Solution* sol = new Solution();

     result = sol->canReach(arr, start);
    cout << result << endl;
}

int main() {
   

    testSolution({4, 2, 3, 0, 3, 1, 2}, 5);
    

    testSolution({4, 2, 3, 0, 3, 1, 2}, 0);
    

    testSolution({3, 0, 2, 1, 2}, 2);
    testSolution({0, 0}, 0);
    

    return 0;
}
