#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int rand100() {
        // 用一个rand7()判断要生出的是奇数还是偶数
        int OddEven = rand7();
        while(OddEven == 7)
            OddEven = rand7();
        // 用一个rand7()得到生成的数
        int num = rand7();
        while(num == 6 || num == 7)
            num = rand7();
        if(OddEven % 2 == 0) 
            num = num * 2 - 1;
        else 
            num = num * 2;
        return num;
    }
    unsigned int seed;
    Solution() {
        seed = rand7() * rand7() % 10 + 1;
    }
    int rand10() {
        seed = (seed + rand7()) % 10 + 1;
        return seed;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        cout << Solution().rand10() << endl;
    }
    cout << "2:" << endl;
    {
        cout << Solution().rand10() << endl;
    }
    cout << "3:" << endl;
    {
        cout << Solution().rand10() << endl;
    }
    return 0;
}
#endif