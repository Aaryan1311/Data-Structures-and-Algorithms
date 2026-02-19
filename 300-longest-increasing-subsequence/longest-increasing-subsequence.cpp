class Solution {
public:
    int helper(int n, int idx, int pre, vector<int>& arr, vector<vector<int>>& dp){
        if(idx == n) return 0;
        if(dp[idx][pre+1] != -1) return dp[idx][pre+1];
        int len = helper(n,idx+1,pre,arr,dp);
        if(pre == -1 || arr[pre] < arr[idx]){
            len = max(len,1 + helper(n,idx+1,idx,arr,dp));
        }
        return dp[idx][pre+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return helper(n,0,-1,nums,dp);
    }
};