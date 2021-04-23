#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        vector<int> tmp(2);
        tmp[0] = intervals[0][0];
        tmp[1] = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] > tmp[1]) {
                ans.push_back(tmp);
                tmp[0] = intervals[i][0];
                tmp[1] = intervals[i][1];
            }
            else {
                if(intervals[i][1] > tmp[1])
                    tmp[1] = intervals[i][1];
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
        cout << Solution().merge(intervals) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> intervals{{1,4},{4,5}};
        cout << Solution().merge(intervals) << endl;
    }
    return 0;
}
#endif