class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first = -1
        last = -1
        l = 0
        r = len(nums)-1
        while l <= r:
            mid = l + (r-l)//2
            if nums[mid] == target:
                first = mid
                r = mid-1
            elif nums[mid] < target:
                l = mid+1
            else: 
                r = mid-1
        ans = []
        if first == -1:
            return [-1,-1]
        else: ans.append(first)
        l = 0
        r = len(nums)-1
        while l <= r:
            mid = l + (r-l)//2
            if nums[mid] == target:
                last = mid
                l = mid+1
            elif nums[mid] < target:
                l = mid+1
            else: 
                r = mid-1
        ans.append(last)
        return ans


        