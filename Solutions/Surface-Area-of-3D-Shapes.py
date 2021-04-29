from typing import List

class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = 0
        for i in range(n):
            for j in range(n):
                ans += grid[i][j] * 6
                if (grid[i][j] > 1): ans -= (grid[i][j] - 1) * 2
                if i > 0: ans -= min(grid[i - 1][j], grid[i][j])
                if i < n - 1: ans -= min(grid[i][j], grid[i + 1][j])
                if j > 0: ans -= min(grid[i][j - 1], grid[i][j])
                if j < n - 1: ans -= min(grid[i][j], grid[i][j + 1])
        return ans
    
S = Solution()
print(S.surfaceArea([[1,0],[0,2]]))