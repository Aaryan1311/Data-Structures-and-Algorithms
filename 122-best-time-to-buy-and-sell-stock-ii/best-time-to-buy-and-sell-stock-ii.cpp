class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int> (2,0));
        for(int idx = prices.size()-1;idx >= 0; idx--){
            for(int j = 1;j>=0;j--){
                int buy = 0;
                int leave = 0;
                if(j == 0){
                    buy = dp[idx+1][1-j] + prices[idx];
                }
                else{
                    buy = dp[idx+1][1-j] - prices[idx];
                }
                leave = dp[idx+1][j];
                dp[idx][j] =  max(buy,leave);
            }
        }
        return dp[0][1];
    }
};