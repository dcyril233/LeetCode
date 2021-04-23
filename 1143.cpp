#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:"<< endl;
    {
        string text1 = "abcde", text2 = "ace";
        cout << Solution().longestCommonSubsequence(text1, text2) << endl;
    }
    cout << " 2:"<< endl;
    {
        string text1 = "abc", text2 = "abc";
        cout << Solution().longestCommonSubsequence(text1, text2) << endl;
    }
    cout << " 3:"<< endl;
    {
        string text1 = "abc", text2 = "def";
        cout << Solution().longestCommonSubsequence(text1, text2) << endl;
    }
    return 0;
}
#endif