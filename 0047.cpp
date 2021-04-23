#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void backTracking(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if(index == nums.size() - 1) {
            ans.emplace_back(nums);
            return;
        }
        set<int> exist;
        for(int i = index; i < nums.size(); ++i) {
            if(((i != index) && (nums[index] == nums[i])) || exist.find(nums[i]) != exist.end()) {
                continue;
            }
            swap(nums[i], nums[index]);
            backTracking(nums, ans, index+1);
            swap(nums[i], nums[index]);
            if(nums[index] != nums[i])
                exist.insert(nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        backTracking(nums, ans, 0);
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums {1,1,2};
        cout << Solution().permuteUnique(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums {1,2,3};
        cout << Solution().permuteUnique(nums) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums {2,2,1,1};
        cout << Solution().permuteUnique(nums) << endl;
    }
    return 0;
}
#endif