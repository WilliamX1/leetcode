class Solution
{
  public:
    struct node
    {
        int height;
        string name;
        node(){};
        node(int h, string n) : height(h), name(n){};
    };

    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<node> v;
        for (int i = 0; i < names.size(); i++)
            v.emplace_back(heights[i], names[i]);
        sort(v.begin(), v.end(), [](const node &a, const node &b) { return a.height > b.height; });
        vector<string> ans;
        for (int i = 0; i < v.size(); i++)
            ans.push_back(v[i].name);
        return ans;
    }
};