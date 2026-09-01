class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        last = {}
        l = 0
        mx = 0
        for r,f in enumerate(fruits):
            last[f] = r
            if len(last) > 2:
                out = min(last,key=last.get)
                l = last[out]+1
                del last[out]
            mx = max(mx,r-l+1)
        return mx