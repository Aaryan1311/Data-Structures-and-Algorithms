class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<nums.size()-3;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j<nums.size()-2;j++){
                // if(nums[i] == nums[j]) continue;
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int l = j+1, r = nums.size()-1;
                while(l < r){
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    }
                    else if(sum < target){
                        l++;
                    }
                    else r--;
                }
            }
        }
        return ans;
    }
};