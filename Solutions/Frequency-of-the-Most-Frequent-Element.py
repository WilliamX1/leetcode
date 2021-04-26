from typing import List

class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        total = 0
        left = 0
        ans = 1
        
        for i in range(1, len(nums)):
            total += (nums[i] - nums[i - 1]) * (i - left)
            while total > k:
                total -= nums[i] - nums[left]
                left += 1
            ans = max(ans, i - left + 1)
                
        return ans

S = Solution()
print(S.maxFrequency([3,6,9],2))