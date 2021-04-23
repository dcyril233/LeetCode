#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head): head(head) {}
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans = head->val;
        ListNode* node = head->next;
        int index = 2;
        while(node) {
            if((rand() % index) == 0)
                ans = node->val;
            ++index;
            node = node->next;
        }
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    ListNode *head = ListNode::Create({1, 2, 3});
    Solution solution = Solution(head);
    cout << solution.getRandom() << endl;
    cout << solution.getRandom() << endl;   
    cout << solution.getRandom() << endl;
    return 0;
}
#endif