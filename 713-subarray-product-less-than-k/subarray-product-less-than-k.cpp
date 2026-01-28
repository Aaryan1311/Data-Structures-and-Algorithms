class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int mul = 1;
        int l = 0;
        int r = 0;
        while(r < nums.size()){
            mul *= nums[r];
            if(mul < k){
                ans += (r-l+1);
            }
            else{
                while(l < r && mul >= k){
                    mul /= nums[l];
                    l++;
                }
                if(mul < k) ans += (r-l+1);
            }
            r++;
        }
        return ans;
    }
};