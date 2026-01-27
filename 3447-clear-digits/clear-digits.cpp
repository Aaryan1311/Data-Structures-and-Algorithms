class Solution {
public:
    string clearDigits(string s) {
        int l = 0;
        int r = 1;
        string ans = "";
        while(r < s.size()){
            if(s[r] >= 'a' && s[r] <= 'z'){
                l = r;
                r++;
            }
            else if(s[r] >= '0' && s[r] <= '9'){
                s[l] = '*';
                s[r] = '*';
                while(l  >= 0 && s[l] == '*') l--;
                r++;
            }
        }
        for(int i = 0;i<s.size();i++){
            if(s[i] != '*') ans.push_back(s[i]);
        }
        return ans;
    }
};