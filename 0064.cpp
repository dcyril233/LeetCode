#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 1; i < m; ++i) {
            grid[i][0] += grid[i-1][0];
        }

        for(int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j-1];
        }

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> grid {{1,3,1},{1,5,1},{4,2,1}};
        cout << Solution().minPathSum(grid) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> grid {{1,2,3},{4,5,6}};
        cout << Solution().minPathSum(grid) << endl;
    }
    return 0;
}
#endif