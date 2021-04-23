#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() < 3) return 0;
        vector<int> dp(n, 0);
        for(int i = 2; i < n; ++i) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                dp[i] = dp[i-1] + 1; 
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {1,2,3,4};
        cout << Solution().numberOfArithmeticSlices(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {1};
        cout << Solution().numberOfArithmeticSlices(nums) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> nums = {1,3,5,7,9};
        cout << Solution().numberOfArithmeticSlices(nums) << endl;
    }
    return 0;
}
#endif