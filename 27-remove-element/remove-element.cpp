class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int cnt = 0;
        int idx = 0;
        int cidx = 0;
        while(idx <= nums.size()-1){
            if(nums[idx] == val){
                cnt++;
                idx++;
            }
            else{
                if(idx != cidx){
                    nums[cidx] = nums[idx];
                }
                idx++;
                cidx++;
            }
        }
        // for(int i = 0;i<nums.size();i++) cout << nums[i] << ' ';
        // cout << endl << cnt;
        return nums.size()-cnt;
    }
};