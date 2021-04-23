#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size() - 1, n = num2.size() - 1;
        string ans = "";
        int jinwei = 0;
        while(m >= 0 || n >= 0) {
            if(m >= 0 && n >= 0) {
                int sum = num1[m] + num2[n] + jinwei - 96;
                ans = to_string(sum % 10) + ans;
                jinwei = sum / 10;
                --m;
                --n;
            }
            else if(m >= 0) {
                int sum = num1[m] + jinwei - 48;
                ans = to_string(sum % 10) + ans;
                jinwei = sum / 10;
                --m;
            }
            else {
                int sum = num2[n] + jinwei - 48;
                ans = to_string(sum % 10) + ans;
                jinwei = sum / 10;
                --n;
            }
        }
        if(jinwei != 0)
            ans = to_string(jinwei) + ans;
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl; 
    {
        string num1 = "11", num2 = "123";
        cout << Solution().addStrings(num1, num2) << endl;
    }
    cout << "2:" << endl; 
    {
        string num1 = "456", num2 = "77";
        cout << Solution().addStrings(num1, num2) << endl;
    }
    cout << "3:" << endl; 
    {
        string num1 = "0", num2 = "0";
        cout << Solution().addStrings(num1, num2) << endl;
    }
    cout << "3:" << endl; 
    {
        string num1 = "1", num2 = "9";
        cout << Solution().addStrings(num1, num2) << endl;
    }
    return 0;
}
#endif