#include <iostream>
#include <sstream>
#include <initializer_list>

#include <numeric>

#include <algorithm>
#include <memory>
#include <cmath>
#include <functional>
#include <optional>

#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

int knapsack01(vector<int>& weights, vector<int>& values, int w, int n) {
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for(int i = 1; i <= n; ++i) {
        int weight = weights[i-1], value = values[i-1];
        for(int j = 1; j <= w; ++j) {
            if(j >= weight)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+value);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}

int knapsack01Pro(vector<int>& weights, vector<int>& values, int w, int n) {
    vector<int> dp(w+1, 0);
    for(int i = 1; i <= n; ++i) {
        int weight = weights[i-1], value = values[i-1];
        for(int j = w; j >= weight; --j) {
            dp[j] = max(dp[j], dp[j-w]+value);
        }
    }
    return dp[w];
}

int knapsackFull(vector<int>& weights, vector<int>& values, int w, int n) {
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for(int i = 1; i <= n; ++i) {
        int weight = weights[i-1], value = values[i-1];
        for(int j = 1; j <= w; ++j) {
            if(j >= weight)
                dp[i][j] = max(dp[i-1][j], dp[i][j-w]+value);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}

int knapsackFullPro(vector<int>& weights, vector<int>& values, int w, int n) {
    vector<int> dp(w+1, 0);
    for(int i = 1; i <= n; ++i) {
        int weight = weights[i-1], value = values[i-1];
        for(int j = weight; j <= w; --j) {
            dp[j] = max(dp[j], dp[j-w]+value);
        }
    }
    return dp[w];
}