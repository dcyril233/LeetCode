#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(n == 1)
            return s1[0] == s2[0];
        if(n == 2)
            return (s1[0] == s2[0] && s1[1] == s2[1]) || (s1[1] == s2[0] && s1[0] == s2[1]);
        char ch2 = s2[0];
        vector<int> index;
        for(int j = 0; j < n; ++j) {
            char ch1 = s1[j];
            if(ch1 == ch2)
                index.emplace_back(j);
        }
        for(auto &j:index) {
            bool result;
            if(j == 0) {
                bool result3 = isScramble(s1.substr(j+1, n-j-1), s2.substr(j+1, n-j-1));
                bool result4 = isScramble(s1.substr(0, j+1), s2.substr(0, j+1));
                result = (result3 && result4);
            }
            else if(j == n-1) {
                bool result1 = isScramble(s1.substr(j, n-j), s2.substr(0, n-j));
                bool result2 = isScramble(s1.substr(0, j), s2.substr(n-j, j));
                result = (result1 && result2);
            }
            else {
                bool result1 = isScramble(s1.substr(j, n-j), s2.substr(0, n-j));
                bool result2 = isScramble(s1.substr(0, j), s2.substr(n-j, j));
                bool result3 = isScramble(s1.substr(j+1, n-j-1), s2.substr(j+1, n-j-1));
                bool result4 = isScramble(s1.substr(0, j+1), s2.substr(0, j+1));
                result = (result1 && result2) || (result3 && result4);
            }
            if(result)
                return true;
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s1 = "great";
        string s2 = "rgeat";
        cout << Solution().isScramble(s1, s2) << endl;
    }
    cout << " 2:" << endl;
    {
        string s1 = "abcde";
        string s2 = "caebd";
        cout << Solution().isScramble(s1, s2) << endl;
    }
    cout << " 3:" << endl;
    {
        string s1 = "abca";
        string s2 = "caba";
        cout << Solution().isScramble(s1, s2) << endl;
    }
    cout << " 4:" << endl;
    {
        string s1 = "abcdbdacbdac";
        string s2 = "bdacabcdbdac";
        cout << Solution().isScramble(s1, s2) << endl;
    }
    cout << " 5:" << endl;
    {
        string s1 = "abcd";
        string s2 = "bcad";
        cout << Solution().isScramble(s1, s2) << endl;
    }
    return 0;
}
#endif

