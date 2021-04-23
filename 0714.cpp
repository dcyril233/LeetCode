#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxProfit0(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n == 0) return 0;
        int valley = prices[0], peak = prices[0], curr = 0, lastsum = 0;
        for(int i = 1; i < n; ++i) {
            int price = prices[i];
            if(peak - price > fee) {
                valley = price;
                peak = price;
                lastsum += curr;
                curr = 0;
            }
            if(price < valley) {
                valley = price;
                peak = price;
            }
            if(price > peak)
                peak = price;
            curr = max(curr, price - valley - fee);
        }
        return curr + lastsum;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n == 0) return 0;
        int cash = 0, hold = -prices[0];
        for(int i = 1; i < n; ++i) {
            cash = max(cash, prices[i] + hold - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> prices{1,3,2,8,4,9};
        int fee = 2;
        cout << Solution().maxProfit(prices, fee) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> prices{4,5,2,4,3,3,1,2,5,4}; // 4
        int fee = 1;
        cout << Solution().maxProfit(prices, fee) << endl;
    }
    return 0;
}
#endif