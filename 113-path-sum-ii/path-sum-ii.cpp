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
    void helper(TreeNode* node, int curr, int target, vector<vector<int>>& ans, vector<int>& v){
        if(!node) return;
        v.push_back(node->val);
        if(!node->left && !node->right){
            if(curr + node->val == target){
                ans.push_back(v);
            }
            v.pop_back();
            return;
        }
        if(node->left){
            helper(node->left,curr+node->val,target,ans,v);
        }
        if(node->right){
            helper(node->right,curr+node->val,target,ans,v);
        }
        v.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root,0,targetSum,ans,v);
        return ans;
    }
};