#include <bits\stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
const int OO = 10000000;  // A big value expressing infinity

void add_directed_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
}

class Solution {
private:
    vector<int> BFS_v2(GRAPH &adjList, vector<int> &family, int start) {
        vector<int> len(adjList.size(), OO);
        queue<int> q;
        q.push(start);
        len[start] = 0;

        for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
            while (sz--) {
                int cur = q.front();
                q.pop();
                for (int neighbour : adjList[cur])
                    if (len[neighbour] == OO) {  // never visited
                        q.push(neighbour);
                        len[neighbour] = level + 1;
                        family[neighbour] = cur;
                    }
            }
        }
        return len;
    }

public:
    void printPath(vector<vector<int>> &_pairs, int nodes, int start) {
        vector<int> family(nodes, -2);
        // build the graph
        GRAPH graph(nodes);
        for (int i = 0; i < _pairs.size(); i++) {
            add_directed_edge(graph, _pairs[i][0], _pairs[i][1]);
        }
        family[start] = -1;

        BFS_v2(graph, family, 0);

        string path = "";
        for (int i = 1; i < graph.size(); i++) {
            int father = i;
            path = to_string(i);

            cout << "0 : " << i << " ";
            while (true) {
                if (family[father] == -1) {
                    cout << " :: " << path << endl;
                    break;
                } else if (family[father] == -2) {
                    cout << "Not Existence";
                    break;
                }
                path = " " + to_string(family[father]) + " " + path;
                father = family[father];
            }
            cout << endl;
        }
    }
};

void testSolution(vector<vector<int>> pairs, int nodes, int start) {
    Solution *solution = new Solution();
    solution->printPath(pairs, nodes, start);
}
int main() {
    testSolution({{5, 4}, {0, 1}, {1, 2}, {2, 3}, {4, 3}}, 6, 0);

    // 2

    // 5 4
    // 0 1
    // 1 2
    // 2 3
    // 4 3

    // 9 13
    // 1 3
    // 1 5
    // 1 6
    // 3 5
    // 4 3
    // 3 7
    // 5 4
    // 6 0
    // 2 4
    // 2 8
    // 0 2
    // 2 8
    // 2 2

    return 0;
}
