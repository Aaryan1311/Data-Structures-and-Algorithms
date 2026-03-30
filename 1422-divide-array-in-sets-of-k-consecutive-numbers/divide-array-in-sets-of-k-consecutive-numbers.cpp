class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;
        priority_queue<int, vector<int>, greater<int>> pq;
        map<int,int> mp;
        for(int i : nums){
            pq.push(i);
            mp[i]++;
        }
        int cnt = 0;
        while(cnt < n){
            int ele = pq.top();
            if(mp[ele] > 0){
                for(int i = 0;i<k;i++){
                    if(mp.find(ele+i) == mp.end() || mp[ele+i] <= 0) return false;
                    else mp[ele+i]--;
                }
                cnt += k;
            }
            pq.pop();
        }
        return true;
    }
};