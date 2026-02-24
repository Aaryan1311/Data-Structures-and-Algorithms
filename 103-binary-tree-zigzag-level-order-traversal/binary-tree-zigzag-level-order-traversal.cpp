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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool b = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                v.push_back(node->val);
                q.pop();
            }
            if(b){
                reverse(v.begin(),v.end());
            }
            ans.push_back(v);
            b = !b;
        }
        return ans;
    }
};