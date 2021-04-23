#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> topKFrequent0(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int maxNum = 0;
        for(int  &num : nums)
            maxNum = max(maxNum, ++count[num]);
        vector<vector<int>> bucket (maxNum+1);
        for(auto &pair : count)
            bucket[pair.second].push_back(pair.first);
        vector<int> output;
        for(int i = maxNum; i > 0; --i) {
            for(auto &num : bucket[i]) {
                output.push_back(num);
                --k;
            }
            if(k == 0)
                break;
        }
        return output;
    }
    // quicksort
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int &num : nums)
            count[num]++;
        vector<pair<int, int>> bucket;
        bucket.reserve(count.size());
        for(auto &pair : count)
            bucket.emplace_back(pair);
        sort(bucket.begin(), bucket.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        });
        bucket.reserve(k);
        vector<int> output;
        for(int i = 0; i < k; ++i)
            output.emplace_back(bucket[i].first);
        return output;
    }
    // 堆排序
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int &num : nums)
            count[num]++;
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        for(auto &p: count) {
            if(que.size() < k)
                que.emplace(p);
            else if(que.top().second < p.second) {
                que.pop();
                que.emplace(p);
            }
        }
        vector<int> output(k);
        for(int i = k-1; i >= 0; --i) {
            output[i] = que.top().first;
            que.pop();
        }
        return output;
    }

};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums{1,1,1,2,2,3};
        int k = 2;
        cout << Solution().topKFrequent(nums, k) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums{1};
        int k = 1;
        cout << Solution().topKFrequent(nums, k) << endl;
    }
    return 0;
}
#endif