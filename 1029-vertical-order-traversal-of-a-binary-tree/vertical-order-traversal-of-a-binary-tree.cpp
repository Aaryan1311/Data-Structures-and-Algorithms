class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;   // col, row, value
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int,int>>> q;

        if(root == nullptr) return ans;

        q.push({root,{0,0}});   // row=0, col=0

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int row = p.second.first;
            int col = p.second.second;

            nodes.push_back({col,row,node->val});

            if(node->left){
                q.push({node->left, {row+1,col-1}});
            }
            if(node->right){
                q.push({node->right, {row+1,col+1}});
            }
        }

        sort(nodes.begin(),nodes.end());

        int prevCol = INT_MIN;

        for(auto &t : nodes) {
            int col,row,val;
            tie(col,row,val) = t;

            if(col != prevCol) {
                ans.push_back({});
                prevCol = col;
            }
            ans.back().push_back(val);
        }

        return ans;
    }
};