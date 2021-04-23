#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    vector<int> origin;
public:
    Solution(vector<int>& nums): origin(move(nums)) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    // Fisher-Yates Shuffle
    vector<int> shuffle() {
        if(origin.empty()) return {};
        vector<int> shuffle(origin);
        int n = shuffle.size();
        for(int i = n - 1; i >= 0; --i)
            swap(shuffle[i], shuffle[rand() % (i + 1)]);
        return shuffle;
    }
};

#ifdef LEETCODE
int main() {
    vector<int> nums = {1, 2, 3};
    Solution solution = Solution(nums);
    cout << solution.shuffle() << endl;    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
    cout << solution.reset() << endl;      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
    cout << solution.shuffle() << endl;    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]
    return 0;
}
#endif