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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> mp;
        map<TreeNode*,int> visited;
        TreeNode* starting_node;
        queue<TreeNode*> q;
        if(!root) return 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                visited[node] = 0;
                if(node->val == start){
                    starting_node = node;
                }
                if(node->left){
                    mp[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    mp[node->right] = node;
                    q.push(node->right);
                }
                q.pop();
            }
        }
        int cnt = 0;
        q.push(starting_node);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                visited[node] = 1;
                if(mp.find(node) != mp.end() && visited[mp[node]] != 1){
                    q.push(mp[node]);
                }
                if(node->left && visited[node->left] != 1){
                    q.push(node->left);
                }
                if(node->right && visited[node->right] != 1){
                    q.push(node->right);
                }
                q.pop();
            }
            cnt++;
        }
        return cnt-1;
    }
};