#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> findMinHeightTrees0(int n, vector<vector<int>>& edges) {
        if(n == 1) return vector<int> {0};
        if(n == 2) return edges[0];
        vector<int> ans;
        vector<vector<bool>> connections (n, vector<bool>(n, false));
        for(auto& edge : edges){
            connections[edge[0]][edge[1]] = true;
            connections[edge[1]][edge[0]] = true;
        }
        int minHeight = n;
        int height;
        vector<bool> record (n, false);
        queue<int> que;
        for(int i = 0; i < n; ++i) {
            fill(record.begin(), record.end(), false);
            record[i] = true;
            que.emplace(i);
            height = -1;
            while(!que.empty()) {
                int m = que.size();
                ++height;
                while(m--) {
                    auto temp = que.front();
                    que.pop();
                    for(int j = 0; j < n; ++j) {
                        if(connections[temp][j] && (record[j] == false)) {
                            record[j] = true;
                            que.emplace(j);
                        }
                    }
                }
                if(height > minHeight) {
                    while(!que.empty())
                        que.pop();
                }
            }
            if(height < minHeight) {
                ans.clear();
                ans.emplace_back(i);
                minHeight = height;
            }
            else if(height == minHeight)
                ans.emplace_back(i);
        }
        return ans;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return vector<int> {0};
        if(n == 2) return edges[0];

        vector<vector<int>> adj(n);
        vector<int> counters(n, 0);
        for(auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
            ++counters[edge[0]];
            ++counters[edge[1]];
        }

        queue<int> que;
        for(int i = 0; i < n; ++i) {
            if(counters[i] == 1)
                que.emplace(i);
        }

        while(n > 2) {
            int leafNum = que.size();
            n -= leafNum;
            for(int i = 0; i < leafNum; ++i) {
                auto temp = que.front();
                que.pop();
                for(auto neighbor : adj[temp]) {
                    if(--counters[neighbor] == 1)
                        que.emplace(neighbor);
                }
            }
        }

        vector<int> ans;
        while(!que.empty()) {
            ans.emplace_back(que.front());
            que.pop();
        }

        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int n = 4;
        vector<vector<int>> edges {{1,0},
                                   {1,2},
                                   {1,3}};
        cout << Solution().findMinHeightTrees(n, edges) << endl;
    }
    cout << " 2:" << endl;
    {
        int n = 6;
        vector<vector<int>> edges {{3,0},
                                   {3,1},
                                   {3,2},
                                   {3,4},
                                   {5,4}};
        cout << Solution().findMinHeightTrees(n, edges) << endl;
    }
    cout << " 3:" << endl;
    {
        int n = 1;
        vector<vector<int>> edges {};
        cout << Solution().findMinHeightTrees(n, edges) << endl;
    }
    cout << " 4:" << endl;
    {
        int n = 2;
        vector<vector<int>> edges {{0,1}};
        cout << Solution().findMinHeightTrees(n, edges) << endl;
    }
    cout << " 5:" << endl;
    {
        int n = 7; //[1,2]
        vector<vector<int>> edges {{0,1},
                                   {1,2},
                                   {1,3},
                                   {2,4},
                                   {3,5},
                                   {4,6}};
        cout << Solution().findMinHeightTrees(n, edges) << endl;
    }
    cout << " 6:" << endl;
    {
        int n = 8; //[0]
        vector<vector<int>> edges {{0,1},
                                   {1,2},
                                   {2,3},
                                   {0,4},
                                   {4,5},
                                   {4,6},
                                   {6,7}};
        cout << Solution().findMinHeightTrees(n, edges) << endl;
    }
    return 0;
}
#endif