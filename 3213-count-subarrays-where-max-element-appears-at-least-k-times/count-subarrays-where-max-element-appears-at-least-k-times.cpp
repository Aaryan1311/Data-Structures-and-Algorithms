class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = -1;
        for(int i : nums) mx = max(mx,i);
        long long cnt = 0;
        int l = 0;
        int r = 0;
        int curr = 0;
        while(r < nums.size()){
            if(nums[r] == mx){
                curr++;
            }
            if(curr < k){
                cnt += (r-l+1);
            }
            else{
                while(l <= r && curr >= k){
                    if(nums[l] == mx){
                        curr--;
                    }
                    l++;
                }
                if(l <= r) cnt += (r-l+1);
            }
            r++;
        }
        return (nums.size()*(nums.size()+1)/2) - cnt;
    }
};