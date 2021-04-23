#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void backTracking(vector<vector<string>>& ans, vector<string>& board, vector<bool>& column, vector<bool>& ldiag, vector<bool>& rdiag, int row, int n) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(column[i] || ldiag[n-row+i-1] || rdiag[row+i])
                continue;
            board[row][i] = 'Q';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = true;
            backTracking(ans, board, column, ldiag, rdiag, row+1, n);
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = false;
            board[row][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if(n == 0) return ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false), ldiag(2*n-1, false), rdiag(2*n-1, false);
        backTracking(ans, board, column, ldiag, rdiag, 0, n);
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int n = 4;
        cout << Solution().solveNQueens(n) << endl;
    }
    cout << " 2:" << endl;
    {
        int n = 1;
        cout << Solution().solveNQueens(n) << endl;
    }
    return 0;
}
#endif