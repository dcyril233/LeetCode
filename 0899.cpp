#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:    
    string orderlyQueue(string S, int K) {
        if(K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        
        int n = S.size();
        string res = S;
        S += S;
        for(int i=0;i<n;i++) {
            if(S.substr(i, n) < res) res = S.substr(i, n);
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl; 
    {
        string s = "cba";
        int k = 1;
        cout << Solution().orderlyQueue(s, k) << endl;
    }
    return 0;
}
#endif