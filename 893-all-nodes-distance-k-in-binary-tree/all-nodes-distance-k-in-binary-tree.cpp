/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentPointer;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->left){
                parentPointer[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentPointer[node->right] = node;
                q.push(node->right);
            }
            q.pop();
        }
        vector<int> ans;
        q.push(target);
        unordered_set<TreeNode*> s;
        s.insert(target);
        while(k--){
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                if(parentPointer.find(node) != parentPointer.end() && s.find(parentPointer[node]) == s.end()){
                    q.push(parentPointer[node]);
                    s.insert(parentPointer[node]);
                }
                if(node->left && s.find(node->left) == s.end()){
                    q.push(node->left);
                    s.insert(node->left);
                }
                if(node->right && s.find(node->right) == s.end()){
                    q.push(node->right);
                    s.insert(node->right);
                }
                q.pop();
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};