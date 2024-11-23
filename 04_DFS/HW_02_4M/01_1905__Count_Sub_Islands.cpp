#include <bits\stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
     bool isValid(int row, int col, int rows_size, int cols_size){
        if(row < 0 || row > rows_size)
            return false;
        else if(col < 0 || col > cols_size)
            return false;
        
        return true;

    }
    void DFS_grid1(vector<vector<int>>& grid1,vector<vector<bool>>& visited,
                   unordered_map<string, int> &connected_grid1, int sr, int sc, int cnt){
        if(visited[sr][sc] || (grid1[sr][sc] == 0))
            return;
        // mark as vidiited
        visited[sr][sc] = true;       
        connected_grid1[to_string(sr) + "_" + to_string(sc) ] =  cnt;

            // left r , c - 1
        if(isValid(sr, sc - 1, grid1.size() - 1, grid1[0].size()- 1)){
            DFS_grid1(grid1, visited, connected_grid1 ,sr, sc-1, cnt);
        }
        // right r , c + 1
        if(isValid(sr, sc + 1, grid1.size() - 1, grid1[0].size()- 1)){
            DFS_grid1(grid1, visited, connected_grid1, sr, sc+1, cnt);
        }
        // up r - 1
        if(isValid(sr - 1, sc, grid1.size() - 1, grid1[0].size()- 1)){
            DFS_grid1(grid1, visited, connected_grid1, sr - 1, sc, cnt);
        }
        //down
        if(isValid(sr + 1, sc, grid1.size() - 1, grid1[0].size()- 1)){
            DFS_grid1(grid1, visited, connected_grid1, sr + 1, sc, cnt);
        }

        // check nighbours and DFS on them
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // get grid1 's connected components in hashtable (pair)-> labale number
        // get grid2 's connected components in vector of stacks
        // compare grid2 's stack with the lables pairs 
        vector<vector<bool>>visited(grid1.size(), vector<bool>(grid1[0].size(), false));
        unordered_map<string, int> connected_grid1;
         int cnt = 0;
         for (int i = 0; i < grid1.size(); i++){
           for(int j = 0; j < grid1[0].size(); j++){
            if(!visited[i][j]){
                DFS_grid1(grid1, visited, connected_grid1, i, j, cnt);
                cnt++;
            }
           }
         }
        return cnt;

    }
};

class DrSolution {
    bool isValid(int row, int col, int rows_size, int cols_size){
        if(row < 0 || row > rows_size)
            return false;
        else if(col < 0 || col > cols_size)
            return false;
        
        return true;

    }
    void DFS(vector<vector<int>>& grid1,vector<vector<int>>& grid2, 
                vector<vector<bool>>& visited, bool &is_sub_island,int sr, int sc){
        if(visited[sr][sc] || grid2[sr][sc] == 0)
            return;
       
         if(grid1[sr][sc] != grid2[sr][sc]){
             is_sub_island = false;
             return;
         }
         

        visited[sr][sc] = true;       
        is_sub_island =true;
            // left r , c - 1
        if(isValid(sr, sc - 1, grid1.size() - 1, grid1[0].size()- 1)){
            DFS(grid1, grid2, visited,is_sub_island,  sr, sc-1);
        }
        // right r , c + 1
        if(isValid(sr, sc + 1, grid1.size() - 1, grid1[0].size()- 1)){
            DFS(grid1, grid2, visited,is_sub_island, sr, sc+1);
        }
        // up r - 1
        if(isValid(sr - 1, sc, grid1.size() - 1, grid1[0].size()- 1)){
           DFS(grid1, grid2, visited,is_sub_island, sr - 1, sc);
        }
        //down
        if(isValid(sr + 1, sc, grid1.size() - 1, grid1[0].size()- 1)){
           DFS(grid1, grid2, visited,is_sub_island, sr + 1, sc);
        }

        // check nighbours and DFS on them
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         vector<vector<bool>>visited(grid1.size(), vector<bool>(grid1[0].size(), false));
         int cnt = 0;
         bool is_sub_island = true;
         for (int i = 0; i < grid1.size(); i++){
           for(int j = 0; j < grid1[0].size(); j++){
            if(!visited[i][j] &&  (grid1[i][j] != 0)){
                is_sub_island = true;
                DFS(grid1, grid2, visited, is_sub_island, i, j);
                cnt += is_sub_island;
            }
           }
         }
                 return cnt;

    }
};
void Test_countSubIslands(vector<vector<int>> grid1, vector<vector<int>> grid2){
    DrSolution *sol = new DrSolution();
    auto result = sol->countSubIslands(grid1, grid2);
    cout << result << endl;
}
int main(){

    Test_countSubIslands( 
        {{1,1,1,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {1,0,0,0,0},
        {1,1,0,1,1}}, 

        {{1,1,1,0,0},
        {0,0,1,1,1},
        {0,1,0,0,0},
        {1,0,1,1,0},
        {0,1,0,1,0}});

return 0;
}
