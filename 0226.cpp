#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    void recurrsion(TreeNode* root) {
        if(root == nullptr)
            return;
        swap(root->left, root->right);
        recurrsion(root->left);
        recurrsion(root->right);
    }
public:
    TreeNode* invertTree0(TreeNode* root) {
        recurrsion(root);
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        stack<TreeNode*> stk;
        stk.emplace(root);
        while(!stk.empty()) {
            auto temp = stk.top();
            stk.pop();
            swap(temp->left, temp->right);
            if(temp->left != nullptr)
                stk.emplace(temp->left);
            if(temp->right != nullptr)
                stk.emplace(temp->right);
        }
        return root;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({4,2,7,1,3,6,9});
        cout << Solution().invertTree(root) << endl;
    }
    cout << " 2:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({2,1,3});
        cout << Solution().invertTree(root) << endl;
    }
    return 0;
}
#endif