#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(auto& num : nums) {
            int pos = abs(num) - 1;
            if(nums[pos] > 0)
                nums[pos] = -nums[pos];
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) 
                ans.push_back(i+1);
        }
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{4,3,2,7,8,2,3,1};
        cout << Solution().findDisappearedNumbers(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums{1,1};
        cout << Solution().findDisappearedNumbers(nums) << endl;
    }
    return 0;
}
#endif