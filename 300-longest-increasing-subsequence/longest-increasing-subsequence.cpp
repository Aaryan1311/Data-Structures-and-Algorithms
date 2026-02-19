class Solution {
public:
    int helper(int n, int idx, int pre, vector<int>& arr, vector<vector<int>>& dp){
        if(idx == n) return 0;
        if(dp[idx][pre+1] != -1) return dp[idx][pre+1];
        int pick = 0;
        int not_pick = helper(n,idx+1,pre,arr,dp);
        if(pre == -1 || arr[pre] < arr[idx]){
            pick = 1 + helper(n,idx+1,idx,arr,dp);
        }
        return dp[idx][pre+1] = max(pick,not_pick);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int idx = n-1;idx>=0;idx--){
            for(int pre = idx-1;pre>=-1;pre--){
                int pick = 0;
                int not_pick = dp[idx+1][pre+1];
                if(pre == -1 || arr[pre] < arr[idx]){
                    pick = 1 + dp[idx+1][idx+1];
                }
                dp[idx][pre+1] = max(pick,not_pick);
            }
        }
        return dp[0][-1+1];
    }
};