#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    void divide(vector<int>& array, int b, int e, int divideNum, int distraction) {
        if(b == e) {
            array[e] = divideNum + distraction;
            return;
        }
        divide(array, b, (e+b)/2, 2*divideNum, distraction-divideNum);
        divide(array, (e+b)/2+1, e, 2*divideNum, distraction);
    }
public:
    vector<int> beautifulArray(int N) {
        vector<int> array(N);
        divide(array, 0, N-1, 1, 0);
        return array;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl; 
    {
        int N = 4;
        cout << Solution().beautifulArray(N) << endl;
    }
    cout << "2:" << endl; 
    {
        int N = 5;
        cout << Solution().beautifulArray(N) << endl;
    }
    return 0;
}
#endif
