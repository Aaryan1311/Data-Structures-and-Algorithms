class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr;
        for(int i : nums) arr.push_back(i);
        for(int i : nums) arr.push_back(i);
        vector<int> ans(nums.size());
        stack<int> stk;
        for(int i = arr.size()-1;i>=nums.size();i--){
            while(!stk.empty() && stk.top() < arr[i]){
                stk.pop();
            }
            stk.push(arr[i]);
        }
        for(int i = nums.size()-1;i>=0;i--){
            while(!stk.empty() && stk.top() <= arr[i]){
                stk.pop();
            }
            if(stk.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = stk.top();
            }
            stk.push(arr[i]);
        }
        return ans;
    }
};

// 1 2 1 1 2 1