class Allocator
{
  public:
    vector<int> free_buck;
    int total_size;
    Allocator(int n)
    {
        free_buck = vector<int>(n, 0);
        total_size = n;
    }

    int allocate(int size, int mID)
    {
        int left = 0, right = 0;
        while (left < total_size)
        {
            while (right < total_size && free_buck[right] == 0 && right - left + 1 < size)
                right++;
            if (right < total_size && free_buck[right] == 0 && right - left + 1 == size)
            {
                for (int i = left; i <= right; i++)
                    free_buck[i] = mID;
                return left;
            }
            else
                right = left = right + 1;
        };
        return -1;
    }

    int free(int mID)
    {
        int ans = 0;
        for (int i = 0; i < total_size; i++)
            if (free_buck[i] == mID)
            {
                free_buck[i] = 0;
                ans++;
            };
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */