class Solution
{
  public:
    bool in(const multimap<pair<int, int>, bool> &steps, int x, int y, int xup, int yup)
    {
        if (!xup && x || !yup && y)
            return false;
        int loop_num = min(x / xup, y / yup);
        return steps.find(make_pair(x - xup * loop_num, y - yup * loop_num)) != steps.end();
    };
    bool robot(string command, vector<vector<int>> &obstacles, int x, int y)
    {
        int xx = 0, yy = 0, index = 0;
        multimap<pair<int, int>, bool> steps;
        steps.insert(make_pair(make_pair(xx, yy), true));
        for (const char &ch : command)
        {
            if (ch == 'U')
                yy++;
            else if (ch == 'R')
                xx++;
            steps.insert(make_pair(make_pair(xx, yy), true));
        };

        if (!in(steps, x, y, xx, yy))
            return false;
        for (const vector<int> &ob : obstacles)
            if ((ob[0] <= x && ob[1] <= y && (ob[0] != x || ob[1] != y)) && in(steps, ob[0], ob[1], xx, yy))
                return false;

        return true;
    }
};