class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            int sq = sqrt(nums[i]);
            cnt = 0;
            int val = -1;
            for(int j = 2;j<=sq;j++){
                if(nums[i]%j == 0){
                    bool b = nums[i]/j != j;
                    if(b) cnt++;
                    else cnt+=2;
                    val = j;
                }
            }
            if(cnt == 1){
                sum += 1+nums[i]+val+nums[i]/val;
            }
        }
        return sum;
    }
};