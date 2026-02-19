class Solution {
public:
    int helper(int idx1, int idx2, string s1, string s2, vector<vector<int>>& dp){
        if(idx1 == s1.size() || idx2 == s2.size()) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int ans = 0;
        if(s1[idx1] == s2[idx2]){
            ans = 1+helper(idx1+1,idx2+1,s1,s2,dp);
        }
        else{
            ans = max(helper(idx1+1,idx2,s1,s2,dp),helper(idx1,idx2+1,s1,s2,dp));
        }
        return dp[idx1][idx2] = ans;
    }
    int longestCommonSubsequence(string s1, string s2) {
        int idx1 = 0,idx2 = 0;
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1,0));
        for(int idx1 = s1.size()-1;idx1>=0; idx1--){
            for(int idx2 = s2.size()-1;idx2>=0; idx2--){
                int ans = 0;
                if(s1[idx1] == s2[idx2]){
                    ans = 1+dp[idx1+1][idx2+1];
                }
                else{
                    ans = max(dp[idx1+1][idx2],dp[idx1][idx2+1]);
                }
                dp[idx1][idx2] = ans;
            }
        }
        return dp[0][0];
    }
};