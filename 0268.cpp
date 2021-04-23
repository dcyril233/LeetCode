#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            sum ^= (i+1);
            sum ^= nums[i];
        }
        return sum;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums{3,0,1};
        cout << Solution().missingNumber(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums{0,1};
        cout << Solution().missingNumber(nums) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> nums{9,6,4,2,3,5,7,0,1};
        cout << Solution().missingNumber(nums) << endl;
    }
    return 0;
}
#endif