class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int idx1 = 0,idx2 = 0;
        int n1 = s1.size();
        int n2 = s2.size();
        n1 = max(n1,n2);
        vector<int> nx1(n1+1,0),cur(n1+1,0);
        for(int idx1 = s1.size()-1;idx1>=0; idx1--){
            for(int idx2 = s2.size()-1;idx2>=0; idx2--){
                int ans = 0;
                if(s1[idx1] == s2[idx2]){
                    ans = 1+nx1[idx2+1];
                }
                else{
                    ans = max(nx1[idx2],cur[idx2+1]);
                }
                cur[idx2] = ans;
            }
            nx1 = cur;
        }
        return cur[0];
    }
};