#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {

    vector<int> grabKNum(vector<int>& num, int k) {
        int n = num.size();
        int subtract = n - k;
        vector<int> output;
        for(int i = 0; i < n; ++i) {
            int curr = num[i];
            while(!output.empty() && output.back() < curr && subtract > 0) {
                output.pop_back();
                subtract--;
            }
            output.push_back(curr);
        }
        for(int i = 0; i < subtract; ++i)
            output.pop_back();
        return output;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        int curr, mode;
        int p, q;
        p = q = 0;
        while(p < nums1.size() || q < nums2.size()) {
            if(p == nums1.size())
                mode = 2;
            else if(q == nums2.size())
                mode = 1;
            else {
                int tempP = p;
                int tempQ = q;
                while(nums1[tempP] == nums2[tempQ] && tempP < nums1.size() - 1 && tempQ < nums2.size() - 1) {
                    tempP++;
                    tempQ++;
                }
                if(nums1[tempP] > nums2[tempQ])
                    mode = 1;
                else if(nums1[tempP] < nums2[tempQ])
                    mode = 2;
                else if(tempP == nums1.size() - 1)
                    mode = 2;
                else
                    mode = 1;
            }
            switch (mode) {
                case 1: {
                    curr = nums1[p];
                    p++;
                    break;
                }
                case 2: {
                    curr = nums2[q];
                    q++;
                    break;
                }
            }
            output.push_back(curr);
        }
        return output;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> maxv, temp;
        for(int i = 0; i <= k; ++i) {
            if(i <= nums1.size() && k - i <= nums2.size()) {
                auto temp1 = grabKNum(nums1, i);
                auto temp2 = grabKNum(nums2, k - i);
                temp = merge(temp1, temp2);
                if(temp > maxv)
                    maxv = temp;
            }
        }
        return maxv;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums1 = {3, 4, 6, 5};
        vector<int> nums2 = {9, 1, 2, 5, 8, 3};
        int k = 5;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums1 = {6, 7};
        vector<int> nums2 = {6, 0, 4};
        int k = 5;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums1 = {3, 9};
        vector<int> nums2 = {8, 9};
        int k = 3;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums1 = {9,5,6,2,4,3,6,2};
        vector<int> nums2 = {5,7,6,2,2,1,3,0,2,8,9,7,7,3,2,2,9,4,5,1};
        int k = 28;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> nums1 = {2,5,6,4,4,0};
        vector<int> nums2 = {7,3,8,0,6,5,7,6,2};
        int k = 15;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    return 0;
}
#endif