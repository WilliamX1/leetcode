class Solution
{
  public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        bool flag1 = false, flag2 = false, flag3 = false;
        for (const vector<int> &tri : triplets)
        {
            if (tri[0] == target[0] && tri[1] <= target[1] && tri[2] <= target[2])
                flag1 = true;
            if (tri[1] == target[1] && tri[0] <= target[0] && tri[2] <= target[2])
                flag2 = true;
            if (tri[2] == target[2] && tri[0] <= target[0] && tri[1] <= target[1])
                flag3 = true;
        };
        return flag1 && flag2 && flag3;
    };
};