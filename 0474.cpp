#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int zero, one;
        for(int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            zero = one = 0;
            for(auto& ch:str) {
                if(ch == '0')
                    ++zero;
                else 
                    ++one;
            }
            for(int j = m; j >= zero; --j) {
                for(int k = n; k >= one; --k) {
                    dp[j][k] = max(dp[j][k], dp[j-zero][k-one]+1);
                }
            }
        }
        return dp[m][n];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:"<< endl;
    {
        vector<string> strs{"10","0001","111001","1","0"};
        int m = 5, n = 3;
        cout << Solution().findMaxForm(strs, m, n) << endl;
    }
    cout << " 2:"<< endl;
    {
        vector<string> strs{"10","0","1"};
        int m = 1, n = 1;
        cout << Solution().findMaxForm(strs, m, n) << endl;
    }
    return 0;
}
#endif