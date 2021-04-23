#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool canPartition0(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i) {
            int value = nums[i-1];
            for(int j = target; j >= value; --j)
                dp[j] = dp[j] || dp[j-value];
        }
        return dp[target];
    }
    bool canPartition1(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            int value = nums[i-1];
            if(value == target)
                return true;
            for(int j = target; j >= value; --j)
                dp[j] = dp[j] || dp[j-value];
            if(dp[target])
                return true;
        }
        return dp[target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)
            return false;

        int target = sum/2;

        vector<char> dp(target+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i) {
            int value = nums[i-1];
            if(value <= target) {
                if(dp[target-value])
                    return true;
                for(int j = target-1; j >= value; --j)
                    dp[j] |= dp[j-value];
            }
        }
        return dp[target];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:"<< endl;
    {
        vector<int> nums {1,5,11,5};
        cout << Solution().canPartition(nums) << endl;
    }
    cout << " 2:"<< endl;
    {
        vector<int> nums {1,2,3,5};
        cout << Solution().canPartition(nums) << endl;
    }
    cout << " 2:"<< endl;
    {
        vector<int> nums {2,2,3,5};
        cout << Solution().canPartition(nums) << endl;
    }
    return 0;
}
#endif