class Solution:
    def reverse(self,arr: list[int], x: int, y: int) -> None:
        for i in range(x,y):
            while x < y:
                temp = arr[x]
                arr[x] = arr[y]
                arr[y] = temp
                x += 1
                y -= 1
            
    def rotate(self,nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k%len(nums)
        self.reverse(nums,0,len(nums)-1)
        self.reverse(nums,0,k-1)
        self.reverse(nums,k,len(nums)-1)