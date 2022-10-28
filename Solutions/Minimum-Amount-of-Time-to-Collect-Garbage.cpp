class Solution
{
  public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        vector<int> sM, sP, sG;
        for (int i = 0; i < garbage.size(); i++)
        {
            for (const char &ch : garbage[i])
            {
                if (ch == 'M')
                    sM.push_back(i);
                else if (ch == 'P')
                    sP.push_back(i);
                else if (ch == 'G')
                    sG.push_back(i);
            };
        };

        vector<int> prefix(travel.size() + 1, 0);
        for (int i = 0; i < travel.size(); i++)
            prefix[i + 1] = prefix[i] + travel[i];

        return sM.size() + sP.size() + sG.size() + (sM.empty() ? 0 : prefix[sM.back()]) +
               (sP.empty() ? 0 : prefix[sP.back()]) + (sG.empty() ? 0 : prefix[sG.back()]);
    }
};