typedef long long ll;
class Solution
{
  public:
    long long maximumBeauty(vector<int> &flowers, long long newFlowers, int target, int full, int partial)
    {
        sort(flowers.begin(), flowers.end());

        ll fcnt = 0;
        while (flowers.size() && flowers.back() >= target)
        {
            flowers.pop_back();
            fcnt += 1;
        }

        /* 所有花坛都是 full */
        if (!flowers.size())
        {
            return fcnt * full;
        }

        ll res = 0, sum = 0;
        for (int i = 0; i < flowers.size(); ++i)
        {
            sum += flowers[i];
        }
        ll T = target - 1;

        /* 枚举变为 full 的花坛数量 */
        /* 这里 i = flowers.size() 开始, 代表的是所有的花坛都还是 partial */
        for (int i = flowers.size(), j = i - 1; i >= 0; --i, ++fcnt)
        {
            if (i < (int)flowers.size())
            {
                newFlowers -= target - flowers[i];
            }
            /* 如果 newFlowers 不足以填充 full 的花坛 */
            if (newFlowers < 0)
            {
                break;
            }
            /* 存在 partial */
            if (i > 0)
            {
                /* 双指针 */
                while (j >= i)
                {
                    sum -= flowers[j];
                    j--;
                }
                while (T * (j + 1) - sum > newFlowers)
                {
                    T--;
                    while (flowers[j] >= T)
                    {
                        sum -= flowers[j];
                        j--;
                    }
                }
                res = max(res, T * partial + fcnt * full);
            }
            /* 不存在 partial, 全是 full */
            else
            {
                res = max(res, fcnt * full);
            }
        }

        return res;
    }
};