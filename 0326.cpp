#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool isPowerOfThree0(int n) {
        return fmod(log10(n) / log10(3), 1) == 0;
    }

    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl; 
    {
        int n = 27;
        cout << Solution().isPowerOfThree(n) << endl;
    }
    cout << "2:" << endl; 
    {
        int n = 9;
        cout << Solution().isPowerOfThree(n) << endl;
    }
    cout << "3:" << endl; 
    {
        int n = 45; 
        cout << Solution().isPowerOfThree(n) << endl;
    }
    return 0;
}
#endif