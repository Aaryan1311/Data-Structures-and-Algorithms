class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1, vector<int> (2,0));
        for(int idx = prices.size()-1; idx >= 0; idx--){
            for(int can_buy = 0; can_buy < 2; can_buy++){
                if(can_buy == 1){
                    dp[idx][can_buy] = max(dp[idx+1][0] - prices[idx], dp[idx+1][can_buy]);
                }
                else{
                    dp[idx][can_buy] = max(dp[idx+1][1] + prices[idx] - fee, dp[idx+1][can_buy]);
                }
            }
        }
        return dp[0][1];
    }
};