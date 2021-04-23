#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (numRows == 0)
            return v;
        v.resize(numRows);
        for (int i = 0; i < numRows; ++i) {
            v[i].resize(i+1);
            if (i == 0) 
                v[0][0] = 1;
            else if (i == 1) {
                v[1][0] = 1;
                v[1][1] = 1;
            }
            else {
                v[i][0] = 1;
                for (int j = 1; j < i; ++j) {
                    v[i][j] = v[i-1][j-1] + v[i-1][j];
                }
                v[i][i] = 1;
            }
        }
        return v;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int numRows = 5;
        cout << Solution().generate(numRows) << endl;
    }
    return 0;
}
#endif