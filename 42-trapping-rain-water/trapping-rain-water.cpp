class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        vector<int> right(height.size());
        left.push_back(height[0]);
        for(int i = 1;i<height.size();i++){
            left.push_back(max(height[i],left[i-1]));
        }
        right[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2;i>=0;i--){
            right[i] = max(height[i],right[i+1]);
        }
        int ans = 0;
        for(int i = 1;i<height.size()-1;i++){
            if(left[i] > height[i] && right[i] > height[i]){
                ans += (min(left[i],right[i])-height[i]);
            }
        }
        return ans;
    }
};