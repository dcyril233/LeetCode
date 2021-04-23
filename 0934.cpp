#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void dfs(vector<vector<int>>& A, queue<pair<int, int>>& points, int n, int r, int c) {
        if(r < 0 || r >= n || c < 0 || c >= n || A[r][c] == 2)
            return;
        if(A[r][c] == 0) {
            points.emplace(r, c);
            return;
        }
        A[r][c] = 2;
        dfs(A, points, n, r-1, c);
        dfs(A, points, n, r+1, c);
        dfs(A, points, n, r, c-1);
        dfs(A, points, n, r, c+1);
    }

    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> directions{-1, 0, 1, 0, -1};
        queue<pair<int, int>> points;
        bool flag = false;
        for(int i = 0; i < n; ++i) {
            if(flag) break;
            for(int j = 0; j < n; ++j) {
                if(A[i][j]) {
                    dfs(A, points, n, i, j);
                    flag = true;
                    break;
                }
            }
        }
        //bfs
        int x, y;
        int level = 0;
        while(!points.empty()) {
            ++level;
            int nPoints = points.size();
            while(nPoints--) {
                auto [r, c] = points.front();
                points.pop();
                for(int k = 0; k < 4; ++k) {
                    int x = r + directions[k], y = c + directions[k+1];
                    if(x >= 0 && x < n && y >= 0 && y < n) {
                        if(A[x][y] == 1)
                            return level;
                        else if(A[x][y] == 0) {
                            points.emplace(x, y);
                            A[x][y] = 2;
                        }
                    }
                }
            }
        }
        return 0;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> A {{0,1},
                               {1,0}};
        cout << Solution().shortestBridge(A) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> A {{0,1,0},
                               {0,0,0},
                               {0,0,1}};
        cout << Solution().shortestBridge(A) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<vector<int>> A {{1,1,1,1,1},
                               {1,0,0,0,1},
                               {1,0,1,0,1},
                               {1,0,0,0,1},
                               {1,1,1,1,1}};
        cout << Solution().shortestBridge(A) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<vector<int>> A {{0,1,0,0,0,0},
                               {0,1,1,1,0,0},
                               {0,0,0,0,0,0},
                               {0,0,0,0,0,0},
                               {0,0,0,0,0,0},
                               {1,1,0,0,0,0}};
        cout << Solution().shortestBridge(A) << endl;
    }
    return 0;
}
#endif