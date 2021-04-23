#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    ListNode* reverseList0(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *cur = head, *nxt;
        while(cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        ListNode* head = ListNode::Create({1,2,3,4,5});
        cout << Solution().reverseList(head) << endl;
    }
    cout << " 2:" << endl;
    {
        ListNode* head = ListNode::Create({1,2});
        cout << Solution().reverseList(head) << endl;
    }
    return 0;
}
#endif