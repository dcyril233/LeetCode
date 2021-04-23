#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool isSymmetric0(TreeNode* root) {
        if(root == nullptr) 
            return true;

        queue<pair<TreeNode*, TreeNode*>> que;
        que.emplace(root->left, root->right);

        while(que.size() != 0) {
            auto temp = que.front();
            que.pop();
            if(temp.first == nullptr || temp.second == nullptr) {
                if(temp.first != temp.second)
                    return false;
            } else {
                cout << temp.first->val << endl;
                if(temp.first->val != temp.second->val)
                    return false;
                que.emplace(temp.first->left, temp.second->right);
                que.emplace(temp.first->right, temp.second->left);
            }
        }
        cout << endl << endl;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        using T = pair<TreeNode*, TreeNode*>;
        if(root == nullptr) 
            return true;

        // stack<T> == stack<T, deque<T>>
        stack<T, vector<T>> stk;
        stk.emplace(root->left, root->right);

        
        while(stk.size() != 0) {
            auto temp = stk.top();
            stk.pop();
            if(temp.first == nullptr || temp.second == nullptr) {
                if(temp.first != temp.second)
                    return false;
            } else {
                cout << temp.first->val << endl;
                if(temp.first->val != temp.second->val)
                    return false;
                stk.emplace(temp.first->left, temp.second->right);
                stk.emplace(temp.first->right, temp.second->left);
            }
        }
        cout << endl << endl;
        return true;
    }
};

#ifdef LEETCODE
int main() {
    //     1
    //  2     2
    //3  4   4  3
    cout << " 1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({1,2,2,3,4,4,3});
        cout << Solution().isSymmetric0(root) << endl;
    }
    cout << " 2:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({1,2,2,3,4,4,3});
        cout << Solution().isSymmetric1(root) << endl;
    }
    // cout << " 2:" << endl;
    // {
    //     TreeNode *root = TreeNode::CreateLev({1,2,2,nullopt,3,nullopt,3});
    //     cout << Solution().isSymmetric(root) << endl;
    // }
    return 0;
}
#endif