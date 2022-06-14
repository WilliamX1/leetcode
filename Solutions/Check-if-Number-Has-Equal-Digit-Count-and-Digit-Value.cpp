class Solution
{
  public:
    bool digitCount(string num)
    {
        for (int i = 0; i < num.length(); i++)
        {
            int count = 0;
            for (int j = 0; j < num.length(); j++)
                count += num[j] - '0' == i;
            // cout << count << endl;
            if (count != num[i] - '0')
                return false;
        }
        return true;
    }
};