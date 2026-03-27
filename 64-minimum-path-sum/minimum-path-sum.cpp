class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int right = INT_MAX, down = INT_MAX;
        if(i < m-1){
            down = helper(i+1,j,m,n,grid,dp) + grid[i][j];
        }
        if(j < n-1){
            right = helper(i,j+1,m,n,grid,dp) + grid[i][j];
        }
        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return helper(0,0,m,n,arr,dp);
    }
};