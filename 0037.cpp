#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool backTracking(vector<vector<char>>& board, vector<vector<bool>>& col, vector<vector<bool>>& row, vector<vector<bool>>& box, vector<pair<int, int>>& dot, int index) {
        if(index == dot.size()) 
            return true;
        bool flag = false;
        auto [r, c] = dot[index];

        for(int num = 0; num < 9; ++num) {
            if(col[c][num] || row[r][num] || box[r/3*3+c/3][num])
                continue;
            board[r][c] = num + 49;
            col[c][num] = row[r][num] = box[r/3*3+c/3][num] = true;
            if(backTracking(board, col, row, box, dot, index+1))
                return true;
            board[r][c] = '.';
            col[c][num] = row[r][num] = box[r/3*3+c/3][num] = false;
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col (9, vector<bool>(9, false));
        vector<vector<bool>> row (9, vector<bool>(9, false));
        vector<vector<bool>> box (9, vector<bool>(9, false));
        vector<pair<int, int>> dot;
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - 48;
                    col[j][num-1] = true;
                    row[i][num-1] = true;
                    box[i/3*3+j/3][num-1] = true;
                }
                else 
                    dot.emplace_back(i, j);
            }
        }
        backTracking(board, col, row, box, dot, 0);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<char>> board {{'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};
        Solution().solveSudoku(board);
        cout << board << endl;
    }
    return 0;
}
#endif