#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() == 0) {
            if(s.size() == 0)
                return true;
            else
                return false;
        }
        
        vector<vector<bool>> dp(s.size()+1, vector<bool> (p.size()+1, false));
        // initialize dp[0][j] and dp[i][0]
        dp[0][0] = true;
        for(int j = 1; j < p.size()+1; ++j) {
            if(j % 2 == 0 && p[j-1] == '*' && dp[0][j-2])
                dp[0][j] = true;
        }

        for(int i = 1; i < s.size()+1; ++i) {
            for(int j = 1; j < p.size()+1; ++j) {
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*' && j > 1) {
                    dp[i][j] = dp[i][j-1] || dp[i][j-2];
                    if(s[i-1]==p[j-2] || p[j-2] == '.')
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = "aaa";
        string p = "ab*a*c*a";
        cout << Solution().isMatch(s, p) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "aa";
        string p = "a*";
        cout << Solution().isMatch(s, p) << endl;
    }
    cout << " 3:" << endl;
    {
        string s = "ab";
        string p = ".*";
        cout << Solution().isMatch(s, p) << endl;
    }
    cout << " 4:" << endl;
    {
        string s = "aab";
        string p = "c*a*b";
        cout << Solution().isMatch(s, p) << endl;
    }
    cout << " 5:" << endl;
    {
        string s = "mississippi";
        string p = "mis*is*p*.";
        cout << Solution().isMatch(s, p) << endl;
    }
    cout << " 5:" << endl;
    {
        string s = "aaa";
        string p = ".*";
        cout << Solution().isMatch(s, p) << endl;
    }
    return 0;
}
#endif