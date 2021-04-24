class Solution(object):
    def isPathCrossing(self, path):
        """
        :type path: str
        :rtype: bool
        """
        x, y = 0, 0
        S = set([(0, 0)])
        for i in path:
            if i == 'N': y += 1
            elif i == 'S': y -= 1
            elif i == 'E': x += 1
            elif i == 'W': x -= 1
            if (x, y) in S: return True
            S.add((x, y))
        return False
    
S = Solution()
print(S.isPathCrossing('NESW'))