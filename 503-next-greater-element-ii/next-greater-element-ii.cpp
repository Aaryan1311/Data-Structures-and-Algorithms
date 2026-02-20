class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> stk;
        for(int i = nums.size()-1;i>=0;i--){
            while(!stk.empty() && stk.top() < nums[i]){
                stk.pop();
            }
            stk.push(nums[i]);
        }
        for(int i = nums.size()-1;i>=0;i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            if(stk.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        return ans;
    }
};

// 1 2 1 1 2 1