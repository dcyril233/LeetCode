#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void backTracking(string& s, vector<string>& wordDict, vector<string>& ans, int index, int n) {
        if(index == n) {
            ans.push_back(s.substr(0, s.size()-1));
            return;
        }
        for(int i = index; i < n; ++i) {
            if(find(wordDict.begin(), wordDict.end(), s.substr(index, i-index+1)) != wordDict.end()) {
                s.insert(i+1, " ");
                backTracking(s, wordDict, ans, i+2, n+1);
                s.erase(i+1, 1);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<string> ans;
        backTracking(s, wordDict, ans, 0, n);
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:"<< endl;
    {
        string s = "catsanddog";
        vector<string> wordDict {"cat", "cats", "and", "sand", "dog"};
        cout << Solution().wordBreak(s, wordDict) << endl;
    }
    cout << " 2:"<< endl;
    {
        string s = "pineapplepenapple";
        vector<string> wordDict {"apple","pen","applepen","pine","pineapple"};
        cout << Solution().wordBreak(s, wordDict) << endl;
    }
    cout << " 3:"<< endl;
    {
        string s = "catsandog";
        vector<string> wordDict {"cats","dog","sand","and","cat"};
        cout << Solution().wordBreak(s, wordDict) << endl;
    }
    return 0;
}
#endif