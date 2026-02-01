class Solution {
public:
    int minimumMoves(string s) {
        int cnt = 0;
        int idx = 0;
        while(idx < s.size()){
            if(s[idx] == 'X'){
                idx += 3;
                cnt++;
            }
            else idx++;
        }
        return cnt;
    }
};