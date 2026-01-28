class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int z = 0;
        for(char c : s){
            if(c == '0') z++;
        }
        int o = s.size()-z;
        int curz = 0;
        int curo = 0;
        for(int i = 0;i<s.size()-1;i++){
            if(s[i] == '0'){
                curz++;
            }
            else{
                curo++;
            }
            ans = max(ans,curz+o-curo);
        }
        return ans;
    }
};