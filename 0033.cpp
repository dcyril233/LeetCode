#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[l] == nums[mid])
                ++l;
            else if(nums[l] < nums[mid]) {
                if(target < nums[mid] && target >= nums[l])
                    r = mid - 1;
                else 
                    l = mid + 1;
            }
            else {
                if(target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
        }
        return -1;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{4,5,6,7,0,1,2};
        int target = 0;
        cout << Solution().search(nums, target) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums{4,5,6,7,0,1,2};
        int target = 3;
        cout << Solution().search(nums, target) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums{1};
        int target = 0;
        cout << Solution().search(nums, target) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums{5,1,3};
        int target = 5;
        cout << Solution().search(nums, target) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> nums{3,1};
        int target = 1;
        cout << Solution().search(nums, target) << endl;
    }
    return 0;
}
#endif