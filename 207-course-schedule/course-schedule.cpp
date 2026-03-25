class Solution {
public:
    bool dfs(int idx, vector<int>& vis, vector<vector<int>>& adj){
        vis[idx] = 1;
        for(int i : adj[idx]){
            if(vis[i] == 1) return false;
            else if(vis[i] == 0){
                if(!dfs(i,vis,adj)) return false;
            }
        }
        vis[idx] = 2;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i = 0;i<arr.size();i++){
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        for(int i = 0;i<n;i++){
            bool b = dfs(i,vis,adj);
            if(!b) return false;
        }
        return true;
    }
};