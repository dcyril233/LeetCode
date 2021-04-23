#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    static inline size_t FindKImpl(vector<int> &nums, size_t b, size_t e, size_t k) {
        auto CmpFunc = std::greater<int>();
        switch(e-b) {
            case 0: {
                return nums[b];
            }
            case 1: {
                if(!CmpFunc(nums[b], nums[e]))
                    std::swap(nums[b], nums[e]);
                return nums[k-1];
            }
            default: {
                int pivot = nums[b];
                int l = b;
                int r = e;
                while(l < r) {
                    while(l < r && pivot >= nums[r])
                        r--;
                    nums[l] = nums[r];
                    while(l < r && nums[l] >= pivot)
                        l++;
                    nums[r] = nums[l];
                }
                nums[l] = pivot;
                if(l == k-1)
                    return pivot;
                else if(l < k-1)
                    return FindKImpl(nums, l+1, e, k);
                else
                    return FindKImpl(nums, b, l-1, k);
            }
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return FindKImpl(nums, 0, nums.size()-1, k);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{3,2,1,5,6,4};
        int k = 2;
        cout << Solution().findKthLargest(nums, k) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums{3,2,3,1,2,4,5,5,6};
        int k = 4;
        cout << Solution().findKthLargest(nums, k) << endl;
    }
    return 0;
}
#endif