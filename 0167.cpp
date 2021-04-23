#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin = 0;
        int end = numbers.size() - 1;
        while(begin < end) {
            if(numbers[begin] + numbers[end] > target)
                end--;
            else if(numbers[begin] + numbers[end] < target)
                begin++;
            else 
                break;
        }
        return vector<int> {begin+1, end+1};
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> numbers = {2,7,11,15};
        int target = 9;
        cout << Solution().twoSum(numbers, target) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> numbers = {2,3,4};
        int target = 6;
        cout << Solution().twoSum(numbers, target) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> numbers = {-1,0};
        int target = -1;
        cout << Solution().twoSum(numbers, target) << endl;
    }
    return 0;
}
#endif