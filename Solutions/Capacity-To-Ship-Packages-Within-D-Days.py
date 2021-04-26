from typing import List
import math
class Solution:
    def isOK(self, weights: List[int], D: int, mid: int) -> bool:
        minus_sum = sum(weights)
        minus_D = D
        tmp_sum = 0
        for i in range(len(weights)):
            tmp_sum += weights[i]
            if tmp_sum > mid: 
                tmp_sum -= weights[i]
                
                minus_sum -= tmp_sum
                minus_D -= 1
                if minus_sum / mid > minus_D: return False
                else: tmp_sum = weights[i]
            else: continue
        return True
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        # 二分搜索算法
        left = (max(max(weights), math.ceil(sum(weights) / D)))
        right = sum(weights)
        mid = 0
        while (left <= right):
            mid = (left + right) >> 1
            if self.isOK(weights, D, mid): right = mid - 1
            else: left = mid + 1
        return left
S = Solution()
print(S.shipWithinDays([1,2,3,1,1], 4))