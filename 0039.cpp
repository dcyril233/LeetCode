#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void backTracking(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& comb, int sum, int index, int target) {
        if(sum == target) {
            ans.push_back(comb);
            return;
        }
        else if(sum > target)
            return;
        for(int i = index; i < candidates.size(); ++i) {
            comb.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(ans, candidates, comb, sum, i, target);
            sum -= candidates[i];
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        backTracking(ans, candidates, comb, 0, 0, target);
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> candidates {2,3,6,7};
        int target = 7;
        cout << Solution().combinationSum(candidates, target) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> candidates {2,3,5};
        int target = 8;
        cout << Solution().combinationSum(candidates, target) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> candidates {2};
        int target = 1;
        cout << Solution().combinationSum(candidates, target) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> candidates {1};
        int target = 1;
        cout << Solution().combinationSum(candidates, target) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> candidates {1};
        int target = 2;
        cout << Solution().combinationSum(candidates, target) << endl;
    }
    return 0;
}
#endif