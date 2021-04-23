#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, count = 0;
        for(auto& num : nums) {
            if(count == 0) {
                ans = num;
                ++count;
            }
            else if(ans == num)
                ++count;
            else
                --count;
        }
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums{3,2,3};
        cout << Solution().majorityElement(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums{2,2,1,1,1,2,2};
        cout << Solution().majorityElement(nums) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> nums{3,3,4};
        cout << Solution().majorityElement(nums) << endl;
    }
    return 0;
}
#endif