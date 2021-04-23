#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> height (n, 0);
        vector<int> left (n, 0);
        vector<int> right (n, n);
        for(int i = 0; i < m; ++i) {
            int leftBdry = 0;
            int rightBdry = n;
            for(int j = n - 1; j >= 0; --j) {
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], rightBdry);
                else {
                    right[j] = n;
                    rightBdry = j;
                }
            }
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    left[j] = max(left[j], leftBdry);
                    height[j]++;
                    maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
                }
                else {
                    left[j] = 0;
                    leftBdry = j + 1;
                    height[j] = 0;
                }
            }
        }
        return maxArea;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<char>> matrix {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        cout << Solution().maximalRectangle(matrix) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<char>> matrix {{'0'}};
        cout << Solution().maximalRectangle(matrix) << endl;
    }
    return 0;
}
#endif