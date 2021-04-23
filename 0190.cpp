#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; ++i) {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        uint32_t n = 0b00000010100101000001111010011100;
        cout << Solution().reverseBits(n) << endl;
    }
    cout << "2:" << endl;
    {
        uint32_t n = 0b11111111111111111111111111111101;
        cout << Solution().reverseBits(n) << endl;
    }
    return 0;
}
#endif