class Solution {
public:
    bool helper(int a, int b, int c) { return a > 0 && b > 0 & c > 0; }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        while(r < s.size()){
            if(s[r] == 'a') a += 1;
            if(s[r] == 'b') b += 1;
            if(s[r] == 'c') c += 1;
            if(helper(a,b,c)){
                ans += n-r;
            }
            while(helper(a,b,c)){
                if(s[l] == 'a') a -= 1;
                if(s[l] == 'b') b -= 1;
                if(s[l] == 'c') c -= 1;
                if(helper(a,b,c)){
                    ans += n-r;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};