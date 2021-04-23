#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ldepth = maxDepth(root->left);
        int rdepth = maxDepth(root->right);
        if (ldepth > rdepth)
            return ldepth+1;
        else
            return rdepth+1;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({3,9,20,nullopt,nullopt,15,7});
        cout << Solution().maxDepth(root) << endl;
    }
    return 0;
}
#endif