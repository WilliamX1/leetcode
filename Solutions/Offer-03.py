from typing import List

class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]: return nums[i]
            else: continue

S = Solution()
S.findRepeatNumber([1,3,4,2,3,4,5,5,6])