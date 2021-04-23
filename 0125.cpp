#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0)
            return true;
        int start = 0, end = s.length() - 1, flag = 0;
        while (start < end) {
            int a = int(s[start]);
            int b = int(s[end]);
            if (a < 48 || (a >57 && a < 65) || (a > 90 && a < 97) || a > 122) {
                flag = 1;
                start += 1;
            }
            if (b < 48 || (b >57 && b < 65) || (b > 90 && b < 97) || b > 122) {
                flag = 1;
                end -= 1;
            }
            if (flag)
                flag = 0;
            else if ((a != b && (a < 65 || b < 65)) || (abs(a-b)%32 != 0 && a >= 65 && b >= 65))
                return false;
            else {
                start += 1;
                end -= 1;
            }
        }
        return true;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = " 3?8044''0''tt08?3";
        cout << Solution().isPalindrome(s) << endl;
    }
    return 0;
}
#endif