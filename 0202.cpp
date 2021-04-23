#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    int digitSquareSum(int n) {
        int sum = 0, temp;
        while(n) {
            int temp = n % 10;
            sum += temp * temp;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
            if(fast == 1)
                return 1;
        } while(slow != fast);
        return 0;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int n = 19;
        cout << Solution().isHappy(n) << endl;
    }
    cout << "2:" << endl;
    {
        int n = 2;
        cout << Solution().isHappy(n) << endl;
    }
    cout << "3:" << endl;
    {
        int n = 3;
        cout << Solution().isHappy(n) << endl;
    }
    return 0;
}
#endif