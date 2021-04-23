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
        unordered_set<int> exist;
        for(int i = index; i < candidates.size(); ++i) {
            if(exist.find(candidates[i]) != exist.end())
                continue;
            comb.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(ans, candidates, comb, sum, i+1, target);
            sum -= candidates[i];
            comb.pop_back();
            exist.insert(candidates[i]);
        }
    }

    static void recursion(vector<int>& candidates, vector<vector<int>> &rlt, vector<int> &now, unsigned index, int leave) {
        int nowsize = now.size();
        now.push_back(0);
        for(;index < candidates.size() && leave > candidates[index];){
            now[nowsize] = candidates[index];
            recursion(candidates, rlt, now, index + 1, leave - candidates[index]);
            while(++index < candidates.size() && candidates[index] == candidates[index-1]){}
        }
        if(index < candidates.size() && leave == candidates[index]){
            now[nowsize] = leave;
            rlt.push_back(now);
        }
        now.resize(nowsize);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        //backTracking(ans, candidates, comb, 0, 0, target);
        recursion(candidates, ans, comb, 0, target);
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> candidates {10,1,2,7,6,1,5};
        int target = 8;
        cout << Solution().combinationSum2(candidates, target) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> candidates {2,5,2,1,2};
        int target = 5;
        cout << Solution().combinationSum2(candidates, target) << endl;
    }
    return 0;
}
#endif