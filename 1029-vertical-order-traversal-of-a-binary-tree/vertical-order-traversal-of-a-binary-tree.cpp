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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> pq;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<tuple<int,int,TreeNode*>> q;
        q.push({0,0,root});
        while(!q.empty()){
            int row,col;
            TreeNode* node;
            tie(row,col,node) = q.front();
            q.pop();
            if(node->left != nullptr){
                q.push({row+1,col-1,node->left});
            }
            if(node->right != nullptr){
                q.push({row+1,col+1,node->right});
            }
            pq.push_back({col,row,node->val});
        }
        sort(pq.begin(), pq.end());
        int colValue = INT_MIN;

        for(auto &node : pq){
            int row, col, val;
            col = node[0], row = node[1], val = node[2];
            if(col != colValue){
                ans.push_back({});
                colValue = col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};