#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1, n = b.size() - 1;
        string ans;
        int jinwei = 0;
        while(m >= 0 || n >= 0) {
            if(m >= 0 && n >= 0) {
                int sum = jinwei + a[m] + b[n] - 96;
                jinwei = sum / 2;
                ans = to_string(sum % 2) + ans;
                --m;
                --n;
            }
            else if(m >= 0) {
                int sum = jinwei + a[m] - 48;
                jinwei = sum / 2;
                ans = to_string(sum % 2) + ans;
                --m;
            }
            else {
                int sum = jinwei + b[n] - 48;
                jinwei = sum / 2;
                ans = to_string(sum % 2) + ans;
                --n;
            }
        }
        if(jinwei == 1)
            ans = "1" + ans;
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string a = "11", b = "1";
        cout << Solution().addBinary(a, b) << endl;
    }
    cout << "2:" << endl;
    {
        string a = "1010", b = "1011";
        cout << Solution().addBinary(a, b) << endl;
    }
    return 0;
}
#endif