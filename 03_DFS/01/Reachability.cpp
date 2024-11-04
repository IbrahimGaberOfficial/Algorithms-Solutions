#include <bits\stdc++.h>
using namespace std;
typedef vector<vector<int>> GRAPH;

#pragma region MyCode
// void DFS(GRAPH & graph, vector<bool> &visited, int node, bool isHead){
//     if(visited[node])
//         return;
//         //  cout << graph[node][i] << "| ";
//         if(!isHead)
//             cout << node << "| ";
//         visited[node] = true;
//     for(int i = 0; i < graph[node].size(); i++){
//         DFS(graph, visited, graph[node][i], false);
//     }
// }
// void Reachability(GRAPH graph){
//         int nodes = graph.size();
//     for (int  i = 0; i < nodes; i++)
//     {

//         vector<bool> visited(nodes);
//         cout << i << " can reach : ";
//         DFS(graph, visited, i, true);
//         cout << endl;
//     }
    
// }

#pragma endregion MyCode

#pragma region Dr_Code
void DFS(GRAPH & graph, vector<bool> &visited, int node){
   
            
    visited[node] = true;
    for(int i = 0; i < graph[node].size(); i++){
        int nighbour = graph[node][i];
        if(!visited[nighbour]){
            cout << nighbour << "| ";
            DFS(graph, visited, nighbour);
        }
    }
}
void Reachability(GRAPH graph){
        int nodes = graph.size();
    for (int  i = 0; i < nodes; i++)
    {

        vector<bool> visited(nodes);
        cout << i << " can reach : ";
        DFS(graph, visited, i);
        cout << endl;
    }
    
}
#pragma endregion Dr_Code

int main(){

    Reachability(
        {
            {1, 3},
            {4, 0},
            {0},
            {1},
            {3},
            {6},
            {}
        }
    );

return 0;
}
