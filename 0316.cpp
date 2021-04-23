#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string removeDuplicateLetters(string s) {
        array<int, 26> letter, num;
        letter.fill(0);
        num.fill(0);
        string stk;

        for(char ch : s) {
            num[ch - 'a']++;
        }

        for(char ch : s) {
            if(!letter[ch - 'a']) {
                while(!stk.empty() && stk.back() > ch) {
                    if(num[stk.back() - 'a'] > 0) {
                        letter[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    }
                    else {
                        break;
                    }
                }
                letter[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch - 'a']--;
        }
        return stk;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = "bcabc";
        cout << Solution().removeDuplicateLetters(s) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "cbacdcbc";
        cout << Solution().removeDuplicateLetters(s) << endl;
    }
    return 0;
}
#endif