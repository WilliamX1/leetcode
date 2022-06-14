class Solution
{
  public:
    bool validMountainArray(vector<int> &arr)
    {
        int idx = 1, N = arr.size();
        if (N < 3)
            return false;
        while (idx < N && arr[idx] > arr[idx - 1])
            idx++;
        if (idx == 1 || idx == N)
            return false;
        while (idx < N && arr[idx] < arr[idx - 1])
            idx++;
        return idx == N;
    }
};