#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    int recurssionDepth(TreeNode* root, int depth=1) {
        if (root->left == nullptr and root->right == nullptr)
            return depth;
        int ldepth = INT_MAX;
        int rdepth = INT_MAX;
        if (root->left != nullptr)
            ldepth = recurssionDepth(root->left, depth+1);
        if (root->right != nullptr)
            rdepth = recurssionDepth(root->right, depth+1);
        return min(ldepth, rdepth);
    }
public:
    int minDepth0(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return recurssionDepth(root);
    }
    int minDepth1(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int mdepth = INT_MAX;
        queue <pair<TreeNode*, int>> que;
        que.emplace(root, 1);
        while(!que.empty()) {
            auto tmp = que.front();
            que.pop();

            if (tmp.first->left == nullptr and tmp.first->right == nullptr) {
                if (tmp.second < mdepth)
                    mdepth = tmp.second;
            }
            else {
                if (tmp.second >= mdepth)
                    return mdepth;
                if (tmp.first->left != nullptr)
                    que.emplace(tmp.first->left, tmp.second+1);
                if (tmp.first->right != nullptr)
                    que.emplace(tmp.first->right, tmp.second+1);
            }
        }
        return mdepth;
    }
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int mdepth = INT_MAX;
        stack <pair<TreeNode*, int>> stk;
        stk.emplace(root, 1);
        while(!stk.empty()) {
            auto tmp = stk.top();
            stk.pop();

            if (tmp.first->left == nullptr and tmp.first->right == nullptr)
                mdepth = min(mdepth, tmp.second);
            else {
                if (tmp.first->left != nullptr)
                    stk.emplace(tmp.first->left, tmp.second+1);
                if (tmp.first->right != nullptr)
                    stk.emplace(tmp.first->right, tmp.second+1);
            }
        }
        return mdepth;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({3,9,20,nullopt,nullopt,15,7});
        cout << Solution().minDepth(root) << endl;
    }
    return 0;
}
#endif