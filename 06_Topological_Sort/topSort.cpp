#include <bits\stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> topSort(vector<vector<int>> &graph, queue<int> &nodes,
                        vector<int> &indegree) {
        vector<int> ordering;
        // loop on queeue and decresase indegree of nighbour
        while (nodes.size() != 0) {
            int current = nodes.front();
            nodes.pop();
            ordering.push_back(current);
            for (int nighbour : graph[current])
                // and if any one became zero add to the queue
                if (--indegree[nighbour] == 0)
                    nodes.push(nighbour);
        }

        return ordering;
    }

public:
    vector<int> sort_topology(vector<vector<int>> graph) {
        // add indegree
        vector<int> indegree(graph.size(), 0);
        for (int from = 0; from < graph.size(); from++) {
            for (int to = 0; to < graph[from].size(); to++)
                indegree[graph[from][to]]++;
        }
        // quef of 0-indegree nodes
        queue<int> ready_nodes;
        for (int i = 0; i < indegree.size(); i++)
            if (indegree[i] == 0)
                ready_nodes.push(i);
        // sned to topSort
        vector<int> ordering = topSort(graph, ready_nodes, indegree);
        return ordering;
    }
};

int main() {
    Solution *sol = new Solution();
    auto result =
        sol->sort_topology({{1}, {2}, {4, 3}, {}, {}, {0, 7}, {7, 8}, {2}, {2}});

    for (int val : result)
        cout << val << " -> ";

    return 0;
}
