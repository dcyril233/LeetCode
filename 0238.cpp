#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int last = nums[0], curr;
        int n = nums.size();
        vector<int> ans(n, 1);
        for(int i = 1; i < n; ++i) {
            curr = nums[i];
            ans[i] = last;
            last = last * curr;
        }
        last = nums[n-1];
        for(int i = n-2; i >= 0; --i) {
            curr = nums[i];
            ans[i] *= last;
            last = last * curr;
        }
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums{1,2,3,4};
        cout << Solution().productExceptSelf(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums{-1,1,0,-3,3};
        cout << Solution().productExceptSelf(nums) << endl;
    }
    return 0;
}
#endif