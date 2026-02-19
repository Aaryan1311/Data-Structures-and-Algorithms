class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i =1;i<n;i++){
            if(arr.back() < nums[i]){
                arr.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(arr.begin(),arr.end(),nums[i]) - arr.begin();
                arr[idx] = nums[i];
            }
        }
        return arr.size();
    }
};