#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        long long powerOfTwo = 1;
        int copy = num;
        while(copy) {
            powerOfTwo *= 2;
            copy >>= 1;
        }
        return num ^ (powerOfTwo-1);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int num = 5;
        cout << Solution().findComplement(num) << endl;
    }
    cout << "2:" << endl;
    {
        int num = 1;
        cout << Solution().findComplement(num) << endl;
    }
    return 0;
}
#endif