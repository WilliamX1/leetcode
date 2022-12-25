class Solution
{
  public:
    int maximumTastiness(vector<int> &price, int k)
    {
        int left = 0, right = *max_element(price.begin(), price.end());
        sort(price.begin(), price.end());

        while (left <= right)
        {
            int mid = (left + right) >> 1;

            int kk = k, cur_idx = 0;
            while (--kk)
            {
                if (price.back() < price[cur_idx] + mid)
                    break;
                else
                    cur_idx = lower_bound(price.begin(), price.end(), price[cur_idx] + mid) - price.begin();
            }
            if (kk == 0)
                left = mid + 1;
            else
                right = mid - 1;
        };
        return right;
    }
};