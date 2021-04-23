#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for(auto &ch: s)
            count[ch]++;
        vector<pair<char, int>> bucket;
        bucket.reserve(count.size());
        for(auto &p: count)
            bucket.emplace_back(p);
        sort(bucket.begin(), bucket.end(), [](pair<char, int> &a, pair<char, int> &b) {
            return a.second > b.second;
        });
        string ans;
        for(auto &p: bucket)
            for(int i = 0; i < p.second)
            ans += p.first;
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = "tree";
        cout << Solution().frequencySort(s) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "cccaaa";
        cout << Solution().frequencySort(s) << endl;
    }
    cout << " 3:" << endl;
    {
        string s = "Aabb";
        cout << Solution().frequencySort(s) << endl;
    }
    return 0;
}
#endif