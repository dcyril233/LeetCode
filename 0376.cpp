#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    // dp
    int wiggleMaxLength0(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<pair<int, int>> dp(n, pair<int, int>{0, 0});
        dp[0].first = 1, dp[0].second = 1;
        int longlen = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j])
                    dp[i].first = max(dp[i].first, dp[j].second + 1);
                else if(nums[i] < nums[j])
                    dp[i].second = max(dp[i].second, dp[j].first + 1);
            }
            longlen = max({longlen, dp[i].first, dp[i].second});
        }
        return longlen;
    }
    // linear dp
    int wiggleMaxLength1(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        vector<int> up(n, 0), down(n, 0);
        up[0] = 1, down[0] = 1;
        for(int i = 1; i < n; ++i) {
            if(nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if(nums[i] < nums[i-1]) {
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            }
            else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[n-1], down[n-1]);
    }
    // Space-Optimized linear dp
    int wiggleMaxLength2(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        int up = 1, down = 1;
        for(int i = 1; i < n; ++i) {
            if(nums[i] > nums[i-1])
                up = down + 1;
            else if(nums[i] < nums[i-1])
                down = up + 1;
        }
        return max(up, down);
    }
    // version from zhu
    int wiggleMaxLength(vector<int>& nums) {
        int len = 2;
        int i = 1;
        while(true) {
            if(i >= nums.size())
                return 1;
            if(nums[i] == nums[0])
                i++;
            else
                break;
        }
        bool inc = nums[i] > nums[0];

        while(++i < nums.size()) {
            if((inc && nums[i] < nums[i-1]) || (!inc && nums[i] > nums[i-1])) {
                len++;
                inc = !inc;
            }
        }
        return len;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{1,7,4,9,2,5};
        cout << Solution().wiggleMaxLength(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums{1,17,5,10,13,15,10,5,16,8};
        cout << Solution().wiggleMaxLength(nums) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums{1,2,3,4,5,6,7,8,9};
        cout << Solution().wiggleMaxLength(nums) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums{3,3,3,2,5};
        cout << Solution().wiggleMaxLength(nums) << endl;
    }
    return 0;
}
#endif