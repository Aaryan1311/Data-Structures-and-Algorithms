class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_min = prices[0];
        int profit = 0;
        for(int i = 1;i<prices.size();i++){
            profit = max(profit,prices[i] - curr_min);
            curr_min = min(curr_min,prices[i]);
        }
        return profit;
    }
};