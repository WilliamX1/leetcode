class LUPrefix
{
  public:
    int ptr = 1, n;
    vector<bool> nums;
    LUPrefix(int n)
    {
        nums = vector<bool>(n + 1, false);
        this->n = n;
    }

    void upload(int video)
    {
        nums[video] = true;
        while (ptr <= n && nums[ptr])
            ptr++;
    }

    int longest()
    {
        return ptr - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */