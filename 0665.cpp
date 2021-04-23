#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() <= 2)
            return true;
        
        int prev1 = nums[0];
        int prev2 = nums[1];
        int count = (prev1 > prev2) ? 1 : 0;
        for(int i = 2; i < nums.size(); ++i) {
            if(prev2 > nums[i]) {
                count++;
                if(prev1 <= nums[i]) {
                    prev2 = nums[i];
                }
            }
            else {
                prev1 = prev2;
                prev2 = nums[i];
            }
            if(count > 1)
                break;
        }
        return count <= 1;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums {4,2,3}; //1
        cout << Solution().checkPossibility(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums {4,2,1}; //0
        cout << Solution().checkPossibility(nums) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums {3,4,2,3}; //0
        cout << Solution().checkPossibility(nums) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums {-1,4,2,3}; //1
        cout << Solution().checkPossibility(nums) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> nums {5,7,1,8}; // 1
        cout << Solution().checkPossibility(nums) << endl;
    }
    cout << " 6:" << endl;
    {
        vector<int> nums {2,3,3,2,2}; // 0
        cout << Solution().checkPossibility(nums) << endl;
    }
    cout << " 7:" << endl;
    {
        vector<int> nums {1,4,1,2}; // 1
        cout << Solution().checkPossibility(nums) << endl;
    }
    return 0;
}
#endif