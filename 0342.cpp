#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & (n-1)) && (n & 1431655765);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int n = 16;
        cout << Solution().isPowerOfFour(n) << endl;
    }
    cout << "2:" << endl;
    {
        int n = 5;
        cout << Solution().isPowerOfFour(n) << endl;
    }
    cout << "3:" << endl;
    {
        int n = 1;
        cout << Solution().isPowerOfFour(n) << endl;
    }
    return 0;
}
#endif