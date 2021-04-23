#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    vector<int> sum;
public:
    Solution(vector<int>& w): sum(move(w)) {
        partial_sum(sum.begin(), sum.end(), sum.begin());
    }
    
    int pickIndex() {
        int pos = rand() % sum.back() + 1;
        return lower_bound(sum.begin(), sum.end(), pos) - sum.begin();
    }
};

#ifdef LEETCODE
int main() {
    vector<int> nums = {1, 2, 3};
    Solution solution = Solution(nums);
    cout << solution.pickIndex() << endl;
    cout << solution.pickIndex() << endl;   
    cout << solution.pickIndex() << endl;
    return 0;
}
#endif