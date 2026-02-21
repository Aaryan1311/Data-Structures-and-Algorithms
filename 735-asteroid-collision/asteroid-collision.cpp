class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> stk;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] < 0){
                int ast = abs(arr[i]);
                while(!stk.empty() && stk.top() > 0 && stk.top() < ast){
                    stk.pop();
                }
                if(stk.empty() || stk.top() < 0){
                    stk.push(arr[i]);
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
        return help;
    }
};