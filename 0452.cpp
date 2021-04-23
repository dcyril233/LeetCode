#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int n = points.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int prev = points[0][1];
        int count = 1;
        for(int i = 1; i < n; ++i) {
            if(points[i][0] > prev) {
                count++;
                prev = points[i][1];
            }
        }
        return count;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> points {{10,16},{2,8},{1,6},{7,12}};
        cout << Solution().findMinArrowShots(points) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> points {{1,2},{3,4},{5,6},{7,8}};
        cout << Solution().findMinArrowShots(points) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<vector<int>> points {{1,2},{2,3},{3,4},{4,5}};
        cout << Solution().findMinArrowShots(points) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<vector<int>> points {{1,2}};
        cout << Solution().findMinArrowShots(points) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<vector<int>> points {{2,3}};
        cout << Solution().findMinArrowShots(points) << endl;
    }
    return 0;
}
#endif