class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& m) {
        sort(m.begin(), m.end());
        vector<vector<int>> ans;
        int f = m[0][0];
        int mx_end = m[0][1];
        for(int i = 1;i<m.size();i++){
            if(m[i][0] <= mx_end){
                mx_end = max(mx_end,m[i][1]);
                continue;
            }
            else{
                ans.push_back({f, mx_end});
                mx_end = m[i][1];
                f = m[i][0];
            }
        }
        if(ans.size() > 0 && ans[ans.size()-1][1] >= mx_end) return ans;
        else ans.push_back({f,mx_end});
        return ans;
    }
};