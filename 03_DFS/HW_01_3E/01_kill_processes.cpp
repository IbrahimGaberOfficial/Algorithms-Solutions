#include <bits\stdc++.h>
using namespace std;

class Solution
{
private:
    void DFS(unordered_map<int, vector<int>> &processGraph, vector<int> &killdedProcesses, int kill)
    {
        killdedProcesses.push_back(kill);
        for (int i = 0; i < processGraph[kill].size(); i++)
        {
            DFS(processGraph, killdedProcesses, processGraph[kill][i]);
        }
    }

public:
   // Solution(){}
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
    {
        // build the graph
        // dfs on the process
        unordered_map<int, vector<int>> processGraph;
        for (int i = 0; i < pid.size(); i++)
        {
            if(ppid[i] == 0)
                continue;
            processGraph[ppid[i]].push_back(pid[i]);
        }
        vector<int> KilledProcesses;

        DFS(processGraph, KilledProcesses, kill);
        return KilledProcesses; 
    }

};

void TestSol(vector<int>pid, vector<int> ppid, int kill){
    Solution* sol = new Solution();
    auto result = sol->killProcess(pid, ppid, kill);
    cout << kill << ":\n    ";
    for(auto item : result)
        cout << item << " | ";
    cout << endl;

     
}
int main()
{
    TestSol({1, 3, 10, 5},
            {3, 0, 5, 3},
            5);
    TestSol({5, 2, 0, 1, 6, 3, 4},
            {0, 5, 5 , 5, 2, 2, 1}, 5);
             TestSol({5, 2, 0, 1, 6, 3, 4},
            {0, 5, 5 , 5, 2, 2, 1}, 0);
    return 0;
}
