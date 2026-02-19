class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n);
        if(nums[0] != 0) pre[0] = nums[0];
        else pre[0] = 1;
        int mxp = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i] == 0){
                pre[i] = 1;
                mxp = max(mxp,0);
            }
            else {
                pre[i] = pre[i-1]*nums[i];
                mxp = max(mxp,pre[i]);
            }
        }
        if(nums[n-1] != 0) suf[n-1] = nums[n-1];
        else suf[n-1] = 1;
        int mxs = nums[n-1];
        for(int i = n-2;i>=0;i--){
             if(nums[i] == 0){
                suf[i] = 1;
                mxs = max(mxs,0);
            }
            else {
                suf[i] = suf[i+1]*nums[i];
                mxs = max(mxs,suf[i]);
            }
        }
        return max(mxp,mxs);
    }
};