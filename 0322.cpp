#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= coins.size(); ++i) {
            int coin = coins[i-1];
            for(int j = coin; j <= amount; ++j) {
                dp[j] = min(dp[j], dp[j-coin]+1);
            }
        }
        return dp[amount] < amount+1 ? dp[amount] : -1;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:"<< endl;
    {
        vector<int> coins{1,2,5};
        int amount = 11;
        cout << Solution().coinChange(coins, amount) << endl;
    }
    cout << " 2:"<< endl;
    {
        vector<int> coins{2};
        int amount = 3;
        cout << Solution().coinChange(coins, amount) << endl;
    }
    cout << " 3:"<< endl;
    {
        vector<int> coins{1};
        int amount = 0;
        cout << Solution().coinChange(coins, amount) << endl;
    }
    cout << " 4:"<< endl;
    {
        vector<int> coins{1};
        int amount = 1;
        cout << Solution().coinChange(coins, amount) << endl;
    }
    cout << " 5:"<< endl;
    {
        vector<int> coins{1};
        int amount = 2;
        cout << Solution().coinChange(coins, amount) << endl;
    }
    return 0;
}
#endif