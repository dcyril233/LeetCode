#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int longestValidParentheses0(string s) {
        if(s == "" or s.size() == 1)
            return 0;
        int longlen = 0;
        int n = s.size();
        vector<int> v(n, 0);

        for(int i = 1; i < n; ++i) {
            if(s[i] == ')') {
                if(s[i-1] == '(') {
                    v[i] = (i >= 2 ? v[i-2] : 0) + 2;
                }
                else if(i - v[i-1] > 0 && s[i-v[i-1]-1] == '(') {
                    v[i] = (i > v[i-1]+1 ? v[i-v[i-1]-2] : 0) + v[i-1] + 2;
                }
            }
            longlen = max(longlen, v[i]);
        }
        return longlen;
    }
    
    int longestValidParentheses1(string s) {
        if(s == "" or s.size() == 1)
            return 0;
        int longlen = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(')
                stk.push(i);
            else {
                if(stk.top() == -1 || s[stk.top()] == ')')
                    stk.push(i);
                else
                    stk.pop();
            }
            longlen = max(longlen, i-stk.top());
        }
        return longlen;
    }

    int longestValidParentheses(string s) {
        if(s == "" or s.size() == 1)
            return 0;
        int longlen = 0;
        int left = 0, right = 0;
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(')
                ++left;
            else
                ++right;
            if(left == right)
                longlen = max(longlen, 2*right);
            else if(right > left) {
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;
        for(int i = s.size()-1; i > -1 ; --i) {
            if(s[i] == '(')
                ++left;
            else
                ++right;
            if(left == right)
                longlen = max(longlen, 2*left);
            else if(left > right) {
                left = 0;
                right = 0;
            }
        }
        return longlen;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = "(()())";
        cout << Solution().longestValidParentheses(s) << endl;
    }
    return 0;
}
#endif