from typing import List

class Solution:
    def rev(self, x: int) -> int:
        return int(str(x)[::-1])
    def countNicePairs(self, nums: List[int]) -> int:
        L = {}
        for num in nums:
            n = num - self.rev(num)
            L[n] = L.get(n, 0) + 1

        ans, mod = 0, 10 ** 9 + 7
        for value in L.values():
            ans += value * (value - 1) // 2
        return ans % mod

S = Solution()
print(S.countNicePairs([13,10,35,24,76]))
        
        