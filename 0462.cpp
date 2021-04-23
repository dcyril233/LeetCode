#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int minMoves20(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int increment, decrement, target=0;
        for(int i = 1; i < n; ++i) {
            increment = (nums[i] - nums[i-1]) * i;
            decrement = (nums[i] - nums[i-1]) * (n-i);
            if(increment <= decrement) {
                target = i;
            }
            else
                break;
        }
        int ans = 0;
        for(auto& num : nums)
            ans += abs(num - nums[target]);
        return ans;
    }

    int minMoves2(vector<int>& nums) {
        const size_t Len = nums.size();
        int *arr = new int[Len];
        copy(nums.begin(), nums.end(), arr);


        sort(arr, arr+Len);
        if(arr[0] == arr[Len-1])
            return 0;

        int move = 0;
        int pin = arr[Len/2];
        auto pinit = arr+Len/2;
        for(auto it = arr; it < pinit; it++) {
            move += pin-*it;
        }
        for(auto it = pinit; it < arr+Len; it++) {
            move += *it-pin;
        }
        return move;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums{1,2,3};
        cout << Solution().minMoves2(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums{1,2,3,4};
        cout << Solution().minMoves2(nums) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> nums{1,0,0,8,6}; //14
        cout << Solution().minMoves2(nums) << endl;
    }
    cout << "3:" << endl;
    {
        //2127271182
        vector<int> nums{203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143};
        cout << Solution().minMoves2(nums) << endl;
    }
    return 0;
}
#endif