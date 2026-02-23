class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(mx < i) return false;
            mx = max(nums[i] + i, mx);
        }
        return mx >= nums.size()-1;
    }
};