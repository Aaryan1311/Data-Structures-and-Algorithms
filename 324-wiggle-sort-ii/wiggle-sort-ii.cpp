class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int> pqx;
        for(int i : nums){
            pqx.push(i);
        }
        for(int i = 1;i<nums.size();i+=2){
            nums[i] = pqx.top();
            pqx.pop();
        }
        for(int i = 0;i<nums.size();i+=2){
            nums[i] = pqx.top();
            pqx.pop();
        }
        return;
    }
};