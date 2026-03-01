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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return helper(preorder,inorder,0,n-1,0,n-1,mp);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pres, int pree, int ins, int ine, unordered_map<int,int>& mp){
        if(pres > pree || ins > ine) return nullptr;
        TreeNode* node = new TreeNode(preorder[pres]);
        int inroot_idx = mp[preorder[pres]];
        int left_node = inroot_idx - ins;
        TreeNode* left = helper(preorder, inorder, pres+1, pres+left_node, ins, inroot_idx-1, mp);
        TreeNode* right = helper(preorder, inorder, pres+left_node+1,pree,inroot_idx+1,ine,mp);
        node->left = left;
        node->right = right;
        return node;
    }
};