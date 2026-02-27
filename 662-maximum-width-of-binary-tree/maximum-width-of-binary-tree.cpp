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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        if(!root) return 0;
        q.push({root,0});
        long long ans = 0;
        while(!q.empty()){
            int size = q.size();
            long long norm = q.front().second;
            long long curr_min = INT_MAX;
            long long curr_max = INT_MIN;
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                idx -= norm;
                curr_min = min(curr_min,idx);
                curr_max = max(curr_max,idx);
                if(node->left){
                    q.push({node->left,2*idx+1LL});
                }
                if(node->right){
                    q.push({node->right,2*idx+2LL});
                }
                q.pop();
            }
            ans = max(ans,curr_max-curr_min+1);
        }
        return (int)ans;
    }
};