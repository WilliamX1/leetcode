class Solution
{
  public:
    int kthGrammar(int n, int k)
    {
        return n == 1 ? 0 : kthGrammar(n - 1, (k + 1) / 2) ^ !(k & 1);
    }
};