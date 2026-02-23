class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i : nums){
            mn = min(mn,i);
            mx = max(mx,i);
        }
        vector<int> count(mx-mn+1);
        for(int i = 0;i<nums.size();i++){
            count[nums[i]-mn]++;
        }
        int idx = count.size()-1;
        while(idx >= 0 && k >= 0){
            if(count[idx] >= k) return idx+mn;
            else k -= count[idx];
            idx--;
        }
        return -1;
    }
};

// 1 1 1 1 1 1
// 1 2 2 1 2 1