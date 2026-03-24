class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto &it : mp){
            bucket[it.second-1].push_back(it.first);
        }
        vector<int> ans;
        int idx = nums.size()-1;
        while(idx >= 0 && k > 0){
            for(int i = 0;i<bucket[idx].size() && k > 0;i++){
                ans.push_back(bucket[idx][i]);
                k--;
            }
            idx--;
        }
        return ans;
    }
};