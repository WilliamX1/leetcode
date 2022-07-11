class Solution
{
  public:
    bool canChange(string start, string target)
    {
        int index_start = 0, size_start = start.size(), index_target = 0, size_target = target.size();
        while (index_start < size_start && index_target < size_target)
        {
            while (index_target < size_target && target[index_target] == '_')
                index_target++;
            while (index_start < size_start && start[index_start] == '_')
                index_start++;

            if (index_target >= size_target || index_start >= size_start)
                break;
            else
            {
                if (target[index_target] != start[index_start])
                    return false;
                else if (target[index_target] == 'L' && index_start < index_target)
                    return false;
                else if (target[index_target] == 'R' && index_start > index_target)
                    return false;
                else
                {
                    index_target++;
                    index_start++;
                };
            };
        };

        while (index_target < size_target && target[index_target] == '_')
            index_target++;
        while (index_start < size_start && start[index_start] == '_')
            index_start++;
        return index_target == size_target && index_start == size_start;
    }
};