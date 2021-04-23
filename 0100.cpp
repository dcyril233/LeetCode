#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p -> val == q -> val) {
            if ((p->left != nullptr && q->left != nullptr) && (p->right != nullptr && q->right != nullptr)) {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            } else if ((p->left == nullptr && q->left == nullptr) && (p->right != nullptr && q->right != nullptr)) {
                return isSameTree(p->right, q->right);
            } else if ((p->left != nullptr && q->left != nullptr) && (p->right == nullptr && q->right == nullptr)) {
                return isSameTree(p-> left, q->left);
            } else if ((p->left == nullptr && q->left == nullptr) && (p->right == nullptr && q->right == nullptr)) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode *p = TreeNode::CreateLev({1, 2, 3});
        TreeNode *q = TreeNode::CreateLev({1, 2, 3});
        cout << Solution().isSameTree(p, q) << endl;
    }
    cout << " 2:" << endl;
    {
        TreeNode *p = TreeNode::CreateLev({1, 2});
        TreeNode *q = TreeNode::CreateLev({1, nullopt, 2});
        cout << Solution().isSameTree(p, q) << endl;
    }
    cout << " 3:" << endl;
    {
        TreeNode *p = TreeNode::CreateLev({1, 2, 1});
        TreeNode *q = TreeNode::CreateLev({1, 1, 2});
        cout << Solution().isSameTree(p, q) << endl;
    }
    return 0;
}
#endif