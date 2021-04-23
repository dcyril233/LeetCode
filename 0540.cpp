#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while(l < r) {
            mid = (l + r) / 2;
            if(mid % 2 == 0) {
                if(nums[mid] == nums[mid+1])
                    l = mid + 2;
                else
                    r = mid;
            }
            else {
                if(nums[mid] == nums[mid-1])
                    l = mid + 1;
                else 
                    r = mid;
            }
        }
        return nums[l];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{1,1,2,3,3,4,4,8,8};
        cout << Solution().singleNonDuplicate(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums{3,3,7,7,10,11,11};
        cout << Solution().singleNonDuplicate(nums) << endl;
    }
    return 0;
}
#endif