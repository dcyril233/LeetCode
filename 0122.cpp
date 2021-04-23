#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxProfit0(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int buy = prices[0], sell = 0, sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < prices[i-1]) {
                buy = prices[i];
                sum += sell;
                sell = 0;
            }
            else {
                //buy = min(buy, prices[i]);
                sell = max(sell, prices[i]-buy);
            }
        }
        sum += sell;
        return sum;
    }
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int maxPro = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) 
                maxPro += prices[i] - prices[i-1];
        }
        return maxPro;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> prices {7,1,5,3,6,4};
        cout << Solution().maxProfit(prices) << endl;
    }
    return 0;
}
#endif