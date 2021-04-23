#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty())
            return false;
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j]) {
                    if (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())
                        dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

#ifdef LEETCODE
int main() {
    string s = "applepenapple";
    vector<string> wordDict {"apple", "pen"};
    cout << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}
#endif