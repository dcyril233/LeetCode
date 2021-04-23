#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    // divide and conquer
    vector<int> diffWaysToCompute0(string expression) {
        vector<int> ways;
        for(int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if(c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(const int & l: left) {
                    for(const int & r: right) {
                        switch(c) {
                            case '+': ways.push_back(l + r); break;
                            case '-': ways.push_back(l - r); break;
                            case '*': ways.push_back(l * r); break;
                        }
                    }
                }
            }
        }
        if(ways.empty()) ways.push_back(stoi(expression));
        return ways;
    }

    // bottom-up dp
    vector<int> diffWaysToCompute(string expression) {
        vector<int> data; // store the number
        vector<int> ops; // store the operator
        int num = 0; // receive the number from stream
        char op; // receive the operator from stream
        istringstream ss(expression + "+"); // convert expression to stream
        while(ss >> num && ss >> op) {
            data.push_back(num);
            ops.push_back(op);
        }
        int n = data.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
        for(int i = 0; i < n; ++i) {
            for(int j = i; j >= 0; --j) {
                if(i == j)
                    dp[j][i].push_back(data[i]);
                else {
                    for(int k = j; k < i; ++k) {
                        for(auto left : dp[j][k]) {
                            for(auto right : dp[k+1][i]) {
                                int val = 0;
                                switch(ops[k]) {
                                    case '+': val = left + right; break;
                                    case '-': val = left - right; break;
                                    case '*': val = left * right; break;
                                }
                                dp[j][i].push_back(val);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string expression = "2-1-1";
        cout << Solution().diffWaysToCompute(expression) << endl;
    }
    cout << " 2:" << endl;
    {
        string expression = "2*3-4*5";
        cout << Solution().diffWaysToCompute(expression) << endl;
    }
    return 0;
}
#endif