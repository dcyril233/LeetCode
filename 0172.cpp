#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int trailingZeroes(int n) {
        // how many 5, 5*5, 5*5*5
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl; 
    {
        int n = 5;
        cout << Solution().trailingZeroes(n) << endl;
    }
    cout << "2:" << endl; 
    {
        int n = 3;
        cout << Solution().trailingZeroes(n) << endl;
    }
    cout << "3:" << endl; 
    {
        int n = 30; // 7
        cout << Solution().trailingZeroes(n) << endl;
    }
    return 0;
}
#endif