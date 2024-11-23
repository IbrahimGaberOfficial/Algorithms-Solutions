#include <bits\stdc++.h>
using namespace std;

class Solution
{
private:
    void DFS(vector<vector<int>> &graph, vector<bool> &visited, int curr)
    {
        

        visited[curr] = true;
        for (int i = 0; i < graph[curr].size(); i++)
        {
            int next = graph[curr][i];
            if(!visited[next]){
                DFS(graph, visited, graph[curr][i]);
            }
        }
      
    }

public:
    // Solution(){}
    int NumberOfConnectedComponents(int nodes, vector<vector<int>> &components)
    {
        // build the graph
        // dfs on the process
        vector<vector<int>> graph(nodes);
        vector<bool> visited(nodes, 0);
        int components_num = 0;
         int from, to;
        for (int i = 0; i < components.size(); i++)
        {
            from = components[i][0];
            to = components[i][1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for(int i = 0 ; i < graph.size(); i++){
            int next = i;
            if(!visited[next]){
                DFS(graph, visited, next);
                components_num++;
            }
        }
        return components_num;
    }
};

void TestSol(int nodes, vector<vector<int>> components)
{
    Solution *sol = new Solution();
    int result = sol->NumberOfConnectedComponents(nodes, components);
    cout << result << endl;
}
int main()
{
    TestSol(5, {{0, 1}, {1, 2}, {3, 4}});
    TestSol(5 ,{{0, 1}, {1, 2}, {2, 3}, {3, 4}});
    return 0;
}
