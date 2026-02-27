class Solution {
public:
    int helper(vector<int>& arr, int k, int mid){
        int cnt = 0;
        int cur = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] <= mid){
                cur++;
                if(cur == k){
                    cnt++;
                    cur = 0;
                }
            }
            else{
                cur = 0;
            }
        }
        return cnt;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int l = 1;
        int r = INT_MIN;
        for(int i : arr) r = max(i,r);
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int made = helper(arr,k,mid);
            if(made < m){
                l = mid+1;
            }
            else{
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
};