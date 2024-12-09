#include <bits\stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
class Solution {
private:
    const int OO = 10000000;  // A big value expressing infinity

    void add_undirected_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> BFS_v2(GRAPH &adjList, vector<int> &father, int start, bool &have_cycle) {
        vector<int> len(adjList.size(), OO);
        queue<int> q;
        q.push(start);
        len[start] = 0;

        for (int level = 0, sz = 1; !q.empty() && !have_cycle; ++level, sz = q.size()) {
            while (sz-- && !have_cycle) {
                int cur = q.front();
                q.pop();
                for (int child : adjList[cur])
                    if (len[child] == OO) {  // never visited
                        q.push(child);
                        len[child] = level + 1;
                        father[child] = cur;
                    } else if ((father[cur] != child) &&
                               (father[child] != -2)) {  // have anothe father
                        have_cycle = true;
                    }
            }
        }
        return len;
    }
    void build_graph(GRAPH &graph, vector<vector<int>> &edges) {
        for (int i = 0; i < edges.size(); i++) {
            add_undirected_edge(graph, edges[i][0], edges[i][1]);
        }
    }

public:
    bool validTree(int nodes, vector<vector<int>> &edges) {
        if (edges.size() >= nodes)
            return false;

        vector<int> family(nodes, -2);
        bool have_cycle = false;
        // build the graph
        GRAPH graph(nodes);
        build_graph(graph, edges);

        // build the family
        BFS_v2(graph, family, 0, have_cycle);

        // check for cycles
        if(have_cycle)
            return false;

        // check for spare components
        return true;
    }
};
void test_solution(int nodes, vector<vector<int>> edges) {
    Solution *sol = new Solution();
    auto result = sol->validTree(nodes, edges);
    cout << result << endl;
}
int main() {
    test_solution(5, {{0, 1}, {0, 2}, {0, 3}, {1, 4}});
    test_solution(5, {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}});
    return 0;
}
