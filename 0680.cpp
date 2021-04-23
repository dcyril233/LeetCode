#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    bool validPHelper(string & s, int l, int r, int count) {
        if(count > 1)
            return false;
        if(l >= r)
            return true;
        if(s[l] == s[r])
            return validPHelper(s, ++l, --r, count);
        else {
            bool flag1 = validPHelper(s, l+1, r, count+1);
            bool flag2 = validPHelper(s, l, r-1, count+1);
            return flag1 || flag2;
        }
    }
public:
    bool validPalindrome(string s) {
        if(s.size() < 3)
            return true;
        int l = 0, r = s.size() - 1;
        int count = 0;
        return validPHelper(s, l, r, count);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string s = "aba";
        cout << Solution().validPalindrome(s) << endl;
    }
    cout << "2:" << endl;
    {
        string s = "abca";
        cout << Solution().validPalindrome(s) << endl;
    }
    cout << "3:" << endl;
    {
        string s = "abdca";
        cout << Solution().validPalindrome(s) << endl;
    }
    cout << "4:" << endl;
    {
        string s = "ebcbbececabbacecbbcbe";
        cout << Solution().validPalindrome(s) << endl;
    }
    cout << "5:" << endl;
    {
        string s = "cbbcc";
        cout << Solution().validPalindrome(s) << endl;
    }
    return 0;
}
#endif