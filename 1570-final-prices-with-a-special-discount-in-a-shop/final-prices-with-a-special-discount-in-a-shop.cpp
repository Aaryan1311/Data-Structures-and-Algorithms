class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        vector<int> ans(prices.size(),0);
        stk.push(prices[prices.size()-1]);
        ans[prices.size()-1] = prices[prices.size()-1];
        for(int i = prices.size()-2;i>=0;i--){
            while(stk.size() > 0 && stk.top() > prices[i]){
                stk.pop();
            }
            if(stk.size() == 0){
                stk.push(prices[i]);
                ans[i] = prices[i];
            }
            else{
                ans[i] = prices[i] - stk.top();
                stk.push(prices[i]);
            }
        }
        return ans;
    }
};