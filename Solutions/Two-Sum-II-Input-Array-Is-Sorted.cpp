class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            while (left < right && numbers[left] + numbers[right] > target)
                right--;
            if (left < right && numbers[left] + numbers[right] == target)
                return {left + 1, right + 1};
            else
                left++;
        };
        return {};
    }
};