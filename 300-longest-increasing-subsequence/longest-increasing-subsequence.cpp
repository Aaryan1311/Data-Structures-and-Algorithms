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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return helper(n,0,-1,nums,dp);
    }
};