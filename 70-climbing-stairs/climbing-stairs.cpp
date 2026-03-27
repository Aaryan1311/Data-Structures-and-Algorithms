class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int curr = 1;
        int temp = 0;
        if(n <= 1) return 1;
        for(int i = 2;i<=n;i++){
            temp = curr;
            curr = curr + prev;
            prev = temp;
        }
        return curr;
    }
};