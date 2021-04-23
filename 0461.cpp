#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int dist = 0;
        while(diff) {
            dist += diff & 1;
            diff >>= 1;
        }
        return dist;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int x = 1, y = 4;
        cout << Solution().hammingDistance(x, y) << endl;
    }
    cout << "2:" << endl;
    {
        int x = 1, y = 4;
        cout << Solution().hammingDistance(x, y) << endl;
    }
    return 0;
}
#endif