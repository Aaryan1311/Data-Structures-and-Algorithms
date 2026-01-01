class Solution {
public:
    string helper(string s){
        int cnt = 1;
        string ans = "";
        for(int i =0;i<s.size()-1;i++){
            if(s[i] == s[i+1]){
                cnt++;
            }
            else{
                ans.push_back((char)(cnt+'0'));
                ans.push_back(s[i]);
                cnt = 1;
            }
        }
        ans.push_back((char)(cnt+'0'));
        ans.push_back(s[s.size()-1]);
        return ans;
    }
    string countAndSay(int n) {
        int x = n;
        string s = "1";
        if(n == 1) return s;
        while(x > 1){
            s = helper(s);
            x--;
        }
        return s;
    }
};