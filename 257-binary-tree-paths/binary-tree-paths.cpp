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
    vector<string> ans;
    void helper(TreeNode* node, string s){
        if(node->left == nullptr && node->right == nullptr){
            string ss = s + "->" + to_string(node->val);
            ans.push_back(ss);
            return;
        }
        string curr = s + "->" + to_string(node->val);
        if(node->left != nullptr) helper(node->left,curr);
        if(node->right != nullptr) helper(node->right,curr);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr){
            string ss = to_string(root->val);
            ans.push_back(ss);
        }
        if(root->left != nullptr) helper(root->left,to_string(root->val));
        if(root->right != nullptr) helper(root->right,to_string(root->val));

        return ans;
    }
};