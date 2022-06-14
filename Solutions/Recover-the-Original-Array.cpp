#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> recoverArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size(), k2, left, right;
        vector<bool> havebeen(n);
        vector<int> answer;
        for (int i = 1; i < n; i++)
        { // 2 * k = nums[i] - nums[0]
            k2 = nums[i] - nums[0];
            if (k2 & 1 || k2 == 0)
                continue;

            std::fill(havebeen.begin(), havebeen.end(), false);
            answer.clear();

            left = 0, right = i;

            while (left < n)
            {
                if (havebeen[left])
                    left++;
                else
                {
                    while (right < n && (havebeen[right] || right <= left || nums[left] + k2 > nums[right]))
                        right++;
                    if (right < n && nums[left] + k2 == nums[right])
                    {
                        havebeen[left] = havebeen[right] = true;
                        answer.push_back(nums[left] + (k2 >> 1));
                    }
                    else
                    {
                        k2 = -1;
                        break;
                    };
                }
            }
            if (k2 != -1)
                break;
        };
        return answer;
    }
};