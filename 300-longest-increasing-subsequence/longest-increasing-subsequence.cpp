class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1,0),cur(n+1,0);
        for(int idx = n-1;idx>=0;idx--){
            for(int pre = idx-1;pre>=-1;pre--){
                int pick = 0;
                int not_pick = next[pre+1];
                if(pre == -1 || nums[pre] < nums[idx]){
                    pick = 1+next[idx+1];
                }
                cur[pre+1] = max(pick,not_pick);
            }
            next = cur;
        }
        return cur[0];
    }
};