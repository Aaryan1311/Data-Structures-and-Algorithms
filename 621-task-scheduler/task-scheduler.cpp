class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        priority_queue<int> pq;
        for(int i = 0;i<tasks.size();i++){
            freq[tasks[i] - 'A']++;
        }
        for(int i : freq){
            if(i > 0) pq.push(i);
        }
        int ans = 0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i = 0;i<=n;i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int i : temp){
               if(i > 0) pq.push(i);
            }
            if(pq.empty()) ans += temp.size();
            else ans += n+1;
        }
        return ans;
    }
};