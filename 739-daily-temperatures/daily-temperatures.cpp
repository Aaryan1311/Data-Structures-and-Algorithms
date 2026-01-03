class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans (n,0);
        stack<pair<int,int>> stk;
        stk.push({temp[n-1],n-1});
        ans[n-1] = 0;
        for(int i = n-2;i>=0;i--){
            while(stk.size() != 0 && stk.top().first <= temp[i]){
                stk.pop();
            }
            if(stk.size() == 0){
                ans[i] = 0;
                stk.push({temp[i],i});
            }
            else{
                ans[i] = stk.top().second - i;
                stk.push({temp[i],i});
            }
        }
        return ans;
    }
};