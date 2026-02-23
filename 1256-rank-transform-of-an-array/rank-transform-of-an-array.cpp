class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : arr) pq.push(i);
        map<int,int> mp;
        vector<int> ans(arr.size());
        int rank = 1;
        int val = INT_MIN;
        while(!pq.empty()){
            while(!pq.empty() && pq.top() == val) pq.pop();
            if(pq.empty()) break;
            val = pq.top();
            mp[val] = rank;
            rank++;
            pq.pop();
        }
        for(int i = 0;i<arr.size();i++){
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};