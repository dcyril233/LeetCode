#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 2) return vector<int> {0, 1};
        unordered_map<int, int> exist;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            if(exist.find(target - nums[i]) != exist.end()) {
                ans.push_back(exist[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            exist[nums[i]] = i;
        }
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums {2,7,11,15};
        int target = 9;
        cout << Solution().twoSum(nums, target) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums {3,2,4};
        int target = 6;
        cout << Solution().twoSum(nums, target) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums {3,3};
        int target = 6;
        cout << Solution().twoSum(nums, target) << endl;
    }
    return 0;
}
#endif