#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool judgeSquareSum0(int c) {
        vector<int> cache;
        for(int i = 0; i < 46341 && i*i <= c; ++i)
            cache.emplace_back(i*i);
        
        int r = 0, l = cache.size() - 1;
        while(r <= l) {
            if(cache[r] == c - cache[l])
                return true;
            else if(cache[r] < c - cache[l])
                r++;
            else 
                l--;
        }
        return false;
    }

    bool judgeSquareSum1(int c) {
        for(int a = 0; a < 46341 && a*a <= c; ++a) {
            int b = c - a * a;
            int i = 1, sum = 0;
            while(sum < b) {
                sum += i;
                i += 2;
            }
            if(sum == b)
                return true;
        }
        return false;
    }

    bool judgeSquareSum(int c) {
        int i = floor(sqrt(c));
        if(i*i == c)
            return true;
        int j = 1;
        while(j <= i) {
            if(i*i == c - j*j)
                return true;
            else if(i*i < c - j*j)
                j++;
            else 
                i--;
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int c = 5;
        cout << Solution().judgeSquareSum(c) << endl;
    }
    cout << "2:" << endl;
    {
        int c = 3;
        cout << Solution().judgeSquareSum(c) << endl;
    }
    cout << "3:" << endl;
    {
        int c = 4;
        cout << Solution().judgeSquareSum(c) << endl;
    }
    cout << "4:" << endl;
    {
        int c = 2;
        cout << Solution().judgeSquareSum(c) << endl;
    }
    cout << "5:" << endl;
    {
        int c = 2147482647;
        cout << Solution().judgeSquareSum(c) << endl;
    }
    return 0;
}
#endif