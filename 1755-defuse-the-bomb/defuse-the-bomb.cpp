class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans;
        vector<int> v;
        if(k > 0){
            for(int i = 1;i<code.size();i++) v.push_back(code[i]);
            for(int i = 0;i<k;i++) v.push_back(code[i]);
        }
        else if(k < 0){
            for(int i = n+k;i<code.size();i++) v.push_back(code[i]);
            for(int i = 0;i<n-1;i++) v.push_back(code[i]);
            k *= -1;
        }
        else{
            for(int i = 0;i<code.size();i++) ans.push_back(0);
            return ans;
        }
        int val = 0;
        for(int i = 0;i<k;i++){
            val += v[i];
        }
        ans.push_back(val);
        int l = 0;
        int r = k;
        while(r < v.size()){
            val -= v[l];
            val += v[r];
            ans.push_back(val);
            l++;
            r++;
        }
        return ans;
    }
};
