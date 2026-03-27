class Solution {
public:
    int helper(int idx, int sum, int tar, int off, vector<int>& nums, vector<vector<int>>& dp){
        if(sum == tar && idx == nums.size()) return 1;
        if(idx == nums.size()) return 0;
        if(dp[idx][sum+off] != -1) return dp[idx][sum+off];
        int plus = helper(idx+1,sum+nums[idx],tar,off,nums,dp);
        int minus = helper(idx+1,sum-nums[idx],tar,off,nums,dp);
        return dp[idx][sum+off] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i : nums) sum += i;
        vector<vector<int>> dp(nums.size()+1, vector<int> (2*sum+1,-1));
        return helper(0,0,target,sum,nums,dp);
    }
};