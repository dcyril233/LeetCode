#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int lengthOfLIS0(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<int> dp(n, 1);
        int longLen = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            longLen = max(longLen, dp[i]);
        }
        return longLen;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < n; ++i) {
            if(nums[i] > dp.back())
                dp.push_back(nums[i]);
            else {
                auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
                *itr = nums[i];
            }
        }
        return dp.size();
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:"<< endl;
    {
        vector<int> nums {10,9,2,5,3,7,101,18};
        cout << Solution().lengthOfLIS(nums) << endl;
    }
    cout << " 2:"<< endl;
    {
        vector<int> nums {0,1,0,3,2,3};
        cout << Solution().lengthOfLIS(nums) << endl;
    }
    cout << " 3:"<< endl;
    {
        vector<int> nums {7,7,7,7,7,7,7};
        cout << Solution().lengthOfLIS(nums) << endl;
    }
    return 0;
}
#endif