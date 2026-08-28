class Solution:
    def check(self, mid: int, piles: List[int]) -> int:
        cnt = 0
        for i in range(len(piles)):
            cnt += (piles[i] + mid - 1) // mid
        return cnt

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        ans = -1

        while l <= r:
            mid = l + (r - l) // 2
            hours = self.check(mid, piles)

            if hours > h:
                l = mid + 1
            else:
                ans = mid
                r = mid - 1

        return ans
