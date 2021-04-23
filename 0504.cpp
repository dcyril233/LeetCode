#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string convertToBase70(int num) {
        if(num == 0) return "0";
        string result = "";
        if(num < 0) {
            num = - num;
            result += "-";
        }
        int l = 1, r = 7;
        while(num != 0 || l > 0) {
            if(num >= l && num < r) {
                result += to_string(num / l);
                num = num % l;
                l /= 7;
                r /= 7;
            }
            else if(num >= r){
                l *= 7;
                r *= 7;
            }
            else if(num < l) {
                result += "0";
                l /= 7;
                r /= 7;
            }
        }
        return result;
    }
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string result = "";
        bool isNegative = false;
        if(num < 0) {
            num = - num;
            isNegative = true; 
        }
        while(num) {
            result = to_string(num % 7) + result;
            num /= 7;
        }
        return isNegative ? "-" + result : result;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl; 
    {
        int n = 100;
        cout << Solution().convertToBase7(n) << endl;
    }
    cout << "2:" << endl; 
    {
        int n = -7;
        cout << Solution().convertToBase7(n) << endl;
    }
    return 0;
}
#endif