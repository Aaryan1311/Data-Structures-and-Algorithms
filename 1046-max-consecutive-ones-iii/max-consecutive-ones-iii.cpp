class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int zero = 0;
        int curr = 0;
        int mx = 0;
        while(r < nums.size()){
            if(nums[r] == 1){
                curr++;
                r++;
            }
            else{ 
                mx = max(mx,curr);
                zero++;
                curr++;
                while(zero > k){
                    if(nums[l] == 0) zero--;
                    curr--;
                    l++;
                }
                r++;
            }
            // cout << l << ' ' << r << ' ' << zero << ' ' << curr << ' ' << mx << endl;
        }
        mx = max(mx,curr);
        return mx;
    }
};