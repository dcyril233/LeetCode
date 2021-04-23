#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    static int saveSum(TreeNode* root, int currentsum, int targetsum) {
        if (root->left == nullptr && root->right == nullptr) {
            currentsum = currentsum + root->val;
            return currentsum == targetsum;
        }
        else if (root->left != nullptr && root->right != nullptr)
            return (saveSum(root->left, currentsum+root->val, targetsum) || saveSum(root->right, currentsum+root->val, targetsum));
        else if (root->left == nullptr)
            return saveSum(root->right, currentsum+root->val, targetsum);
        else
            return saveSum(root->left, currentsum+root->val, targetsum);
    }
public:
    bool hasPathSum0(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        return saveSum(root, 0, sum);
    }
    bool hasPathSum1(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        queue <pair<TreeNode*, int>> que;
        que.emplace(root, root->val);
        while (!que.empty()) {
            auto temp = que.front();
            que.pop();
            if (temp.first->left == nullptr && temp.first->right == nullptr) {
                if (temp.second == sum)
                    return true;
            }
            else {
                if (temp.first->left != nullptr)
                    que.emplace(temp.first->left, temp.second+temp.first->left->val);
                if (temp.first->right != nullptr)
                    que.emplace(temp.first->right, temp.second+temp.first->right->val);
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root ==nullptr)
            return false;
        stack <pair<TreeNode*, int>> stk;
        stk.emplace(root, root->val);
        while (!stk.empty()) {
            auto temp = stk.top();
            stk.pop();
            if (temp.first->left == nullptr && temp.first->right == nullptr) {
                if (temp.second == sum)
                    return true;
            }
            else {
                if (temp.first->left != nullptr)
                    stk.emplace(temp.first->left, temp.second+temp.first->left->val);
                if (temp.first->right != nullptr)
                    stk.emplace(temp.first->right, temp.second+temp.first->right->val);
            }
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({5,4,8,11,nullopt,13,4});
        int sum = 26;
        cout << Solution().hasPathSum(root, sum) << endl;
    }
    return 0;
}
#endif