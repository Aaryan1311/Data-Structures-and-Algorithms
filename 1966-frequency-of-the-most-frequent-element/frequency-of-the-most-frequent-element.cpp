class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long l = 0;
        long long r = 1;
        int ans = 1;
        long long diff = 0;
        while(r < nums.size()){
            diff += (nums[r] - nums[r-1])*(r-l);
            if(diff <= k){
                ans = max(ans,(int)(r-l+1));
            }
            else{
                while(diff > k && l < r){
                    diff -= (nums[r]-nums[l]);
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};