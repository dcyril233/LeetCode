#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0)
                    dp[i][j] = j;
                else if(j == 0)
                    dp[i][j] = i;
                else  {
                    if(word1[i-1] == word2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
                }
            }
        }
        return dp[n][m];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string word1 = "sea", word2 = "eat";
        cout << Solution().minDistance(word1, word2) << endl;
    }
    cout << " 2:" << endl;
    {
        string word1 = "leetcode", word2 = "etco";
        cout << Solution().minDistance(word1, word2) << endl;
    }
    return 0;
}
#endif