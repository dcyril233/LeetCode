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

        vector<vector<bool>> dp (s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;

        for(int j = 1; j < p.size()+1; ++j) {
            if(p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }

        for(int i = 1; i < s.size()+1; ++i) {
            for(int j = 1; j < p.size()+1; ++j) {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }

        return dp[s.size()][p.size()];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = "aa";
        string p = "a";
        cout << Solution().isMatch(s, p) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "aa";
        string p = "*";
        cout << Solution().isMatch(s, p) << endl;
    }
    cout << " 3:" << endl;
    {
        string s = "cb";
        string p = "?a";
        cout << Solution().isMatch(s, p) << endl;
    }
    cout << " 4:" << endl;
    {
        string s = "adceb";
        string p = "*a*b";
        cout << Solution().isMatch(s, p) << endl;
    }
    cout << " 5:" << endl;
    {
        string s = "acdcb";
        string p = "a*c?b";
        cout << Solution().isMatch(s, p) << endl;
    }
    return 0;
}
#endif