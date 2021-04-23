#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int p = 0, q = n - 1;
        while(p < m && q >= 0) {
            if(matrix[p][q] == target)
                return true;
            else if(matrix[p][q] > target)
                --q;
            else 
                ++p;
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> matrix{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
        int target = 5;
        cout << Solution().searchMatrix(matrix, target) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> matrix{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
        int target = 20;
        cout << Solution().searchMatrix(matrix, target) << endl;
    }
    return 0;
}
#endif