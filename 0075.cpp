#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void sortColors0(vector<int>& nums) {
        int red = 0, white = 0, blue = nums.size() - 1;
        int temp;
        while(white <= blue) {
            if(nums[white] == 0) {
                nums[white] = nums[red];
                nums[red] = 0;
                ++red;
                ++white;
            }
            else if(nums[white] == 1)
                ++white;
            else {
                nums[white] = nums[blue];
                nums[blue] = 2;
                --blue;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        int second = nums.size()-1, zero = 0;
        for(int i = 0; i <= second; i++) {
            while (nums[i]==2 && i<second) swap(nums[i], nums[second--]);
            while (nums[i]==0 && i>zero) swap(nums[i], nums[zero++]);
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{2,0,2,1,1,0};
        Solution().sortColors(nums);
        cout << nums << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums{2,0,1};
        Solution().sortColors(nums);
        cout << nums << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums{0};
        Solution().sortColors(nums);
        cout << nums << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums{2,2,0,1,1};
        Solution().sortColors(nums);
        cout << nums << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> nums{2,0,1};
        Solution().sortColors(nums);
        cout << nums << endl;
    }
    return 0;
}
#endif