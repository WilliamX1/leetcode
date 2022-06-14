class Solution : def minNonZeroProduct(self, p
                                       : int)
                     ->int : return (2 * *p - 1) *
    pow(2 * *p - 2, 2 * *(p - 1) - 1, 1000000000 + 7) % (1000000000 + 7);