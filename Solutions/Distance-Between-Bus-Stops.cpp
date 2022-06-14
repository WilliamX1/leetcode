class Solution
{
  public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        if (start > destination)
            swap(start, destination);
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < start; i++)
            ans1 += distance[i];
        for (int i = start; i < destination; i++)
            ans2 += distance[i];
        for (int i = destination; i < distance.size(); i++)
            ans1 += distance[i];
        return min(ans1, ans2);
    }
};