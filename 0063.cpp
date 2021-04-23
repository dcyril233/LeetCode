#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp (m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            if(obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
            else
                break;
        }

        for(int j = 0; j < n; ++j) {
            if(obstacleGrid[0][j] == 0)
                dp[0][j] = 1;
            else
                break;
        }

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> obstacleGrid {{0,0,0},{0,1,0},{0,0,0}};
        cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> obstacleGrid {{0,1},{0,0}};
        cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
    }
    return 0;
}
#endif