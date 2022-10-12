class Solution
{
  public:
    int lastMaterial(vector<int> &material)
    {
        while (material.size() > 1)
        {
            sort(material.begin(), material.end(), greater<int>());
            material[0] -= material[1];
            material.erase(material.begin() + 1);
            if (material[0] == 0)
                material.erase(material.begin());
        };
        return material.empty() ? 0 : material[0];
    }
};