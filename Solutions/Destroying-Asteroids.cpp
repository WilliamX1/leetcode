class Solution
{
  public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end(), less<int>());
        int64_t m = mass;
        for (int i = 0; i < asteroids.size(); i++)
            if (m >= asteroids[i])
                m += asteroids[i];
            else
                return false;
        return true;
    }
};