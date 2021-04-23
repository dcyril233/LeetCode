#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return vector<int> {-1, -1};
        int low = lowerBound(nums, target);
        int high = upperBound(nums, target) - 1;
        if(low == nums.size() || nums[low] != target)
            return vector<int> {-1, -1};
        return vector<int> {low, high};
    }

    int lowerBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while(l < r) {
            mid = (l + r) / 2;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    int upperBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while(l < r) {
            mid = (l + r) / 2;
            if(nums[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {5,7,7,8,8,10};
        int target = 8;
        cout << Solution().searchRange(nums, target) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {5,7,7,8,8,10};
        int target = 6;
        cout << Solution().searchRange(nums, target) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> nums = {};
        int target = 0;
        cout << Solution().searchRange(nums, target) << endl;
    }
    return 0;
}
#endif