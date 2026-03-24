class Solution {
public:
    void dfs(int idx, vector<int>& vis, vector<vector<int>>& arr){
        vis[idx] = 1;
        for(int i = 0;i<arr[idx].size();i++){
            if(arr[idx][i] == 1 && vis[i] == 0){
                dfs(i,vis,arr);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i = 0;i<vis.size();i++){
            if(!vis[i]){
                dfs(i,vis,isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};