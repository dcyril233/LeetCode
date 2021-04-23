#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxProfit0(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int k = 1; k <= 2; ++k) {
            for (int i = 1; i < prices.size(); ++i) {
                int min_diff = prices[0];
                for (int j = 1; j < i; ++j) {
                    min_diff = min(min_diff, prices[j]-dp[k-1][j-1]);
                }
                dp[k][i] = max(dp[k][i-1], prices[i]-min_diff);
            }
        }
        return dp[2][prices.size()-1];
    }
    int maxProfit1(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int k = 1; k <= 2; ++k) {
            int min_diff = prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                min_diff = min(min_diff, prices[i]-dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i]-min_diff);
            }
        }
        return dp[2][prices.size()-1];
    }
    int maxProfit2(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        vector<int> min_diff(2, prices[0]);
        for (int i = 1; i < prices.size(); ++i) {
            for (int k = 1; k <= 2; ++k) {
                min_diff[k-1] = min(min_diff[k-1], prices[i]-dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i]-min_diff[k-1]);
            }
        }
        return dp[2][prices.size()-1];
    }
    int maxProfit3(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        vector<int> dp(3, 0);
        vector<int> min_diff(2, prices[0]);
        for (int i = 1; i < prices.size(); ++i) {
            for (int k = 1; k <= 2; ++k) {
                min_diff[k-1] = min(min_diff[k-1], prices[i]-dp[k-1]);
                dp[k] = max(dp[k], prices[i]-min_diff[k-1]);
            }
        }
        return dp[2];
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int buy1 = prices[0], buy2 = prices[0];
        int sell1 = 0, sell2 = 0;
        for(auto &p : prices) {
            buy1 = min(buy1, p);
            sell1 = max(sell1, p-buy1);
            buy2 = min(buy2, p-sell1);
            sell2 = max(sell2, p-buy2);
        }
        return sell2;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> prices {3,3,5,0,0,3,1,4};
        cout << Solution().maxProfit(prices) << endl;
    }
    return 0;
}
#endif