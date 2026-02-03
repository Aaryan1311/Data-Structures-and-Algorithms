class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int pre = 1;
        int idx = 1;
        while(idx < nums.size() && nums[idx] > nums[idx-1]) idx++;
        if(idx == nums.size() || idx == pre) return false;
        pre = idx;
        while(idx < nums.size() && nums[idx] < nums[idx-1]) idx++;
        if(idx == nums.size() || idx == pre) return false;
        pre = idx;
        while(idx < nums.size() && nums[idx] > nums[idx-1]) idx++;
        if(idx == nums.size()) return true;
        else return false;
    }
};