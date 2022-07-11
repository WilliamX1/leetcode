class SmallestInfiniteSet
{
  public:
    vector<bool> nums;
    SmallestInfiniteSet()
    {
        nums = vector<bool>(1e3 + 7, true);
    }

    int popSmallest()
    {
        int i;
        for (i = 1; i <= 1e3; i++)
            if (nums[i])
            {
                nums[i] = false;
                break;
            };
        return i;
    }

    void addBack(int num)
    {
        nums[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */