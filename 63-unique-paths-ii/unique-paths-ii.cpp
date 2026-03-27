class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(arr[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int right = 0, down = 0;
        if(i < m-1){
            down = helper(i+1,j,m,n,arr,dp);
        }
        if(j < n-1){
            right = helper(i,j+1,m,n,arr,dp);
        }
        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return helper(0,0,m,n,arr,dp);
    }
};