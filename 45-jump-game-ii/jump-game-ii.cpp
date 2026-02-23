class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int cur_end = 0;
        int mx = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(mx < i) return -1;
            mx = max(mx,nums[i] + i);
            if(i == cur_end){
                step++;
                cur_end = mx;
            }
        }
        return step;
    }
};