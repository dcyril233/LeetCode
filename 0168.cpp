#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n) {
            --n;
            char ch = n % 26 + 65;
            ans.insert(0, 1, ch);
            n = n / 26;
        }
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int n = 1;
        cout << Solution().convertToTitle(n) << endl;
    }
    cout << "2:" << endl;
    {
        int n = 28;
        cout << Solution().convertToTitle(n) << endl;
    }
    cout << "3:" << endl;
    {
        int n = 701;
        cout << Solution().convertToTitle(n) << endl;
    }
    return 0;
}
#endif