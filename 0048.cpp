#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int extra;
        int n = matrix.size();
        for(int r = 0; r < (n+1)/2; ++r) {
            for(int i = r; i < n-r-1; ++i) {
                extra = matrix[r][i];
                matrix[r][i] = matrix[n-i-1][r];
                matrix[n-i-1][r] = matrix[n-r-1][n-i-1];
                matrix[n-r-1][n-i-1] = matrix[i][n-r-1];
                matrix[i][n-r-1] = extra;
            }
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
        Solution().rotate(matrix);
        cout << matrix << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
        Solution().rotate(matrix);
        cout << matrix << endl;
    }
    return 0;
}
#endif