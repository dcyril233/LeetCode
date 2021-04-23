#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1; i < n; ++i) {
            if(s[i] == '0') {
                if((s[i-1] == '0' || s[i-1] > '2'))
                    return 0;
                else
                    dp[i+1] = dp[i-1];
            }
            else {
                if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))
                    dp[i+1] = dp[i] + dp[i-1];
                else 
                    dp[i+1] = dp[i];
            }
        }
        return dp[n];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:"<< endl;
    {
        string s = "12";
        cout << Solution().numDecodings(s) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "226";
        cout << Solution().numDecodings(s) << endl;
    }
    cout << " 3:" << endl;
    {
        string s = "0";
        cout << Solution().numDecodings(s) << endl;
    }
    cout << " 4:" << endl;
    {
        string s = "06";
        cout << Solution().numDecodings(s) << endl;
    }
    cout << " 5:" << endl;
    {
        string s = "27";
        cout << Solution().numDecodings(s) << endl;
    }
    cout << " 6:" << endl;
    {
        string s = "2101";
        cout << Solution().numDecodings(s) << endl;
    }
    cout << " 7:" << endl;
    {
        string s = "1123";
        cout << Solution().numDecodings(s) << endl;
    }
    return 0;
}
#endif