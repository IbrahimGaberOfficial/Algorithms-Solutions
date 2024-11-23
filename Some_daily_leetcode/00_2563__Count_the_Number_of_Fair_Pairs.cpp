#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    multiset<int> myMultiset;

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result = 0;
        for (int i = 0; i < nums.size(); i++) {
            myMultiset.insert(nums[i]);
        }
        for (std::multiset<int>::iterator it = myMultiset.begin(); it != myMultiset.end();
             it++) {
            int target = 0;
            std::multiset<int>::iterator next_it = std::next(it ,1);
            if (lower == upper) {
                 target = lower - *it;
                int count = std::count(next_it, myMultiset.end(), target);
                result += count;
            } else {
                for (int i = lower; i <= upper; i++) {
                    target = i - *it;
                    int count = std::count(next_it, myMultiset.end(), target);
                    result += count;
                }
            }
        }

        return result;
    }
    /* brute force solution TLE */
    // long long countFairPairs(vector<int>& nums, int lower, int upper) {
    //     if(lower == 0 && upper == 0)
    //         return 0;
    //     long long result = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for(int j = i + 1; j < nums.size(); j++) {
    //             if((nums[i] + nums[j] >= lower) && (nums[i] + nums[j] <= upper))
    //                 result++;
    //         }
    //     }
    //     return result;
    // }
};

void testCountFairPairs(vector<int> nums, int lower, int upper) {
    Solution* sol = new Solution();

    cout << sol->countFairPairs(nums, lower, upper) << endl;
}
int main() {
    testCountFairPairs({0, 1, 7, 4, 4, 5}, 3, 6);
    testCountFairPairs({1, 7, 9, 2, 5}, 11, 11);
    testCountFairPairs({0, 0, 0, 0, 0, 0}, 0, 0);
    return 0;
}
