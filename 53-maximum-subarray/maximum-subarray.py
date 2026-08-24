class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur_sum = nums[0]
        mx_sum = nums[0]
        for i in range(1,len(nums)):
            cur_sum = max(nums[i],cur_sum+nums[i])
            mx_sum = max(mx_sum,cur_sum)
        return mx_sum