#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k)
            return "0";
        string output;
        int n = num.size();
        for(int i = 0; i < n; ++i) {
            char ch = num[i];
            while(!output.empty() && output.back() > ch && k > 0) {
                output.pop_back();
                k--;
           }
           if((!output.empty() || ch != '0'))
                output.push_back(ch);
        }
        if(output == "")
            output = "0";
        else
            output = output.substr(0, output.size() - k);
        return output;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string num = "1432219";
        int k = 3;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    cout << " 2:" << endl;
    {
        string num = "10200";
        int k = 1;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    cout << " 3:" << endl;
    {
        string num = "10";
        int k = 2;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    cout << " 4:" << endl;
    {
        string num = "112";
        int k = 1;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    cout << " 5:" << endl;
    {
        string num = "9999999999991";
        int k = 8;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    cout << " 5:" << endl;
    {
        string num = "1173";
        int k = 2;
        cout << Solution().removeKdigits(num, k) << endl;
    }
    return 0;
}
#endif