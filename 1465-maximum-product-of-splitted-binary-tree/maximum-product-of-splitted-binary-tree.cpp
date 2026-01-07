/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    const int mod = 1e9 + 7;
    long long ts = 0;
    long long mx = 0;

    long long sum(TreeNode* root) {
        if (!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long sub = root->val + left + right;
        mx = max(mx, sub * (ts - sub));

        return sub;
    }

    int maxProduct(TreeNode* root) {
        ts = sum(root);
        dfs(root);
        return mx % mod;
    }
};
