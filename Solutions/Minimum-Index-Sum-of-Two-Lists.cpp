class Solution
{
  public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        int idxs = 0x7fffffff;
        vector<string> ans;
        for (int i = 0; i < list1.size(); i++)
            for (int j = 0; j < list2.size(); j++)
            {
                if (list1[i] == list2[j])
                {
                    if (i + j == idxs)
                    {
                        ans.push_back(list1[i]);
                    }
                    else if (i + j < idxs)
                    {
                        idxs = i + j;
                        ans.clear();
                        ans.push_back(list1[i]);
                    };
                };
            };
        return ans;
    }
};