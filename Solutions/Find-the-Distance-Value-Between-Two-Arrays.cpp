class Solution
{
  public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int ans = 0;
        int len1 = arr1.size(), len2 = arr2.size(), i, j;
        for (i = 0; i < len1; i++)
        {
            for (j = 0; j < len2; j++)
            {
                if (abs(arr1[i] - arr2[j]) <= d)
                    break;
            };
            ans += j == len2;
        }
        return ans;
    }
};