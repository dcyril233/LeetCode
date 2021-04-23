#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int candy0(vector<int>& ratings) {
        int n = ratings.size();
        int minIndex;
        vector<int> distance (n, 0);
        if(n == 1)
            return 1;
        for(int i = 0; i < n; ++i) {
            if(i == 0) {
                if(ratings[i] <= ratings[i+1]) {
                    distance[i] = 1;
                    minIndex = i;
                }
            }
            else if(i < n - 1 && ratings[i] <= ratings[i+1] && ratings[i] <= ratings[i-1]) {
                distance[i] = 1;
                minIndex = i;
            }
            else if(ratings[i] > ratings[i-1]) {
                distance[i] = i - minIndex + 1;
            }
        }
        for(int i = n - 1; i >= 0; --i) {
            if(i == n - 1) {
                if(ratings[i] <= ratings[i-1]) {
                    distance[i] = 1;
                    minIndex = i;
                }
            }
            else if(i > 0 && ratings[i] <= ratings[i+1] && ratings[i] <= ratings[i-1]) {
                minIndex = i;
            }
            else if(ratings[i] > ratings[i+1]) {
                int temp = minIndex - i + 1;
                distance[i] = max(distance[i], temp);
            }
        }
        int sum = 0;
        for(int len : distance)
            sum += len;
        return sum;
    }

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> distance (n, 1);
        if(n < 2)
            return n;
        for(int i = 1; i < n; ++i) {
            if(ratings[i] > ratings[i-1])
                distance[i] = distance[i-1] + 1;
        }
        for(int i = n-2; i >= 0; --i) {
            if(ratings[i] > ratings[i+1])
                distance[i] = max(distance[i], distance[i+1]+1);
        }
        return accumulate(distance.begin(), distance.end(), 0);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> ratings {1,0,2};
        cout << Solution().candy(ratings) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> ratings {1,2,2};
        cout << Solution().candy(ratings) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> ratings {1,3,2,2,1}; //7
        cout << Solution().candy(ratings) << endl;
    }
    return 0;
}
#endif