#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> partitionLabels(string S) {
        array<int, 26> word;
        for(int i = 0; i < S.size(); ++i) {
            word[S[i]-97] = i;
        }
        vector<int> output;
        int endIndex = 0;
        int last = -1;
        for(int i = 0; i < S.size(); ++i) {
            if(word[S[i]-97] > endIndex)
                endIndex = word[S[i]-97];
            if(i == endIndex) {
                output.emplace_back(i - last);
                last = i;
            }
        }
        return output;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string S = "ababcbacadefegdehijhklij";
        cout << Solution().partitionLabels(S) << endl;
    }
    cout << " 2:" << endl;
    {
        string S = "eaaaabaaec";
        cout << Solution().partitionLabels(S) << endl;
    }
    return 0;
}
#endif