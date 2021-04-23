#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(nums[mid] >= target)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return l;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{1,3,5,6};
        int target = 5;
        cout << Solution().searchInsert(nums, target) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums{1,3,5,6};
        int target = 2;
        cout << Solution().searchInsert(nums, target) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums{1,3,5,6};
        int target = 7;
        cout << Solution().searchInsert(nums, target) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums{1,3,5,6};
        int target = 0;
        cout << Solution().searchInsert(nums, target) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> nums{1};
        int target = 0;
        cout << Solution().searchInsert(nums, target) << endl;
    }
    return 0;
}
#endif