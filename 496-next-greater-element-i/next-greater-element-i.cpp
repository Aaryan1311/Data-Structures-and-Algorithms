class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        map<int,int> mp;
        int idx = nums2.size()-2;
        mp[nums2[nums2.size()-1]] = -1;
        stk.push(nums2[nums2.size()-1]);
        while(idx >= 0){
            while(!stk.empty() && stk.top() <= nums2[idx]){
                stk.pop();
            }
            if(stk.empty()){
                mp[nums2[idx]] = -1;
            }
            else mp[nums2[idx]] = stk.top();

            stk.push(nums2[idx]);
            idx--;
        }
        vector<int> ans(nums1.size());
        for(int i = 0;i<nums1.size();i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};