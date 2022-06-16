class Solution
{
  public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<int> time_finish(n + 1, 0);
        vector<int> pre_courses_cnt(n + 1, 0);
        vector<vector<int>> next_course_id(n + 1);
        for (const vector<int> &r : relations)
        {
            pre_courses_cnt[r[1]]++;
            next_course_id[r[0]].push_back(r[1]);
        };
        vector<int> already;
        for (int i = 1; i <= n; i++)
            if (!pre_courses_cnt[i])
            {
                already.push_back(i);
                time_finish[i] = time[i - 1];
            };

        while (!already.empty())
        {
            int idx = already.back();
            already.pop_back();

            for (const int &next : next_course_id[idx])
            {
                time_finish[next] = max(time_finish[next], time_finish[idx] + time[next - 1]);
                pre_courses_cnt[next]--;
                if (!pre_courses_cnt[next])
                    already.push_back(next);
            };
        };
        return *max_element(time_finish.begin(), time_finish.end());
    }
};