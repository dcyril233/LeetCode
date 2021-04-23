#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp (word1.size()+1, vector<int>(word2.size()+1, 0));
        dp[0][0] = 0;

        for(int i = 1; i < word1.size()+1; ++i)
            dp[i][0] = i;

        for(int j = 1; j < word2.size()+1; ++j)
            dp[0][j] = j;
        
        for(int i = 1; i < word1.size()+1; ++i) {
            for(int j = 1; j < word2.size()+1; ++j) {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string word1 = "horse";
        string word2 = "ros";
        cout << Solution().minDistance(word1, word2) << endl;
    }
    cout << " 2:" << endl;
    {
        string word1 = "intention";
        string word2 = "execution";
        cout << Solution().minDistance(word1, word2) << endl;
    }
    return 0;
}
#endif