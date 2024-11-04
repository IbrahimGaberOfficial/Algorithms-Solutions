#include <bits\stdc++.h>
using namespace std;

class Solution {
    bool isValid(int row, int col, int rows_size, int cols_size){
        if(row < 0 || row > rows_size)
            return false;
        else if(col < 0 || col > cols_size)
            return false;
        
        return true;

    }
    void DFS(vector<vector<int>>& image,vector<vector<bool>>& visited, int sr, int sc,int old_color, int new_color){
        if(visited[sr][sc] || (image[sr][sc] != old_color))
            return;
        // mark as vidiited
        visited[sr][sc] = true;
        // change the color
        image[sr][sc] = new_color;
            // left r , c - 1
        if(isValid(sr, sc - 1, image.size() - 1, image[0].size()- 1)){
            DFS(image, visited, sr, sc-1, old_color, new_color);
        }
        // right r , c + 1
        if(isValid(sr, sc + 1, image.size() - 1, image[0].size()- 1)){
            DFS(image, visited, sr, sc+1, old_color, new_color);
        }
        // up r - 1
        if(isValid(sr - 1, sc, image.size() - 1, image[0].size()- 1)){
            DFS(image, visited, sr - 1, sc, old_color, new_color);
        }
        //down
        if(isValid(sr + 1, sc, image.size() - 1, image[0].size()- 1)){
            DFS(image, visited, sr + 1, sc, old_color, new_color);
        }

        // check nighbours and DFS on them
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) {
        vector<vector<bool>>visited(image.size(), vector<bool>(image[0].size(), false));
        DFS(image, visited, sr, sc, image[sr][sc], new_color);
        return image;
    }
};

void printMatrix(vector<vector<int>>& image){
    cout << image.size() << " * " << image[0].size() << endl;
    for(auto row : image){
        for(auto cell : row){
            cout << cell << " ";
        }
        cout << endl;
    }
}
void testSol(vector<vector<int>> image, int sr, int sc, int new_color){
    cout << "+++++++ Before +++++++++++++" << endl;;
    printMatrix(image);

    Solution *sol = new Solution();
    auto result = sol->floodFill(image, sr, sc, new_color);
    cout << "+++++++ After +++++++++++++ | " << sr << " " << sc << " " << new_color << endl;;

    printMatrix(result);
}

int main(){

    
    testSol({{1,1,1},{1,1,0},{1,0,1}}, 1, 1, 2);
    testSol({{0,0,0},{0,0,0}}, 0, 0, 0);
return 0;
}
