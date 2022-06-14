#include <bits/stdc++.h>

using namespace std;

class FindSumPairs
{
  private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;

  public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2)
            ++cnt[num];
        return;
    }

    void add(int index, int val)
    {
        --cnt[nums2[index]];
        nums2[index] += val;
        ++cnt[nums2[index]];
        return;
    }

    int count(int tot)
    {
        int ans = 0;
        for (int num : nums1)
        {
            int rest = tot - num;
            if (cnt.count(rest))
            {
                ans += cnt[rest];
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> v1 = {1, 1, 2, 2, 2, 3};
    vector<int> v2 = {1, 4, 5, 2, 5, 4};
    FindSumPairs F(v1, v2);
    printf("%d", F.count(7));
    return 0;
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */