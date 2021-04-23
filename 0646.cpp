#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    //dp
    int findLongestChain0(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n <= 1) return n;
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        int maxLen = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
    //greedy
    int findLongestChain1(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n <= 1) return n;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int cur = INT_MIN, count = 0;
        for(auto& pair:pairs) {
            if(pair[0] > cur) {
                count++;
                cur = pair[1];
            }
        }
        return count;
    }
    //dp+binary search
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n <= 1) return n;
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp;
        dp.push_back(pairs[0]);
        for(int i = 1; i < n; ++i) {
            if(pairs[i][0] > dp.back()[1])
                dp.push_back(pairs[i]);
            else {
                auto itr = lower_bound(dp.begin(), dp.end(), pairs[i], [](const vector<int>& a, const vector<int>&b) {
                    return a[1] < b[1];
                });
                if(itr != dp.end())
                    *itr = pairs[i];
            }
        }
        return dp.size();
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> pairs{{1,2},{2,3},{3,4}};
        cout << Solution().findLongestChain(pairs) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> pairs{{2,3},{3,4},{1,2}};
        cout << Solution().findLongestChain(pairs) << endl;
    }
    return 0;
}
#endif