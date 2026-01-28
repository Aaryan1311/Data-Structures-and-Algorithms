class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int mx = 0;
        int l = 0;
        int r = 0;
        map<int,int> mp;
        while(r < nums.size()){
            mp[nums[r]]++;
            int freq = mp[nums[r]];
            if(freq <= k){
                mx = max(mx,(r-l+1));
            } 
            else{
                while(l < r && freq > k){
                    if(nums[l] == nums[r]){
                        freq--;
                        mp[nums[l]]--;
                    }
                    else{
                        mp[nums[l]]--;
                    }
                    l++;
                }
            }
            r++;
        }
        return mx;
    }
};