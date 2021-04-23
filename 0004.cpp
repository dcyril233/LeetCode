#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;
        int halfLen = (m + n + 1) / 2;
        int i, j;
        double median;
        int medianLeft, medianRight;
        while(low <= high) {
            i = (low + high) / 2;
            j = halfLen - i;
            if(i < m && nums2[j-1] > nums1[i])
                low = i + 1;
            else if(i > 0 && nums1[i-1] > nums2[j])
                high = i - 1;
            else {
                if(i == 0) medianLeft = nums2[j-1];
                else if(j == 0) medianLeft = nums1[i-1];
                else medianLeft = max(nums2[j-1], nums1[i-1]);

                if((m + n) % 2 == 1) {
                    median = medianLeft;
                    break;
                }

                if(i == m) medianRight = nums2[j];
                else if(j == n) medianRight = nums1[i];
                else medianRight = min(nums2[j], nums1[i]);

                median = (medianLeft + medianRight) / 2.0;
                break;
            }
        }
        return median;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums1 {1,3};
        vector<int> nums2 {2};
        cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums1 {1,2};
        vector<int> nums2 {3,4};
        cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums1 {0,0};
        vector<int> nums2 {0,0};
        cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums1 {};
        vector<int> nums2 {1};
        cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> nums1 {2};
        vector<int> nums2 {};
        cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    }
    return 0;
}
#endif