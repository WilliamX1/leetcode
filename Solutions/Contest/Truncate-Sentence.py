class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        s = s + ' '
        tmp = s.split(' ', k)
        tmp.pop()
        return ' '.join(tmp)

S = Solution()
print(S.truncateSentence("hello world hhh www", 1))