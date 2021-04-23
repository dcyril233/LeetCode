#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int mySqrt0(int x) {
        if(x == 0) return 0;
        int l = 1, r = x, mid, sqrt;
        while(l <= r) {
            mid = l + (r - l) / 2;
            sqrt = x / mid;
            if(mid == sqrt)
                return sqrt;
            else if(mid < sqrt)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }

    int mySqrt(int x) {
        long a = x;
        while(a * a > x) {
            a = (a + x/a) / 2;
        }
        return a;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int x = 4;
        cout << Solution().mySqrt(x) << endl;
    }
    cout << "2:" << endl;
    {
        int x = 8;
        cout << Solution().mySqrt(x) << endl;
    }
    cout << "3:" << endl;
    {
        int x = 6;
        cout << Solution().mySqrt(x) << endl;
    }
    return 0;
}
#endif