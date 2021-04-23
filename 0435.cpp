#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

static auto __sync__ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int eraseOverlapIntervals0(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 1)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        int count = 0;
        int first = intervals[0][0];
        int second = intervals[0][1];
        for(int i = 1; i < n; ++i) {
            auto temp = intervals[i];
            if(temp[0] == first)
                count++;
            else if(temp[0] < second){
                count++;
                if(temp[1] < second) {
                    first = temp[0];
                    second = temp[1];
                }
            }
            else {
                first = temp[0];
                second = temp[1];
            }
        }
        return count;
    }

    int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int count = 0;
        int prev = intervals[0][1];
        for(int i = 1; i < n; ++i) {
            if(intervals[i][0] < prev)
                count++;
            else
                prev = intervals[i][1];
        }
        return count;
    }

    int eraseOverlapIntervals(const vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return 0;
        vector<pair<int, int>> ivs;
        ivs.reserve(intervals.size());
        for(auto &i: intervals)
            ivs.emplace_back(i[0], i[1]);

        sort(ivs.begin(), ivs.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.second < b.second;
        });

        int ret = 0;
        int e = ivs[0].second;
        for(int i = 1; i < intervals.size(); i++) {
            if(ivs[i].first >= e)
                e = ivs[i].second;
            else
                ret++;
        }
        return ret;
    }

};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> intervals {{1,2},{2,3},{3,4},{1,3}};
        cout << Solution().eraseOverlapIntervals(intervals) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> intervals {{1,2},{1,2},{1,2}};
        cout << Solution().eraseOverlapIntervals(intervals) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<vector<int>> intervals {{1,2},{2,3}};
        cout << Solution().eraseOverlapIntervals(intervals) << endl;
    }
    return 0;
}
#endif