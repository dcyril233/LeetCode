#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (auto &p : nums) {
            single = single ^ p;
        }
        return single;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{4,1,2,1,2};
        cout << Solution().singleNumber(nums) << endl;
    }
    return 0;
}
#endif