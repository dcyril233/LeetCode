#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& map, int m, int n) {
        if(r < 0 || r >= m || c < 0 || c >= n || (board[r][c] == 'X') || (map[r][c] == true))
            return;
        map[r][c] = true;
        dfs(board, r-1, c, map, m, n);
        dfs(board, r+1, c, map, m, n);
        dfs(board, r, c-1, map, m, n);
        dfs(board, r, c+1, map, m, n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> hMap(m, vector<bool>(n, false)), vMap(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            dfs(board, i, 0, hMap, m, n);
            dfs(board, i, n-1, hMap, m, n);
        }
        for(int j = 0; j < n; ++j) {
            dfs(board, 0, j, vMap, m, n);
            dfs(board, m-1, j, vMap, m, n);
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!hMap[i][j] && !vMap[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<char>> board {{'X','X','X','X'},
                                   {'X','O','O','X'},
                                   {'X','X','O','X'},
                                   {'X','O','X','X'}};
        Solution().solve(board);
        cout << board << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<char>> board {{'X'}};
        Solution().solve(board);
        cout << board << endl;
    }
    cout << " 3:" << endl;
    {
        vector<vector<char>> board {{'O','O'},
                                    {'O','O'}};
        Solution().solve(board);
        cout << board << endl;
    }
    return 0;
}
#endif