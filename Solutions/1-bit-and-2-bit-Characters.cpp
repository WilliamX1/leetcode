class Solution
{
  public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int cnt = 0;
        for (int i = bits.size() - 2; i >= 0; i--)
            if (bits[i])
                cnt++;
            else
                break;
        return !(cnt & 1);
    };
};