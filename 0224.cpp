#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int inputOrder(char ch) {
        int output;
        switch (ch) {
            case '+' : output = 1;
                       break;
            case '-' : output = 1;
                       break;
            case '*' : output = 2;
                       break;
            case '/' : output = 2;
                       break;
            case '^' : output = 3;
                       break;
            default: output = 0;
        }
        return output;
    }

    int doOp(char op, int a, int b) {
        switch(op) {
        case '+' : return a+b;
                   break;
        case '-' : return a-b;
                   break;
        case '*' : return a*b;
                   break;
        case '/' : return a/b;
                   break;
        case '^' : return pow(a, b);
                   break;
        default:
            throw std::runtime_error("unknown op");
        }
    }

    float calculate(string s) {
        stack<char> stk;
        vector<char> v;
        for (char &ch : s) {
            if (ch >= '0' && ch <= '9')
                v.push_back(ch);
            else if (ch == '(')
                stk.push(ch);
            else if (ch == ')') {
                while (stk.top() != '(') {
                        v.push_back(stk.top());
                        stk.pop();
                }
                stk.pop();
            }
            else {
                if (stk.empty())
                    stk.push(ch);
                else {
                    while (!stk.empty()) {
                        if (inputOrder(stk.top()) >= inputOrder(ch)) {
                            v.push_back(stk.top());
                            stk.pop();
                        }
                        else {
                            if (ch == '-')
                                v.push_back(0)
                            stk.push(ch);
                            break;
                        }
                    }
                }
            }
        }
        while (!stk.empty()) {
            v.push_back(stk.top());
            stk.pop();
        }

        stack<float> stk2;
        for (auto &ch : v) {
            if (ch >= '0' && ch <= '9') {
                float num = int(ch) - 48;
                stk2.push(num);
            } 
            else {
                float a = stk2.top();
                stk2.pop();
                float b = stk2.top();
                stk2.pop();
                stk2.push(doOp(ch, b, a));
            }
        }
        return stk2.top();
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string s = "3*(2+7)^4";
        cout << Solution().calculate(s) << endl;
    }
    return 0;
}
#endif