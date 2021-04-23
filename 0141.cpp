#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        while(p != nullptr && p->next != nullptr) {
            head = head->next;
            p = p->next->next;
            if (head == p)
                return true;
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        ListNode *head = new ListNode(3);
        ListNode *a = new ListNode(2);
        ListNode *b = new ListNode(0);
        ListNode *c = new ListNode(-4);
        head->next = a;
        a->next = b;
        b->next = c;
        c->next = a;
        cout << Solution().hasCycle(head) << endl;
    }
    return 0;
}
#endif