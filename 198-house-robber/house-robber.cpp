class Solution {
public:
    int helper(int idx, int can, vector<int>& nums, vector<vector<int>>& dp){
        if(idx == nums.size()) return 0;
        if(dp[idx][can] != -1) return dp[idx][can];
        int pick = 0;
        int not_pick = helper(idx+1,1,nums,dp);
        if(can){
            pick = helper(idx+1,0,nums,dp) + nums[idx];
        }
        return dp[idx][can] = max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (2,-1));
        return helper(0,1,nums,dp);
    }
};