#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S > 1000) return 0;
        int n = nums.size();
        int dp1[2001] = {};
        int dp2[2001] = {};
        dp1[nums[0] + 1000] = 1;
        dp1[-nums[0] + 1000] += 1;
        for(int i = 1; i < n; ++i) {
            for(int sum = 0; sum <= 2000; ++sum) {
                if(dp1[sum] > 0) {
                    dp2[sum - nums[i]] += dp1[sum];
                    dp2[sum + nums[i]] += dp1[sum];
                }
            }
            swap(dp1, dp2);
            fill(dp2, dp2+2001, 0);
        }
        return dp1[S+1000];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{1, 1, 1, 1, 1};
        int S = 3;
        cout << Solution().findTargetSumWays(nums, S) << endl;
    }
    return 0;
}
#endif