class Solution
{
  public:
    int distributeCandies(vector<int> &candyType)
    {
        set<int> s;
        int cnt = 0, up = candyType.size() / 2;
        for (int candy : candyType)
            if (s.find(candy) == s.end())
            {
                s.insert(candy);
                if (++cnt < up)
                    continue;
                else
                    return up;
            };
        return cnt;
    }
};