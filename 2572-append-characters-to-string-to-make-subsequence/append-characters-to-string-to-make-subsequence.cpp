class Solution {
public:
    int appendCharacters(string s, string t) {
        int l = 0;
        int r = 0;
        while(l < t.size() && r < s.size()){
            if(s[r] == t[l]){
                l++;
                r++;
            }
            else r++;
        }
        if(l == t.size()) return 0;
        else return t.size()-l;
    }
};