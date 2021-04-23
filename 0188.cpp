#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxProfitUnlimited(vector<int>& prices) {
        int maxpro = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > prices[i-1])
                maxpro += prices[i] - prices[i-1];
        }
        return maxpro;
    }

    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        if(days < 2) return 0;
        if(k > days) return maxProfitUnlimited(prices);
        vector<int> buy(k+1, prices[0]), sell(k+1, 0);
        for(int i = 0; i < prices.size(); ++i) {
            for(int j = 1; j <= k; ++j) {
                buy[j] = min(buy[j], prices[i] - sell[j-1]);
                sell[j] = max(sell[j], prices[i] - buy[j]);
            }
        }
        return sell[k];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int k = 2;
        vector<int> prices {2,4,1};
        cout << Solution().maxProfit(k, prices) << endl;
    }
    cout << " 2:" << endl;
    {
        int k = 2;
        vector<int> prices {3,2,6,5,0,3};
        cout << Solution().maxProfit(k, prices) << endl;
    }
    return 0;
}
#endif