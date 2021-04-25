import re
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
    # 超时算法
    #    ans = s
    #    tmp = re.sub(r'(.)\1{' + str(k - 1) + '}', "", ans)
    #    while ans != tmp : 
    #        ans = tmp
    #        tmp = re.sub(r'(.)\1{' + str(k - 1) + '}', "", ans)
    #    return ans
        ans = []
        cnt = []
        for i in s:
            if not ans : ans.append(i), cnt.append(1)
            elif i == ans[-1] : 
                ans.append(i) 
                cnt[-1] += 1
                if cnt[-1] == k:
                    for j in range(k): ans.pop()
                    cnt.pop()
            elif cnt[-1] == k: 
                for j in range(k): ans.pop()
                cnt.pop()
                if ans and i == ans[-1]: cnt[-1] += 1
                else: cnt.append(1)
                ans.append(i)
            else: ans.append(i), cnt.append(1)
        while cnt and cnt[-1] == k: 
            for j in range(k): ans.pop()
            cnt.pop()
        return ''.join(ans)
                
                
S = Solution()
S.removeDuplicates("pbbcggttciiippooaais", 2)
