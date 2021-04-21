
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0": return 0
        
        dp = [1, 1] 
        x = len(s)
        for index in range(len(s) - 1):
            if s[index + 1] != '0': dp.append(dp[index + 1])
            else : dp.append(0)
            # 满足26个字母，动态规划
            if s[index] == '1' or s[index] == '2' and s[index + 1] <= '6': dp[index + 2] += dp[index]
            else : continue
        return dp[len(s)]

S = Solution()
print(S.numDecodings("06"))