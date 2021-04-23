#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void backTracking(TreeNode* root, vector<string>& ans, string path) {
        if(root->left == nullptr && root->right == nullptr) {
            ans.emplace_back(path);
            return;
        }
        if(root->left != nullptr) {
            string newPath = path + "->" + to_string(root->left->val);
            backTracking(root->left, ans, newPath);
        }
        if(root->right != nullptr) {
            string newPath = path + "->" + to_string(root->right->val);
            backTracking(root->right, ans, newPath);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr)
            return ans;
        string path = to_string(root->val);
        backTracking(root, ans, path);
        return ans;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({1,2,3,nullopt,5,nullopt,nullopt});
        cout << Solution().binaryTreePaths(root) << endl;
    }
    return 0;
}
#endif