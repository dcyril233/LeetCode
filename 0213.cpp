#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int last12 = 0, last11 = nums[0], curr1;
        int last22 = 0, last21 = nums[1], curr2;
        for(int i = 1; i < n; ++i) {
            if(i < n-1) {
                curr1 = max(last11, last12+nums[i]);
                last12 = last11;
                last11 = curr1;
            }
            if(i > 1) {
                curr2 = max(last21, last22+nums[i]);
                last22 = last21;
                last21 = curr2;
            }
        }
        return max(curr1, curr2);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums {2,3,2};
        cout << Solution().rob(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums {1,2,3,1};
        cout << Solution().rob(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums {0};
        cout << Solution().rob(nums) << endl;
    }
    return 0;
}
#endif