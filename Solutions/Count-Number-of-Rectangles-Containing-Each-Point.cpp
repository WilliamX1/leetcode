class Solution
{
  public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        sort(rectangles.begin(), rectangles.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        for (int i = 0; i < points.size(); ++i)
            points[i].push_back(i);
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        vector<int> answer(points.size(), 0);
        vector<vector<vector<int>>> pp(100 + 1);
        for (const vector<int> &point : points)
            pp[point[1]].push_back(point);

        for (int h = 1; h <= 100; h++)
        {
            vector<vector<int>> new_rec;
            // for (auto iter = rectangles.begin(); iter != rectangles.end();) {
            //     if ((*iter)[1] < h) {
            //         iter = rectangles.erase(iter);
            //     } else iter++;
            // };
            if (pp[h].empty())
                continue;
            for (const vector<int> &rec : rectangles)
            {
                if (rec[1] >= h)
                {
                    new_rec.push_back(rec);
                };
            };
            rectangles = new_rec;

            int i = 0;
            for (const vector<int> &v : pp[h])
            {
                int l = v[0], h = v[1], idx = v[2], n = rectangles.size();
                while (i < n && rectangles[i][0] < l)
                {
                    i++;
                };
                answer[idx] = n - i;
            };
        };
        return answer;
    }
};