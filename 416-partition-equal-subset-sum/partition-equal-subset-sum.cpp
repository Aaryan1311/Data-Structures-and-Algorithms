class Solution {
public:
    bool helper(int idx, int curr, int tar, vector<int>& nums, vector<vector<int>>& dp){
        if(curr == tar) return true;
        if(idx == nums.size()) return false;
        if(dp[idx][curr] != -1) return dp[idx][curr] == 1;
        bool choose = false;
        bool not_choose = helper(idx+1,curr,tar,nums,dp);
        if(curr + nums[idx] <= tar){
            choose = helper(idx+1,curr+nums[idx],tar,nums,dp);
        }
        if(choose || not_choose){
            dp[idx][curr] = 1;
        }
        else{
            dp[idx][curr] = 0;
        }
        return choose || not_choose;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum += i;
        if(sum % 2 == 1) return false;
        vector<vector<int>> dp(nums.size(), vector<int> (sum/2+1,-1));
        return helper(0,0,sum/2,nums,dp);
    }
};