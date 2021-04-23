#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int countPrimes0(int n) {
        if(n <= 2) return 0;
        vector<int> prime(n, 1);
        int count = n - 2;
        for(int i = 2; i < n; ++i) {
            if(prime[i]) {
                for(int j = 2*i; j < n; j += i) {
                    if(prime[j]) {
                        prime[j] = 0; //质数的倍数不是质数
                        --count;
                    }
                }
            }
        }
        return count;
    }
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<int> prime(n, 1);
        int i = 3, sqrtn = sqrt(n), count = n / 2; //质因子不大于n的开方，偶数除了2一定不是质数，1是质数
        while(i <= sqrtn) {
            for(int j = i * i; j < n; j += 2*i) {
                if(prime[j]) {
                    prime[j] = 0;
                    --count;
                }
            }
            do {
                i += 2;
            } while(i <= sqrtn && !prime[i]); // 找到下一个质因子
        }
        return count;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl; 
    {
        int n = 10;
        cout << Solution().countPrimes(n) << endl;
    }
    cout << "2:" << endl; 
    {
        int n = 0;
        cout << Solution().countPrimes(n) << endl;
    }
    cout << "3:" << endl; 
    {
        int n = 1;
        cout << Solution().countPrimes(n) << endl;
    }
    return 0;
}
#endif