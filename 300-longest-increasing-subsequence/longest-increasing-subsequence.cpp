class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,1);
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[j] < nums[i]){
                    arr[i] = max(arr[i],1+arr[j]);
                }
            }
        }
        int ans = 1;
        for(int i : arr){
            ans = max(ans,i);
        }
        return ans;
    }
};