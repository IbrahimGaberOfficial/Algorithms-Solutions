#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // int differenceOfSums(int n, int m)
    // {
    //     int num1 = 0, num2 = 0;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         if (i % m == 0)
    //         { // divisable by m
    //             num2 += i;
    //         }
    //         else
    //         { // not divisable by m
    //             num1 += i;
    //         }
    //     }
    //     return num1 - num2;
    // }
    //// Better version
    int differenceOfSums(int n, int m)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % m == 0)
            { // divisable by m
                sum -= i;
            }
            else
            { // not divisable by m
                sum += i;
            }
        }
        return sum;
    }
};
void TestSol(int n, int m)
{
    Solution sol = Solution();
    auto result = sol.differenceOfSums(n, m);
    cout << "for n = " << n << " | m = " << m << " ==> " << result << endl;
};
int main()
{
    TestSol(10, 3);
    TestSol(5, 6);
    TestSol(5, 1);

    return 0;
}