class Solution {
public:
    bool dfs(int idx,vector<int>& vis, vector<vector<int>>& adj){
        vis[idx] = 1;
        for(int i = 0;i<adj[idx].size();i++){
            if(adj[idx][i] != -1 && vis[adj[idx][i]] == 1) return false;
            else if(adj[idx][i] != -1 && vis[adj[idx][i]] == -1) {
                if(!dfs(adj[idx][i],vis,adj)) return false;
            }
        }
        vis[idx] = 2;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj(n);
        for(int i = 0;i<arr.size();i++){
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        vector<int> vis(n,-1);
        for(int i = 0;i<n;i++){
            if(vis[i] == -1){
                bool b = dfs(i,vis,adj);
                if(!b) return false;
            }
        }
        return true;
    }
};