class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int idx = 1;
        int cidx = 0;
        while(idx <= nums.size()-1){
            if(nums[idx] == nums[cidx]) idx++;
            else{
                cidx++;
                nums[cidx] = nums[idx];
                cnt++;
                idx++;
            }
        }
        return cnt;
    }
};