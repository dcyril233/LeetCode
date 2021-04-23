#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, m+n));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else {
                    if(i > 0)
                        dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
                    if(j > 0)
                        dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
                }
            }
        }

        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                if(matrix[i][j]) {
                    if(i < m-1)
                        dp[i][j] = min(dp[i+1][j]+1, dp[i][j]);
                    if(j < n-1)
                        dp[i][j] = min(dp[i][j+1]+1, dp[i][j]);
                }
            }
        }  

        return dp;      
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> matrix {{0,0,0},
                                    {0,1,0},
                                    {0,0,0}};
        cout << Solution().updateMatrix(matrix) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> matrix {{0,0,0},
                                    {0,1,0},
                                    {1,1,1}};
        cout << Solution().updateMatrix(matrix) << endl;
    }
    return 0;
}
#endif