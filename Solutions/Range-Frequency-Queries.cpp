class RangeFreqQuery
{
  public:
    vector<int> arr;
    unordered_map<int, vector<int>> umap;
    RangeFreqQuery(vector<int> &arr)
    {
        this->arr = arr;
        for (int i = 0; i < arr.size(); i++)
            umap[arr[i]].push_back(i);
    };

    int query(int left, int right, int value)
    {
        const vector<int> &v = umap[value];
        return upper_bound(v.begin(), v.end(), right) - lower_bound(v.begin(), v.end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */