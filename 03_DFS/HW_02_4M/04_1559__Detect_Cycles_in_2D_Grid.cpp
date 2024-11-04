#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <cassert>
#include <ccomplex>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <codecvt>
#include <complex>
#include <condition_variable>
#include <csetjmp>
#include <csignal>
#include <cstdalign>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

class Solution {
private:
    bool have_cyle = false;
    bool isValid(int row, int col, int rows_size, int cols_size, pair<int, int> father) {
        if (row < 0 || row > rows_size)
            return false;
        else if (col < 0 || col > cols_size)
            return false;
        else if (row == father.first && col == father.second)
            return false;

        return true;
    }
    void DFS(vector<vector<char>> &grid, vector<vector<bool>> &visited, char color,
             int sr, int sc, pair<int, int> father) {
        if (grid[sr][sc] != color || have_cyle)
            return;

        if (visited[sr][sc]) {
            have_cyle = true;
            return;
        }
        visited[sr][sc] = true;
        int newSr, newSc;

        // check nighbours and DFS on them

        // left r , c - 1
        newSr = sr;
        newSc = sc - 1;
        if (isValid(newSr, newSc, grid.size() - 1, grid[0].size() - 1, father)) {
            DFS(grid, visited, color, newSr, newSc, make_pair(sr, sc));
        }
        // right r , c + 1
        newSr = sr;
        newSc = sc + 1;
        if (isValid(newSr, newSc, grid.size() - 1, grid[0].size() - 1, father)) {
            DFS(grid, visited, color, newSr, newSc, make_pair(sr, sc));
        }
        // up r - 1
        newSr = sr - 1;
        newSc = sc;
        if (isValid(newSr, newSc, grid.size() - 1, grid[0].size() - 1, father)) {
            DFS(grid, visited, color, newSr, newSc, make_pair(sr, sc));
        }
        // down r + 1
        newSr = sr + 1;
        newSc = sc;
        if (isValid(newSr, newSc, grid.size() - 1, grid[0].size() - 1, father)) {
            DFS(grid, visited, color, newSr, newSc, make_pair(sr, sc));
        }
    }

public:
    bool containsCycle(vector<vector<char>> &grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        // get connected compontents
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!(visited[i][j])) {
                    have_cyle = false;
                    DFS(grid, visited, grid[i][j], i, j, {-1, -1});
                    if (have_cyle) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

void testContainsCycle(vector<vector<char>> grid) {
    Solution *sol = new Solution();
    cout << sol->containsCycle(grid) << endl;
}

int main() {
    vector<vector<char>> grid = {{'a', 'a', 'a', 'a'},
                                 {'a', 'b', 'b', 'a'},
                                 {'a', 'b', 'b', 'a'},
                                 {'a', 'a', 'a', 'a'}};
    testContainsCycle({{'a', 'a', 'a', 'a'},
                       {'a', 'b', 'b', 'a'},
                       {'a', 'b', 'b', 'a'},
                       {'a', 'a', 'a', 'a'}});

    testContainsCycle({{'a', 'a'}, {'a', 'a'}});

    testContainsCycle({{'a', 'b', 'b'}, {'b', 'z', 'b'}, {'b', 'b', 'a'}});
    return 0;
}
