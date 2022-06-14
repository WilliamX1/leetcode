class Solution
{
  public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        set<int> tot, last;
        tot.insert(arr[0]);
        last.insert(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {
            set<int> cur;
            cur.insert(arr[i]);
            tot.insert(arr[i]);
            for (const int &num : last)
            {
                cur.insert(arr[i] | num);
                tot.insert(arr[i] | num);
            };
            last = cur;
        };
        return tot.size();
    }
};