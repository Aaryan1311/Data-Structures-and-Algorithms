class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        cur = 0
        mx = 0
        for i in range(0,len(nums)):
            if nums[i] == 0:
                mx = max(mx,cur)
                cur = 0
            else:
                cur += nums[i]
        mx = max(mx,cur)
        return mx