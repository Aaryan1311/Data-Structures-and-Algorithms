class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        
        // Take last row as initial DP
        vector<int> dp = arr[n-1];

        // Bottom-up
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[j] = arr[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};