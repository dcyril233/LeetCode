#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin())
            s2.push(x);
    }
    
    void pop() {
        if (s1.top() == getMin())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        MinStack* obj = new MinStack();
        obj->push(-2);
        obj->push(0);
        obj->pop();
        int param_3 = obj->top();
        int param_4 = obj->getMin();
        cout << param_3 << endl;
        cout << param_4 << endl;
    }
    return 0;
}
#endif