#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int r) {
        for(int i = 0; i < isConnected.size(); ++i) {
            if(isConnected[r][i]) {
                isConnected[r][i] = 0;
                if(r != i)
                    dfs(isConnected, i);
            }
        }
    }

    int findCircleNum0(vector<vector<int>>& isConnected) {
        if(isConnected.size() == 1) return 1;
        int circle = 0;
        for(int i = 0; i < isConnected.size(); ++i) {
            if(isConnected[i][i]) {
                ++circle;
                isConnected[i][i] = 0;
                dfs(isConnected, i);
            }
        }
        return circle;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.size() == 1) return 1;
        //int circle = isConnected.size();
        vector<int> dp (isConnected.size(), 0);
        for(int i = 1; i < isConnected.size(); ++i)
            dp[i] = i;
        for(int i = 1; i < isConnected.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(isConnected[i][j] && dp[i] != dp[j]) {
                    //--circle;
                    if(dp[i] == i) 
                        dp[i] = dp[j];
                    else {
                        int orig = max(dp[j], dp[i]);
                        int tran = dp[j] + dp[i] - orig;
                        for(int k = 0; k < i; ++k) {
                            if(dp[k] == orig)
                                dp[k] = tran;
                        }
                    }
                }
            }
        }        
        int circle = 1;
        for(int i = 1; i < isConnected.size(); i++)
            if(dp[i] == i)
                circle++;
        return circle;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> isConnected{{1,1,0},
                                        {1,1,0},
                                        {0,0,1}};
        cout << Solution().findCircleNum(isConnected) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> isConnected{{1,0,0},
                                        {0,1,0},
                                        {0,0,1}};
        cout << Solution().findCircleNum(isConnected) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<vector<int>> isConnected{{1,0,0,1},
                                        {0,1,1,0},
                                        {0,1,1,1},
                                        {1,0,1,1}};
        cout << Solution().findCircleNum(isConnected) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<vector<int>> isConnected{{1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
                                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                                        {0,0,0,1,0,1,1,0,0,0,0,0,0,0,0},
                                        {0,0,0,0,1,0,0,0,0,1,1,0,0,0,0},
                                        {0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
                                        {0,0,0,1,0,0,1,0,1,0,0,0,0,1,0},
                                        {1,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
                                        {0,0,0,0,0,0,1,1,1,0,0,0,0,1,0},
                                        {0,0,0,0,1,0,0,0,0,1,0,1,0,0,1},
                                        {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0},
                                        {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
                                        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                                        {0,0,0,0,0,0,1,0,1,0,0,0,0,1,0},
                                        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,1}};
        cout << Solution().findCircleNum(isConnected) << endl;
    }
    return 0;
}
#endif