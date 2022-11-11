class OrderedStream
{
  public:
    vector<string> nums;
    int ptr;
    OrderedStream(int n)
    {
        nums = vector<string>(n + 1, "");
        ptr = 1;
    }

    vector<string> insert(int idKey, string value)
    {
        nums[idKey] = value;

        vector<string> ans;
        while (ptr < nums.size() && nums[ptr] != "")
            ans.push_back(nums[ptr++]);
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */