#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string minWindow0(string s, string t) {
        unordered_map<char, int> target;
        int num = 0;
        for(auto &ch : t) {
            target[ch]++;
            num++;
        }
        
        int l, r;
        int bestl, bestr;
        bestl = bestr = -1;
        int count = 0;
        int len = INT_MAX;
        unordered_map<char, int> exist;
        for(int i = 0; i < s.size(); ++i) {
            auto ch = s[i];
            if(target.find(ch) != target.end()) {
                exist[ch]++;
                if(count == 0) {
                    count++;
                    l = r = i;
                }
                else if(count < num){
                    r = i;
                    if(exist[ch] <= target[ch])
                        count++;
                }
                while(count == num || (l < s.size() && target.find(s[l]) == target.end())) {
                    if(count == num && r - l + 1 < len) {
                        len = r - l + 1;
                        bestl = l;
                        bestr = r;
                    }
                    auto tmp = s[l];
                    if(exist.find(tmp) != exist.end()) {
                        exist[tmp]--;
                        if(exist[tmp] < target[tmp])
                            count--;
                    }
                    l++;
                }
            }
        }
        if(bestl == -1)
            return "";
        return s.substr(bestl, bestr-bestl+1);
    }

    string minWindow(string s, string t) {
        vector<int> chars (128, 0);
        vector<bool> flag (128, false);
        for(auto &ch : t) {
            chars[ch]++;
            flag[ch] = true;
        }

        int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
        for(int r = 0; r < s.size(); ++r) {
            if(flag[s[r]]) {
                if(--chars[s[r]] >= 0)
                    cnt++;
                while(cnt == t.size()) {
                    if(r - l + 1 < min_size) {
                        min_l = l;
                        min_size = r - l + 1;
                    }
                    if(flag[s[l]] && ++chars[s[l]] > 0)
                        cnt--;
                    l++;
                }
            }
        }

        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = "ADOBECODEBANC";
        string t = "ABC";
        cout << Solution().minWindow(s, t) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "a";
        string t = "a";
        cout << Solution().minWindow(s, t) << endl;
    }
    return 0;
}
#endif