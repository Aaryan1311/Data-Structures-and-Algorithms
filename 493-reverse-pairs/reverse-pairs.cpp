class Solution {
public:
    int ans = 0;
    void helper(vector<int>& nums, int l, int mid, int r){
        int j = mid + 1;
        for(int i = l; i <= mid; i++){
            while(j <= r && (long long)nums[i] > 2LL * nums[j]){
                j++;
            }
            ans += (j - (mid + 1));
        }

        int left = l, right = mid+1;
        vector<int> temp;
        while(left <= mid && right <= r){
            if(nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= r) temp.push_back(nums[right++]);

        for(int i = l;i<=r;i++){
            nums[i] = temp[i-l];
        }
        return;
    }
    void merge(vector<int>& nums,int l, int r){
        if(l >= r) return;
        int mid = (l+r)/2;
        merge(nums,l,mid);
        merge(nums,mid+1,r);
        helper(nums,l,mid,r);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        merge(nums,0,n-1);
        return ans;
    }
};
