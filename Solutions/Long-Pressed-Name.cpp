class Solution
{
  public:
    bool isLongPressedName(string name, string typed)
    {
        int tot1 = 0, tot2 = 0, idx1 = 0, idx2 = 0, n1 = name.size(), n2 = typed.size();
        while (idx1 < n1 && idx2 < n2)
        {
            if (name[idx1] != typed[idx2])
                return false;
            tot1 = tot2 = 1;
            idx1++;
            idx2++;
            while (idx1 < n1 && name[idx1] == name[idx1 - 1])
            {
                idx1++;
                tot1++;
            };
            while (idx2 < n2 && typed[idx2] == typed[idx2 - 1])
            {
                idx2++;
                tot2++;
            };
            // cout << idx1 << ' ' << idx2 << ' ' << tot1 << ' ' << tot2 << endl;

            if (tot1 > tot2)
                return false;
        };
        return idx1 >= n1 && idx2 >= n2;
    }
};