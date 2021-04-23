#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        static vector<int> dp {2, 3};
        if(dp.size()+1 < n) {
            int begin = dp.size();
            for(int i = begin+2; i <= n; ++i) {
                int accu = i;
                for(int j = 2; j <= i / 2; ++j){
                    int temp = dp[j-2] * dp[i-j-2];
                    accu = max(temp, accu);
                }
                dp.push_back(accu);
            }
        }
        return dp[n-2];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int n = 2;
        cout << Solution().integerBreak(n) << endl;
    }
    cout << " 2:" << endl;
    {
        int n = 10;
        cout << Solution().integerBreak(n) << endl;
    }
    cout << " 3:" << endl;
    {
        int n = 11;
        cout << Solution().integerBreak(n) << endl;
    }
    return 0;
}
#endif