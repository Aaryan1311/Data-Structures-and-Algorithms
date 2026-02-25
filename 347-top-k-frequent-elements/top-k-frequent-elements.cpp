class Solution {
public:
    struct compare{
        bool operator()(pair<int,int>p1, pair<int,int>p2){
            return p1.second > p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;
        for(int i : nums) mp[i]++;
        for(auto& it: mp){
            pq.push({it.second,it.first});
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