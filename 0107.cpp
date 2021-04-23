#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    void recurssion(vector<vector<int>> &rv, TreeNode* root, size_t depth=0){
        if (root) {
            rv.resize(max(rv.size(), depth+1));
            rv[depth].push_back(root->val);
        }
        if (root->left)
            recurssion(rv, root->left, depth+1);
        if (root->right)
            recurssion(rv, root->right, depth+1);
    }
public:
    vector<vector<int>> levelOrderBottom1(TreeNode* root) {
        vector<vector<int>> rv;
        if (root)
            recurssion(rv, root);
        return vector<vector<int>> (rv.rbegin(), rv.rend());
    }

    vector<vector<int>> levelOrderBottom2(TreeNode* root) {
        vector<vector<int>> v;
        if (root == nullptr)
            return v;
        queue<pair<TreeNode*, size_t>> que;
        que.emplace(root, 0);

        while(que.size() != 0) {
            auto temp = que.front();
            que.pop();
            if (temp.first != nullptr) {
                v.resize(max(v.size(), temp.second+1));
                v[temp.second].push_back(temp.first->val);
                que.emplace(temp.first->left, temp.second+1);
                que.emplace(temp.first->right, temp.second+1);
            }
        }
        return vector<vector<int>> (v.rbegin(), v.rend());
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        using T = pair<TreeNode*, size_t>;
        vector<vector<int>> v;
        if (root == nullptr)
            return v;
        stack<T, vector<T>> stk;
        stk.emplace(root, 0);

        while(stk.size() != 0) {
            auto temp = stk.top();
            stk.pop();
            if (temp.first != nullptr) {
                v.resize(max(v.size(), temp.second+1));
                v[temp.second].push_back(temp.first->val);
                stk.emplace(temp.first->right, temp.second+1);
                stk.emplace(temp.first->left, temp.second+1);
            }
        }
        return vector<vector<int>> (v.rbegin(), v.rend());
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({3,9,20,nullopt,nullopt,15,7});
        cout << Solution().levelOrderBottom(root) << endl;
    }
    return 0;
}
#endif