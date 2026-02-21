class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1000000007;
        int ans = 0;
        vector<int> nse(n),pse(n);
        stack<int> stk1,stk2;
        for(int i = n-1;i>=0;i--){
            while(!stk1.empty() && arr[stk1.top()] > arr[i]){
                stk1.pop();
            }
            if(stk1.empty()){
                nse[i] = -1;
            }
            else{
                nse[i] = stk1.top();
            }
            stk1.push(i);
        }

        for(int i = 0;i<n;i++){
            while(!stk2.empty() && arr[stk2.top()] >= arr[i]){
                stk2.pop();
            }
            if(stk2.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = stk2.top();
            }
            stk2.push(i);
        }

        for(int i = 0;i<n;i++){
            int left = 0;
            int right = 0;
            if(pse[i] == -1){
                left = i+1;
            }
            else{
                left = i-pse[i];
            }
            if(nse[i] == -1){
                right = n-i;
            }
            else{
                right = nse[i]-i;
            }
            ans = (ans + (long long)arr[i]*left*right)%MOD; 
        }
        return ans;
    }
};