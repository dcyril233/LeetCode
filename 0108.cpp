#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    TreeNode* recurssion(vector<int>& nums, int start, int end) {
        if (start == end) {
            TreeNode *leaf = new TreeNode(nums[start]);
            return leaf;
        }
        int mid = (start + end) / 2;
        TreeNode* ret = new TreeNode(nums[mid]);
        ret->right = recurssion(nums, mid+1, end);
        if (start < mid)
            ret->left = recurssion(nums, start, mid-1);
        return ret;
    }
public:
    TreeNode* sortedArrayToBST0(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        return recurssion(nums, 0, nums.size()-1);
    }
    TreeNode* sortedArrayToBST1(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        queue<tuple<TreeNode*&, int, int>> que;
        TreeNode *h = nullptr;
        que.emplace(h, 0, nums.size()-1);
        while(!que.empty()) {
            auto tmp = que.front();
            que.pop();

            auto &node = get<0>(tmp);
            auto b = get<1>(tmp);
            auto e = get<2>(tmp);

            if (b == e) {
                node = new TreeNode(nums[b]);
            } else {
                int mid = (b + e) / 2;
                node = new TreeNode(nums[mid]);
                que.emplace(node->right, mid+1, e);
                if (b < mid)
                    que.emplace(node->left, b, mid-1);
            }
        }
        return h;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        stack<tuple<TreeNode*&, int, int>> stk;
        TreeNode *h = nullptr;
        stk.emplace(h, 0, nums.size()-1);
        while(!stk.empty()) {
            auto temp = stk.top();
            stk.pop();

            auto &node = get<0>(temp);
            auto start = get<1>(temp);
            auto end = get<2>(temp);

            if (start == end)
                node = new TreeNode(nums[end]);
            else {
                int mid = (start + end) / 2;
                node = new TreeNode(nums[mid]);
                stk.emplace(node->right, mid+1, end);
                if (start < mid)
                    stk.emplace(node->left, start, mid-1);
            }
        }
        return h;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums {-10,-3,0,5,9};
        TreeNode* ret = Solution().sortedArrayToBST(nums);
        cout << ret << endl;
    }
    return 0;
}
#endif