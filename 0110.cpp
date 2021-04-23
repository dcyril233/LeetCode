#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        else {
            int ldepth = maxDepth(root->left);
            int rdepth = maxDepth(root->right);
            return max(ldepth+1, rdepth+1);
        }
    }
public:
    bool isBalanced0(TreeNode* root) {
        if (root == nullptr)
            return true;
        else {
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
            if (abs(leftDepth-rightDepth) > 1)
                return false;
            else
                return (isBalanced(root->left) && isBalanced(root->right));
        }
    }
    int IB(TreeNode *root) {
        if (!root)
            return 0;
        else {
            int l = IB(root->left);
            if (l == -1)
                return -1;
            int r = IB(root->right);
            if (r == -1 || abs(r-l) > 1)
                return -1;
            return max(r, l)+1;
        }
    }
    bool isBalanced(TreeNode* root) {
        int ret = IB(root);
        return ret != -1;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({3,9,20,nullopt,nullopt,15,7});
        cout << Solution().isBalanced(root) << endl;
    }
    cout << " 2:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({1,2,2,3,3,nullopt,nullopt,4,4});
        cout << Solution().isBalanced(root) << endl;
    }
    cout << " 3:" << endl;
    {
        TreeNode *root = nullptr;
        cout << Solution().isBalanced(root) << endl;
    }
    return 0;
}
#endif