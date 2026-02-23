class Solution {
public:
    int helper(int idx, bool can_buy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx == prices.size()) return 0;
        if(dp[idx][can_buy ? 1 : 0] != -1) return dp[idx][can_buy ? 1 : 0];
        int buy = 0;
        int leave = 0;
        if(!can_buy){
            buy = helper(idx+1,true,prices,dp) + prices[idx];
        }
        else{
            buy = helper(idx+1,false,prices,dp) - prices[idx];
        }
        leave = helper(idx+1,can_buy,prices,dp);
        return dp[idx][can_buy ? 1 : 0] =  max(buy,leave);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2,-1));
        return helper(0,true,prices,dp);
    }
};