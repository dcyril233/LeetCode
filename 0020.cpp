#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.emplace(s[i]);
            }
            else {
                if(stk.empty())
                    return false;
                if(s[i] == ')') {
                    if(stk.top() == '(')
                        stk.pop();
                    else 
                        return false;
                }
                else if(s[i] == ']') {
                    if(stk.top() == '[')
                        stk.pop();
                    else 
                        return false;
                }
                else 
                    if(stk.top() == '{')
                        stk.pop();
                    else 
                        return false;
            }
        }
        return stk.empty();
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = "()";
        cout << Solution().isValid(s) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "()[]{}";
        cout << Solution().isValid(s) << endl;
    }
    cout << " 3:" << endl;
    {
        string s = "(]";
        cout << Solution().isValid(s) << endl;
    }
    cout << " 4:" << endl;
    {
        string s = "([)]";
        cout << Solution().isValid(s) << endl;
    }
    cout << " 5:" << endl;
    {
        string s = "{[]}";
        cout << Solution().isValid(s) << endl;
    }
    return 0;
}
#endif