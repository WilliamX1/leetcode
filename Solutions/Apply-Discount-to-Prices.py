class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        li: list = str.split(sentence, ' ')
        for i in range(len(li)):
            if li[i][0] == '$':
                flag: int = 0
                for ch in li[i]:
                    if ch < '0' or ch > '9':
                        flag += 1
                if flag == 1 and len(li[i]) > 1:
                    li[i] = '$' + format(float(li[i][1:]) * float(100 - discount) / 100.0, ".2f")
        return ' '.join(li)