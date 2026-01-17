class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        set<int> s;
        for(int i = 0;i<nums.size();i++){
            if(s.find(nums[i]) == s.end()){
                if(nums[i] != target[i]) s.insert(nums[i]);
            }
        }
        return s.size();
    }
};