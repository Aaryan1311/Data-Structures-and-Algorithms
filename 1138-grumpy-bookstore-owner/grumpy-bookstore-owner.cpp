class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int m) {
        int ans = 0;
        for(int i = 0;i<grumpy.size();i++){
            if(grumpy[i] == 0){
                ans += customers[i];
            }
        }
        int l = 0;
        int r = m;
        int x = 0;
        int curr = 0;
        for(int i = 0;i<m && i<customers.size();i++){
            if(grumpy[i] == 1){
                x += customers[i];
            }
        }
        curr = x;
        while(r < customers.size()){
           if(grumpy[r] == 1){
                curr += customers[r];
           }
           if(grumpy[l] == 1){
                curr -= customers[l];
           }
           x = max(x,curr);
           l++;
           r++;
        }
        return ans + x;
    }
};