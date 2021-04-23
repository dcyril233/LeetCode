#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        int first = 1;
        int second = 2;
        int result;
        for(int i = 2; i < n; ++i) {
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int n = 3;
        cout << Solution().climbStairs(n) << endl;
    }
    return 0;
}
#endif