#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> directions {-1, 0, 1, 0, -1};

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& cell, int r, int c) {
        int m = matrix.size(), n = matrix[0].size();
        if(cell[r][c])
            return;
        cell[r][c] = true;
        for(int k = 0; k < 4; ++k) {
            int x = r + directions[k], y = c + directions[k+1];
            if(x >= 0 && x < m && y >= 0 && y < n && (matrix[r][c] <= matrix[x][y]))
                dfs(matrix, cell, x, y);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> cellP (m, vector<bool>(n, false));
        vector<vector<bool>> cellA (m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            dfs(matrix, cellP, i, 0);
            dfs(matrix, cellA, i, n-1);
        }
        for(int j = 0; j < n; ++j) {
            dfs(matrix, cellP, 0, j);
            dfs(matrix, cellA, m-1, j);
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(cellP[i][j] && cellA[i][j])
                    ans.push_back(vector<int>{i, j});
            }
        }
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> matrix{{1, 2, 2, 3, 5},
                                   {3, 2, 3, 4, 4},
                                   {2, 4, 5, 3, 1},
                                   {6, 7, 1, 4, 5},
                                   {5, 1, 1, 2, 4}};
        cout << Solution().pacificAtlantic(matrix) << endl;
    }
    return 0;
}
#endif