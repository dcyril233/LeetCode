#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int maxLen = 0;
        int len, index;
        int p, q;

        for(int i = 0; i < d.size(); ++i) {
            auto temp = d[i];
            len = 0;
            p = 0;
            q = 0;
            while(p < s.size() && q < temp.size()) {
                if(s[p] == temp[q]) {
                    len++;
                    p++;
                    q++;
                }
                else
                    p++;
            }
            if(q == temp.size()) {
                if(len > maxLen) {
                    maxLen = len;
                    index = i;
                }
                else if(len == maxLen && d[i] < d[index])
                    index = i;
            }
        }
        return maxLen == 0 ? "" : d[index];
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string s = "abpcplea";
        vector<string> d {"ale","apple","monkey","plea"};
        cout << Solution().findLongestWord(s, d) << endl;
    }
    cout << "2:" << endl;
    {
        string s = "abpcplea";
        vector<string> d {"a","b","c"};
        cout << Solution().findLongestWord(s, d) << endl;
    }
    cout << "3:" << endl;
    {
        string s = "aewfafwafjlwajflwajflwafj";
        vector<string> d {"apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"};
        cout << Solution().findLongestWord(s, d) << endl;
    }
    return 0;
}
#endif