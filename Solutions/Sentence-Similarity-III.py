class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        str1 = sentence1.split(' ')
        str2 = sentence2.split(' ')
        # 交换字符串，使得只有可能str1包含于str2
        if len(str1) > len(str2):
            tmp = str1
            str1 = str2
            str2 = tmp
        
        for i in range(len(str1)):
            if str1[i] == str2[i]: continue
            else: 
                for j in range(len(str1) - i):
                    if (str1[len(str1) - j - 1] == str2[len(str2) - j - 1]): continue
                    else: return False
                return True            
        return True

S = Solution()
print(S.areSentencesSimilar('hello world hi', 'hello world'))
        