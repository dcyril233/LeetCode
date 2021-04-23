#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int rob0(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        if(nums.size() == 3) return max(nums[1], nums[2]+nums[0]);

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];

        for(int i = 3; i < nums.size(); ++i) {
            dp[i] = max(dp[i-3], dp[i-2]) + nums[i];
        }
        return max(dp[nums.size()-2], dp[nums.size()-1]);
    }

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        int prev2 = 0, prev1 = nums[0], curr;

        for(int i = 1; i < nums.size(); ++i) {
            curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {1,2,3,1};
        cout << Solution().rob(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {2,7,9,3,1};
        cout << Solution().rob(nums) << endl;
    }
    return 0;
}
#endif