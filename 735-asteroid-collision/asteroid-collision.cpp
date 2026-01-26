class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> stk;
        vector<int> ans;
        int idx = 0;
        while(idx < arr.size() && arr[idx] < 0) {
            ans.push_back(arr[idx]);
            idx++;
        }
        while(idx < arr.size() && arr[idx] > 0) {
            stk.push(arr[idx]);
            idx++;
        }
        for(int i = idx;i<arr.size();i++){
            if(arr[i] < 0){
                int ast = abs(arr[i]);
                while(!stk.empty() && stk.top() < ast){
                    stk.pop();
                }
                if(stk.empty()){
                    ans.push_back(arr[i]);
                }
                else if(stk.top() == ast){
                    stk.pop();
                }
            }
            else stk.push(arr[i]); 
        }
        vector<int> help;
        while(!stk.empty()){
            int x = stk.top();
            stk.pop();
            help.push_back(x);
        }
        reverse(help.begin(),help.end());
        for(int i : help){
            ans.push_back(i);
        }
        return ans;
    }
};