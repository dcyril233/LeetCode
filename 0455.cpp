#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int p, q;
        p = q = 0;
        int count = 0;
        while(p < g.size() && q < s.size()) {
            if(g[p] <= s[q]) {
                count++;
                p++;
                q++;
            }
            else
                q++;
        }
        return count;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> g = {1,2,3};
        vector<int> s = {1,1};
        cout << Solution().findContentChildren(g, s) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> g = {1,2};
        vector<int> s = {1,2,3};
        cout << Solution().findContentChildren(g, s) << endl;
    }
    return 0;
}
#endif