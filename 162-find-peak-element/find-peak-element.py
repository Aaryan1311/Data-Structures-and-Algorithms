class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l = 0
        r = len(nums)-1
        if len(nums) == 1 or nums[0] > nums[1]: return 0
        if nums[len(nums)-1] > nums[len(nums)-2]: return len(nums)-1
        while l <= r:
            mid = l + (r-l)//2
            if nums[mid-1] < nums[mid] > nums[mid+1]: 
                return mid
            elif nums[mid-1] > nums[mid] > nums[mid+1]:
                r = mid-1
            else: l = mid+1
        return -1