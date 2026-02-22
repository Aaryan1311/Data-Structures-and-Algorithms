/**
 * Definition for a binary tree node.
    struct Tree{
        int val;
        Tree *left;
        Tree *right;
        Tree() : val(0), left(nullptr), right(nullptr) {};
        Tree(int val) : val(val), left(nullptr), right(nullptr) {};
        Tree(int val, Tree *left, Tree *right) : val(val), left(left), right(right) {};
    };
 */
class Solution {
public:
    int helper(TreeNode* node){
       if(node == nullptr) return 0;
       int left = helper(node->left);
       if(left == -1) return -1;
       int right = helper(node->right);
       if(right == -1) return -1;
       if(abs(left-right) > 1) return -1;
       return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
       return helper(root) != -1;
    }
};