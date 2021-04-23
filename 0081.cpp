#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[l] == nums[mid])
                ++l;
            else {
                if(nums[l] < nums[mid]) {
                    if(target >= nums[l] && target < nums[mid])
                        r = mid;
                    else 
                        l = mid + 1;
                }
                else {
                    if(target > nums[mid] && target <= nums[r-1])
                        l = mid + 1;
                    else 
                        r = mid;
                }
            }
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {2,5,6,0,0,1,2};
        int target = 0;
        cout << Solution().search(nums, target) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {2,5,6,0,0,1,2};
        int target = 3;
        cout << Solution().search(nums, target) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> nums = {1};
        int target = 2;
        cout << Solution().search(nums, target) << endl;
    }
    return 0;
}
#endif