#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void backTracking(vector<vector<char>>& board, string& word, bool& find, vector<vector<bool>>& visit, int count, int r, int c) {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return;
        if(visit[r][c] || find || (board[r][c] != word[count]))
            return;
        if(count == word.size()-1)
            find = true;
        visit[r][c] = true;
        backTracking(board, word, find, visit, count+1, r-1, c);
        backTracking(board, word, find, visit, count+1, r+1, c);
        backTracking(board, word, find, visit, count+1, r, c-1);
        backTracking(board, word, find, visit, count+1, r, c+1);
        visit[r][c] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        bool find = false;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                backTracking(board, word, find, visit, 0, i, j);
            }
        }
        return find;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<char>> board {{'A','B','C','E'},
                                    {'S','F','C','S'},
                                    {'A','D','E','E'}};
        string word = "ABCCED";
        cout << Solution().exist(board, word) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<char>> board {{'A','B','C','E'},
                                    {'S','F','C','S'},
                                    {'A','D','E','E'}};
        string word = "SEE";
        cout << Solution().exist(board, word) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<vector<char>> board {{'A','B','C','E'},
                                    {'S','F','C','S'},
                                    {'A','D','E','E'}};
        string word = "ABCB";
        cout << Solution().exist(board, word) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<vector<char>> board {{'a','a','a','a'},
                                    {'a','a','a','a'},
                                    {'a','a','a','a'}};
        string word = "aaaaaaaaaaaaa";
        cout << Solution().exist(board, word) << endl;
    }
    return 0;
}
#endif