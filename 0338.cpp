#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for(int i = 1; i <= num; ++i) {
            dp[i] = (i & 1) ? dp[i-1] + 1 : dp[i >> 1]; 
        }
        return dp;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int num = 2;
        cout << Solution().countBits(num) << endl;
    }
    cout << "2:" << endl;
    {
        int num = 5;
        cout << Solution().countBits(num) << endl;
    }
    cout << "3:" << endl;
    {
        int num = 8; // 0,1,1,2,1,2,2,3,1
        cout << Solution().countBits(num) << endl;
    }
    return 0;
}
#endif