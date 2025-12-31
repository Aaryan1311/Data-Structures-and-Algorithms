class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        int cnt = 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){
                    stk.push('[');
                    ans++;
                }
                else{
                    stk.pop();
                }
            }
        }
        return ans;
    }
};
