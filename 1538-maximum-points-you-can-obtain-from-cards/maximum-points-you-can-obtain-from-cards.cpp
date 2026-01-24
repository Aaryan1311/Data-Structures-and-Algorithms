class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> v;
        for(int i=n-k;i<n;i++) v.push_back(arr[i]);
        for(int i=0;i<k;i++) v.push_back(arr[i]);
        int l = 0;
        int ans = 0;
        int curr = 0;
        int r = k;
        for(int i = 0;i<k;i++){
            ans += v[i];
        }
        curr = ans;
        while(r < 2*k){
            curr -= v[l];
            curr += v[r];
            ans = max(ans,curr);
            l++;
            r++;
        }
        return ans;
    }
};