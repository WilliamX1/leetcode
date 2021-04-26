class Solution:
    def change(self, x: str) -> int:
        if x == 'a': return 0
        elif x == 'e': return 1
        elif x == 'i': return 2
        elif x == 'o': return 3
        elif x == 'u': return 4
    def longestBeautifulSubstring(self, word: str) -> int:
        L = []
        flag = [0,0,0,0,0]
        ans = 0
        for i in word:
            if len(L) == 0 or i >= L[-1]:
                L.append(i)
                flag[self.change(i)] = 1
            else:
                if sum(flag) == 5: ans = max(ans, len(L))
                flag[0] = flag[1] = flag[2] = flag[3] = flag[4] = 0
                L.clear(), L.append(i)
                flag[self.change(i)] = 1
                
        if sum(flag) == 5: ans = max(ans, len(L))    
        return ans
    
S = Solution()
S.longestBeautifulSubstring("aeeeiiiioooauuuaeiou")
            