class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>> (2, vector<int> (3,0)));
        for(int idx = prices.size()-1;idx>=0;idx--){
            for(int can_buy = 0;can_buy < 2;can_buy++){
                for(int tranc = 0;tranc < 2;tranc++){
                    int buy = 0;
                    int leave = 0;
                    if(can_buy == 0){
                        buy = dp[idx+1][1-can_buy][tranc+1] + prices[idx];
                    }
                    else{
                        buy = dp[idx+1][1-can_buy][tranc] - prices[idx];
                    }
                    leave = dp[idx+1][can_buy][tranc];
                    dp[idx][can_buy][tranc] = max(buy,leave);
                }
            }
        }
        return dp[0][1][0];
    }
};