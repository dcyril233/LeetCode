#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int twoSum = 0;
        for(auto& num : nums)
            twoSum ^= num;
        int index = 1;
        while(twoSum) {
            if(twoSum & 1) {
                break;
            }
            twoSum >>= 1;
            index <<= 1;
        }

        int num1 = 0, num2 = 0;
        for(auto& num : nums) {
            if(num & index)
                num1 ^= num;
            else 
                num2 ^= num;
        }
        return vector<int>{num1, num2};
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums{1,2,1,3,2,5};
        cout << Solution().singleNumber(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums{-1,0};
        cout << Solution().singleNumber(nums) << endl;
    }
    return 0;
}
#endif