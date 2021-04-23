#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxProfit0(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int profit = INT_MAX;
        for (int i = 0; i < prices.size()-1; ++i) {
            for (int j = i+1; j < prices.size(); ++j) {
                int diff = prices[i] - prices[j];
                if (diff < profit)
                    profit = diff;
            }
        }
        if (profit > 0)
            return 0;
        return -profit;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int buy = -prices[0], sell = 0;
        for(auto &p : prices) {
            buy = max(buy, -p);
            sell = max(sell, buy + p);
        }
        return sell;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> price {7,1,5,3,6,4};
        cout << Solution().maxProfit(price) << endl;
    }
    return 0;
}
#endif