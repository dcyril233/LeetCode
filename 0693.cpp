#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return (n & (n >> 1)) == 0 && ((n & (n >> 2)) == (n >> 2));  
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int n = 5;
        cout << Solution().hasAlternatingBits(n) << endl;
    }
    cout << "2:" << endl;
    {
        int n = 7;
        cout << Solution().hasAlternatingBits(n) << endl;
    }
    cout << "3:" << endl;
    {
        int n = 11;
        cout << Solution().hasAlternatingBits(n) << endl;
    }
    cout << "4:" << endl;
    {
        int n = 10;
        cout << Solution().hasAlternatingBits(n) << endl;
    }
    cout << "5:" << endl;
    {
        int n = 3;
        cout << Solution().hasAlternatingBits(n) << endl;
    }
    cout << "6:" << endl;
    {
        int n = 4;
        cout << Solution().hasAlternatingBits(n) << endl;
    }
    return 0;
}
#endif