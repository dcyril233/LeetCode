#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    //我自己写的辣鸡版本
    vector<vector<int>> reconstructQueue0(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        unordered_map<int, int> count;
        for(auto &num : people) {
            count[num[0]]++;
        }
        for(int i = people.size() - 1; i >= 0; --i) {
            auto temp = people[i];
            if(temp[1] > count[temp[0]] - 1) {
                people.insert(people.begin()+i+temp[1]-count[temp[0]]+2, temp);
                count[temp[0]]--;
                people.erase(people.begin()+i);
            }
        }
        return people;
    }

    //数据结构不转换
    vector<vector<int>> reconstructQueue1(vector<vector<int>>& people) {
        if(people.size() <= 1)
            return people;
        
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> rlt;
        rlt.reserve(people.size());
        for(auto &i: people)
            rlt.insert(rlt.begin()+i[1], vector<int>{i[0], i[1]});
        return rlt;
    }

    //数据结构转换一个
    vector<vector<int>> reconstructQueue2(vector<vector<int>>& people) {
        if(people.size() <= 1)
            return people;
        
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<pair<int, int>> que;
        que.reserve(people.size());
        for(auto &i: people)
            que.insert(que.begin()+i[1], pair<int, int>(i[0], i[1]));
        vector<vector<int>> rlt;
        rlt.reserve(people.size());
        for(auto &i: que)
            rlt.emplace_back(vector<int>{i.first, i.second});
        return rlt;
    }

    //数据结构转换两个
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if(people.size() == 1)
            return people;
        
        vector<pair<int, int>> pp;
        pp.reserve(people.size());
        for(auto &temp : people) {
            pp.emplace_back(temp[0], temp[1]);
        } 

        sort(pp.begin(), pp.end(), [](pair<int, int> &a, pair<int, int> &b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });

        vector<pair<int, int>> que;
        que.reserve(pp.size());
        for(auto &i : pp) {
            que.insert(que.begin()+i.second, i);
        }
        
        vector<vector<int>> rlt;
        rlt.reserve(pp.size());
        for(auto &i : que) {
            rlt.emplace_back(vector<int> {i.first, i.second});
        }

        return rlt;
    }
};

#ifdef LEETCODE 
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
        cout << Solution().reconstructQueue(people) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> people = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
        cout << Solution().reconstructQueue(people) << endl;
    }
    return 0;
}
#endif