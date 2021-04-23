#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL or headB == NULL)
            return NULL;
        int lenA = 0, lenB = 0;
        ListNode *pA = headA, *pB = headB;
        while (pA != NULL) {
            lenA += 1;
            pA = pA->next;
        }
        while (pB != NULL) {
            lenB += 1;
            pB = pB->next;
        }
        pA = headA, pB = headB;
        int startA = lenA - min(lenA, lenB);
        int startB = lenB - min(lenA, lenB);
        ListNode *intersection;
        int flag = 1;
        for (int i = 0; i < max(lenA, lenB); ++i) {
            if (i >= startA && i >= startB) {
                if (pA == pB) {
                    if (flag) {
                        intersection = pA;
                        flag = 0;
                    }
                }
                else {
                    intersection = NULL;
                    flag = 1;
                }
                pA = pA->next;
                pB = pB->next;
            }
            else {
                if (i < startA)
                    pA = pA->next;
                if (i < startB)
                    pB = pB->next;
            }
        }
        return intersection;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        ListNode *headA = new ListNode(1);
        ListNode *headB = new ListNode(2);
        ListNode *end = new ListNode(3);
        headB->next = end;
        headA->next = headB;
        cout << Solution().getIntersectionNode(headA, headB) << endl;
    }
    return 0;
}
#endif