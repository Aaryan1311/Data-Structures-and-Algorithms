class Solution {
public:
    bool dfs(int idx, int col, vector<int>& vis, vector<vector<int>>& graph){
        vis[idx] = col;
        int newCol = col == 0 ? 1 : 0;
        for(int i = 0;i<graph[idx].size();i++){
            if(vis[graph[idx][i]] == -1){
                if(!dfs(graph[idx][i],newCol,vis,graph)) return false;
            }
            else if(vis[graph[idx][i]] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i = 0;i<vis.size();i++){
            if(vis[i] == -1){
                if(!dfs(i,0,vis,graph)) return false;
            }
        }
        return true;
    }
};