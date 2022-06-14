class Solution
{
  public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        int ans = 0;
        char ch;
        keysPressed.insert(keysPressed.begin(), ' ');
        releaseTimes.insert(releaseTimes.begin(), 0);
        for (int i = releaseTimes.size() - 1; i >= 1; i--)
        {
            releaseTimes[i] -= releaseTimes[i - 1];
            if (releaseTimes[i] > ans || releaseTimes[i] == ans && keysPressed[i] > ch)
            {
                ans = releaseTimes[i];
                ch = keysPressed[i];
            };
        };
        return ch;
    }
};