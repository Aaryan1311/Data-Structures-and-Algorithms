class Solution {
public:
    int helper(int idx, int curr, int amount, vector<int>& arr, vector<vector<int>>& dp){
        if(curr == amount) return 0;
        if(idx == arr.size() || curr > amount) return 100000;
        if(dp[idx][curr] != -1) return dp[idx][curr];
        int choose = 100000;
        int not_choose = helper(idx+1,curr,amount,arr,dp);
        if(arr[idx] <= amount && curr + arr[idx] <= amount){
            choose = helper(idx,curr+arr[idx], amount, arr, dp) + 1;
        }
        return dp[idx][curr] = min(choose, not_choose);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        int ans = helper(0,0,amount,coins,dp);
        return ans >= 100000 ? -1 : ans;
    }
};