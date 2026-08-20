class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        idx = 0
        for i in range(0,len(nums)):
            if nums[i] != 0:
                nums[idx] = nums[i]
                if i != idx: nums[i] = 0
                idx += 1
        return

