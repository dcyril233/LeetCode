#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int dp = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(dp <= 0)
                dp = nums[i];
            else
                dp += nums[i];
            sum = max(sum, dp);
        }
        return sum;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector nums {-2,1,-3,4,-1,2,1,-5,4};
        cout << Solution().maxSubArray(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector nums {1};
        cout << Solution().maxSubArray(nums) << endl;
    }
    return 0;
}
#endif