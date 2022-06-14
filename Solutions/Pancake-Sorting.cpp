class Solution
{
  public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> ans;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > arr[i - 1])
                continue;
            else if (arr[i] < arr[i - 1])
            {
                int idx = upper_bound(arr.begin(), arr.begin() + i, arr[i]) - arr.begin();
                if (idx - 1 + 1 > 1)
                    ans.push_back(idx - 1 + 1);
                if (i - 1 + 1 > 1)
                    ans.push_back(i - 1 + 1);
                if (i + 1 > 1)
                    ans.push_back(i + 1);
                if (idx + 1 > 1)
                    ans.push_back(idx + 1);

                for (int j = i - 1; j >= 0; j--)
                    if (arr[j] > arr[j + 1])
                        swap(arr[j], arr[j + 1]);
                    else
                        break;
            };
        };
        return ans;
    }
};