#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void backTracking(vector<vector<int>>& ans, vector<int>& comb, int count, int pos, int n, int k) {
        if(count == k) {
            ans.push_back(comb);
            return;
        }
        for(int i = pos; i <= n; ++i) {
            comb[count++] = i;
            backTracking(ans, comb, count, i+1, n, k);
            --count;
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k, 0);
        int count = 0;
        backTracking(ans, comb, count, 1, n, k);
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int n = 4, k = 2;
        cout << Solution().combine(n, k) << endl;
    }
    cout << " 2:" << endl;
    {
        int n = 1, k = 1;
        cout << Solution().combine(n, k) << endl;
    }
    return 0;
}
#endif