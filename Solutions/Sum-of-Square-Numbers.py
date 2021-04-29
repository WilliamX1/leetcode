import math
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        # 暴力解法
        for i in range(math.floor(math.sqrt(c)) + 1):
            tmp = math.sqrt(c - i ** 2)
            if tmp == int(tmp): return True
        return False