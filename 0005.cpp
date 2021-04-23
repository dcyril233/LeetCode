#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "")
            return "";
        int n = s.size();
        vector<vector<bool>> v(n, vector<bool> (n, true));
        int maxstart = 0, maxend = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(s[i] != s[i+1])
                v[i][i+1] = false;
            else {
                maxstart = i;
                maxend = i+1;
            }
        }
        for(int i = 2; i < n; ++i) {
            for(int j = 0; j < n - i; ++j) {
                if(v[j+1][j+i-1] == false || s[j] != s[j+i])
                    v[j][j+i] = false;
                else {
                    if(i > maxend-maxstart) {
                        maxstart = j;
                        maxend = j + i;
                    }
                }
            }
        }
        return s.substr(maxstart, maxend-maxstart+1);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = "aacabdkacaa";
        cout << Solution().longestPalindrome(s) << endl;
    }
    return 0;
}
#endif