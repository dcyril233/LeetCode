#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int solve(vector<vector<int>>& rec, vector<int>& val, int l, int r) {
        if(l >= r-1)
            return 0;
        if(rec[l][r] != -1)
            return rec[l][r];
        for(int i = l+1; i < r; ++i) {
            int sum = val[l] * val[i] * val[r];
            sum += solve(rec, val, l, i) + solve(rec, val, i, r);
            rec[l][r] = max(rec[l][r], sum);
        }
        return rec[l][r];
    }
    int maxCoins0(vector<int>& nums) {
        vector<vector<int>> rec;
        vector<int> val;
        int n = nums.size();
        val.resize(n+2);
        for(int i = 1; i <= n; ++i) {
            val[i] = nums[i-1];
        }
        val[0] = val[n+1] = 1;
        rec.resize(n+2, vector<int>(n+2, -1));
        return solve(rec, val, 0, n+1);
    }

    int maxCoins1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> rec(n+2, vector<int>(n+2, 0));
        vector<int> val(n+2, 1);
        for(int i = 1; i <= n; ++i) {
            val[i] = nums[i-1];
        }
        for(int i = n-1; i >= 0; --i) {
            for(int j = i+2; j < n+2; ++j) {
                for(int k = i+1; k < j; ++k) {
                    int sum = val[k] * val[i] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = max(rec[i][j], sum);
                }
            }
        }
        return rec[0][n+1];
    }
    int maxCoins(vector<int>& nums) {
        const size_t Len = nums.size()+2;
        int *nnums = new int[Len];
        nnums[0] = nnums[Len-1] = 1;
        for(int i = 0; i < nums.size(); i++)
            nnums[i+1] = nums[i];
        // nums.insert(nums.begin(), 1);
        // nums.emplace_back(1);
        
        int *dp = new int[Len*Len];
        for(int i = 1; i < Len-1; i++)
            dp[i*Len+i] = nnums[i-1] * nnums[i] * nnums[i+1];

        for(int i = 1; i < Len-1; i++) {
            for(int j = 1; j < Len-i-1; j++) {
                dp[j*Len+j+i] = max(  dp[(j+1)*Len+j+i] + nnums[j-1]*nnums[j]*nnums[j+i+1], 
                                    dp[j*Len+j+i-1] + nnums[j-1]*nnums[j+i]*nnums[j+i+1]);
                for(int k = j+1; k <= j+i-1; k++) {
                    dp[j*Len+j+i] = max(dp[j*Len+j+i], dp[j*Len+k-1]+dp[(k+1)*Len+j+i]+nnums[j-1]*nnums[k]*nnums[j+i+1]);
                }
            }
        }
        return dp[1*Len+Len-2];
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl; 
    {
        vector<int> nums{3,1,5,8};
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << "2:" << endl; 
    {
        vector<int> nums{3,1,5,8};
        cout << Solution().maxCoins(nums) << endl;
    }
    return 0;
}
#endif