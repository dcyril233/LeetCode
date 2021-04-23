#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> findSubstring0(string s, vector<string>& words) {
        unordered_map<string, int> wordsCount;

        for(string word : words) {
            wordsCount[word]++;
        }

        vector<int> index;
        int len = words[0].size();
        int num =  len * words.size();

        if(s.size() >= num) {
            for(int i = 0; i <= s.size() - num; ++i) {
                unordered_map<string, int> wordsSeen;
                for(int j = i; j < i + num; j += len) {
                    auto temp = s.substr(j, len);
                    if(wordsCount.find(temp) != wordsCount.end()) {
                        wordsSeen[temp]++;
                        if(wordsSeen[temp] > wordsCount[temp])
                            break;
                    }
                    else
                        break;
                    if(j == i + num - len)
                        index.emplace_back(i);
                }
            }
        }
        return index;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0 || s.size() == 0)
            return vector<int>();
        int W = words.size();
        int L = words[0].size();
        if(s.size() < L)
            return vector<int>();

        unordered_map<string_view, int> wcount;

        //这是啥
        using UMIT = unordered_map<string_view, int>::iterator;

        for(auto &i : words)
            wcount[string_view(&i[0], L)]++;

        //记录哪一位开始是可取的word
        vector<UMIT> ss;
        ss.resize(s.size());
        for(int i = 0; i <= ss.size()-L; i++)
            ss[i] = wcount.find(string_view(&s[i], L));

        vector<int> rlt;
        for(int i = 0; i < L; i++) {
            int num = wcount.size();
            int b = i, e = i;
            for(int j = 0; j < W && e < ss.size(); j++) {
                if(ss[e] != wcount.end()) {
                    auto temp = ss[e]->second;
                    switch((ss[e]->second)--) {
                    case 0: num++; break;
                    case 1: num--; break;
                    }
                }
                e += L;
            }
            if(num == 0)
                rlt.emplace_back(b);
            while(e < ss.size()) {
                if(ss[b] != wcount.end()) {
                    switch(++(ss[b]->second)) {
                    case 0: num--; break;
                    case 1: num++; break;
                    }
                }
                if(ss[e] != wcount.end()) {
                    switch((ss[e]->second)--) {
                    case 0: num++; break;
                    case 1: num--; break;
                    }
                }
                b += L, e += L;
                if(num == 0)
                    rlt.emplace_back(b);
            }
            for(; b != e; b += L)
                if(ss[b] != wcount.end())
                    ++(ss[b]->second);
        }
        return rlt;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = "barfoothefoobarman";
        vector<string> words {"foo","bar"};
        cout << Solution().findSubstring(s, words) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "wordgoodgoodgoodbestword";
        vector<string> words {"word","good","best","word"};
        cout << Solution().findSubstring(s, words) << endl;
    }
    cout << " 3:" << endl;
    {
        string s = "barfoofoobarthefoobarman";
        vector<string> words {"bar","foo","the"};
        cout << Solution().findSubstring(s, words) << endl;
    }
    cout << " 4:" << endl;
    {
        string s = "wordgoodgoodgoodbestword";
        vector<string> words {"word","good","best","good"};
        cout << Solution().findSubstring(s, words) << endl;
    }
    cout << " 5:" << endl;
    {
        string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
        vector<string> words {"fooo","barr","wing","ding","wing"};
        cout << Solution().findSubstring(s, words) << endl;
    }
    cout << " 6:" << endl;
    {
        string s = "aaa";
        vector<string> words {"a","a"};
        cout << Solution().findSubstring(s, words) << endl;
    }
    cout << " 7:" << endl;
    {
        string s = "barfoofoobarthefoobarman";
        vector<string> words {"bar","foo","the"};
        cout << Solution().findSubstring(s, words) << endl;
    }
    cout << " 8:" << endl;
    {
        string s = "aaaaaaaaaaaaaa";
        vector<string> words {"aa","aa"};
        cout << Solution().findSubstring(s, words) << endl;
    }
    cout << " 9:" << endl;
    {
        string s = "mississippi";
        vector<string> words {"mississippis"};
        cout << Solution().findSubstring(s, words) << endl;
    }
    return 0;
}
#endif