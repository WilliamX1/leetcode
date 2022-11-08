class Solution
{
  public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int ans = max(0, accumulate(energy.begin(), energy.end(), 0) + 1 - initialEnergy);

        int exp = initialExperience;
        for (const int &e : experience)
        {
            ans += max(0, e - exp + 1);
            exp += max(0, e - exp + 1) + e;
        };

        return ans;
    }
};