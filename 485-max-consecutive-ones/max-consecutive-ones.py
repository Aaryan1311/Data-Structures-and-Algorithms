class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        mx = 0
        l = 0
        r = 0
        while r < len(nums):
            if nums[r] == 1:
                mx = max(r-l+1,mx)
                r += 1
            else:
                while r < len(nums) and nums[r] == 0:
                    r += 1
                if r == len(nums):
                    return mx
                else:
                    l = r
        return mx