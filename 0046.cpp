#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void backTracking(vector<int>& nums, int level, vector<vector<int>>& ans) {
        if(level == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for(int i = level; i < nums.size(); ++i) {
            swap(nums[i], nums[level]);
            backTracking(nums, level+1, ans);
            swap(nums[i], nums[level]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backTracking(nums, 0, ans);
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{1,2,3};
        cout << Solution().permute(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums{0,1};
        cout << Solution().permute(nums) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums{1};
        cout << Solution().permute(nums) << endl;
    }
    return 0;
}
#endif