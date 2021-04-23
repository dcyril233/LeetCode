#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int maxLen = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i+1][j+1] = min({dp[i][j], dp[i+1][j], dp[i][j+1]}) + 1;
                    maxLen = max(maxLen, dp[i+1][j+1]);
                }
            }
        }
        return maxLen*maxLen;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:"<< endl;
    {
        vector<vector<char>> matrix {{'1','0','1','0','0'},
                                     {'1','0','1','1','1'},
                                     {'1','1','1','1','1'},
                                     {'1','0','0','1','0'}};
        cout << Solution().maximalSquare(matrix) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<char>> matrix {{'0','1'},
                                     {'1','0'}};
        cout << Solution().maximalSquare(matrix) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<vector<char>> matrix {{'0'}};
        cout << Solution().maximalSquare(matrix) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<vector<char>> matrix {{'0', '1'}};
        cout << Solution().maximalSquare(matrix) << endl;
    }
    return 0;
}
#endif