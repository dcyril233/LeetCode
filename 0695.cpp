#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxAreaOfIsland0(vector<vector<int>>& grid) {
        vector<int> directions{-1, 0, 1, 0, -1};
        int m = grid.size(), n = m ? grid[0].size() : 0, localArea, area = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    localArea = 1;
                    grid[i][j] = 0;
                    stack<pair<int, int>> island;
                    island.push({i, j});
                    while(!island.empty()) {
                        auto [r, c] = island.top();
                        island.pop();
                        for(int k = 0; k < 4; ++k) {
                            int x = r + directions[k], y = c + directions[k+1];
                            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                                grid[x][y] = 0;
                                ++localArea;
                                island.push({x, y});
                            }
                        }
                    }
                    area = max(area, localArea);
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland1(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, area = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    area = max(area, dfs(grid, i, j));
                }
            }
        }
        return area;
    }
    int dfs1(vector<vector<int>>& grid, int r, int c) {
        vector<int> directions{-1, 0, 1, 0, -1};
        if(grid[r][c] == 0) return 0;
        int localArea = 1;
        grid[r][c] = 0;
        for(int k = 0; k < 4; ++k) {
            int x = r + directions[k], y = c + directions[k+1];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                localArea += dfs(grid, x, y);
            }
        }
        return localArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, localArea, area = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                area = max(area, dfs(grid, i, j));
            }
        }
        return area;
    }
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) 
            return 0;
        grid[r][c] = 0;
        return 1 + dfs(grid, r-1, c) + dfs(grid, r+1, c) 
                    + dfs(grid, r, c-1) + dfs(grid, r, c+1);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> grid{{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                 {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                 {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                 {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                 {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,0,0,0,0}};
        cout << Solution().maxAreaOfIsland(grid) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> grid{{0,0,0,0,0,0,0,0}};
        cout << Solution().maxAreaOfIsland(grid) << endl;
    }
    return 0;
}
#endif