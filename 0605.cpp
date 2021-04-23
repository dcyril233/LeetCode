#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool canPlaceFlowers0(vector<int>& flowerbed, int n) {
        if(n == 0)
            return true;
        int len = flowerbed.size();
        if(len == 1){
            if(flowerbed[0] == 0 && n == 1)
                return true;
            else
                return false;
        }
        if(len == 2) {
            if(flowerbed[0] + flowerbed[1] == 0 && n == 1)
                return true;
            else
                return false;
        }
        for(int i = 0; i < len; ++i) {
            if(n == 0)
                break;
            if(i == 0) {
                if(flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
            }
            else if (i == len - 1) {
                if(flowerbed[i] == 0 && flowerbed[i-1] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
            }
            else {
                if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }
        return n == 0;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for(int i = 0; i < len; i += 2) {
            if(flowerbed[i] == 0) {
                if(i == len - 1 || flowerbed[i+1] == 0)
                    n--;
                else 
                    i++;
            }
            if(n <= 0)
                break;
        }
        return n <= 0;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> flowerbed {1,0,0,0,1};
        int n = 1;
        cout << Solution().canPlaceFlowers(flowerbed, n) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> flowerbed {1,0,0,0,1};
        int n = 2;
        cout << Solution().canPlaceFlowers(flowerbed, n) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> flowerbed {1,0,0,0,0,1};
        int n = 2;
        cout << Solution().canPlaceFlowers(flowerbed, n) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> flowerbed {0,1,0};
        int n = 1;
        cout << Solution().canPlaceFlowers(flowerbed, n) << endl;
    }
    return 0;
}
#endif