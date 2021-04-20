class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

S = Solution()
print(S.strStr("hello", "lle"))