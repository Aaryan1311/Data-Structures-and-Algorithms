class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        map<int,int> mp;
        for(int i : nums) mp[i]++;
        for(auto& it: mp){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(k--){
            pair<int,int> p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        return ans;
    }
};