#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int findMin0(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int>> stk;
        int left = 0, right = n - 1;
        stk.emplace(0, n-1);
        int minnum = INT_MAX;
        while(!stk.empty()) {
            auto temp = stk.top();
            auto left = temp.first;
            auto right = temp.second;
            stk.pop();
            if(right - left <= 1)
                minnum = min(minnum, min(nums[left], nums[right]));
            else {
                int centre = (left + right) / 2;
                if(nums[left] < nums[right])
                    minnum = nums[left];
                else if(nums[left] < nums[centre])
                    stk.emplace(centre, right);
                else if(nums[left] == nums[centre]) {
                    stk.emplace(centre+1, right);
                    stk.emplace(left, centre-1);
                }
                else
                    stk.emplace(left, centre);
            }
        }
        return minnum;
    }

    int findMin1(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        int minNum = INT_MAX;
        while(l <= r) {
            mid = (l + r) / 2;
            if(nums[mid] < minNum)
                minNum = nums[mid];
            if(nums[l] == nums[mid])
                ++l;
            else if(nums[mid] <= nums[r])
                r = mid - 1;
            else {
                if(nums[l] < minNum)
                    minNum = nums[l];
                l = mid + 1;
            }
        }
        return minNum;
    }

    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;

        if(nums[l] < nums[r])
            return nums[l];
 
        while(l < r) {
            mid = (l + r) / 2;
            if(nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[r])
                r = mid;
            else {
                if(nums[r-1] > nums[r]) {
                    l = r;
                    break;
                }
                --r;
            }
        }
        return nums[l];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{10,1,10,10,10};
        cout << Solution().findMin(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums{1,3,5};
        cout << Solution().findMin(nums) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums{2,2,2,0,1};
        cout << Solution().findMin(nums) << endl;
    }
    return 0;
}
#endif