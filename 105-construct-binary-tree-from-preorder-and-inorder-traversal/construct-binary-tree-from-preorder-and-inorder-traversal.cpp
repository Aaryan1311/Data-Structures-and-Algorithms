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
        unordered_map<int,int> mp;
        int n = preorder.size();
        for(int i = 0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return build(preorder,inorder,0,n-1,0,n-1,mp);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie, unordered_map<int,int>& mp){
        if(ps > pe || is > ie) return nullptr;
        TreeNode* node = new TreeNode(preorder[ps]);
        int in_root = mp[preorder[ps]];
        int left_node = in_root - is;
        node->left = build(preorder,inorder,ps+1,ps+left_node,is,in_root-1,mp);
        node->right = build(preorder,inorder,ps+left_node+1,pe,in_root+1,ie,mp);
        return node;
    }
};