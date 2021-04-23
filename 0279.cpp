#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int numSquares0(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j*j <= i; ++j) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
    int numSquares(int n) {
        if(n == 0) return 0;
        static vector<int> dp({0});
        while(dp.size() <= n) {
            int m = dp.size();
            int num = INT_MAX;
            for(int j = 1; j*j <= m; ++j) {
                num = min(num, dp[m-j*j] + 1);
            }
            dp.push_back(num);
        }
        return dp[n];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:"<< endl;
    {
        int n = 12;
        cout << Solution().numSquares(n) << endl;
    }
    cout << " 2:" << endl;
    {
        int n = 13;
        cout << Solution().numSquares(n) << endl;
    }
    return 0;
}
#endif