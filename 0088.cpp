#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void merge0(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1;
        int q = n - 1;
        int index = m + n - 1;
        while(p >= 0 && q >= 0) {
            if(nums1[p] < nums2[q]) {
                nums1[index] = nums2[q];
                q--;
            }
            else {
                nums1[index] = nums1[p];
                p--;
            }
            index--;
        }
        while(q >= 0) {
            nums1[index] = nums2[q];
            q--;
            index--;
        }
        return;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m-- + n-- - 1;
        while(m >= 0 && n >= 0) {
            nums1[index--] = (nums1[m] < nums2[n]) ? nums2[n--] : nums1[m--];
        }
        while(n >= 0) {
            nums1[index--] = nums2[n--];
        }
        return;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums1 = {1,2,3,0,0,0};
        vector<int> nums2 = {2,5,6};
        int m = 3;
        int n = 3;
        Solution().merge(nums1, m, nums2, n);
        cout << nums1 << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums1 = {4,5,6,0,0,0};
        vector<int> nums2 = {1,2,3};
        int m = 3;
        int n = 3;
        Solution().merge(nums1, m, nums2, n);
        cout << nums1 << endl;
    }
    return 0;
}
#endif