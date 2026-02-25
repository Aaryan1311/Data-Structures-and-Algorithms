class Solution {
public:
    void dfs(int x, vector<vector<int>>& arr, vector<int>& vis){
        vis[x] = 1;
        for(int i = 0;i<arr[x].size();i++){
            if(i != x && vis[i] == -1 && arr[x][i] == 1){
                dfs(i,arr,vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,-1);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(vis[i] == -1){
                dfs(i,isConnected,vis);
                cnt++;
            }
        }
        return cnt;
    }
};