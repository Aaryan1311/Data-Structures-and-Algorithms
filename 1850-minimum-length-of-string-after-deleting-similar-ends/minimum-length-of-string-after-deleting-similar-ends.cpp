class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l < r && s[l] == s[r]){
            while(l < r && s[l] == s[l+1]) l++;
            while(r > l && s[r] == s[r-1]) r--;
            l++;
            r--;
        }
        return max(0,r-l+1);
    }
};