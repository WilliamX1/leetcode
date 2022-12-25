class Solution
{
  public:
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback,
                            vector<string> &report, vector<int> &student_id, int k)
    {
        struct student
        {
            int id;
            int score;
            student(){};
            student(int id, int score = 0) : id(id), score(score){};
        };

        set<string> pf, ng;
        for (string &p : positive_feedback)
            pf.insert(p);
        for (string &n : negative_feedback)
            ng.insert(n);

        int n = student_id.size();
        vector<student> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i].id = student_id[i];
            v[i].score = 0;

            string str;
            for (char &ch : report[i])
            {
                if (ch == ' ')
                {
                    if (pf.count(str))
                        v[i].score += 3;
                    else if (ng.count(str))
                        v[i].score -= 1;
                    str.clear();
                }
                else
                    str.push_back(ch);
            };

            if (pf.count(str))
                v[i].score += 3;
            else if (ng.count(str))
                v[i].score -= 1;
            str.clear();
        };

        // for (int i = 0; i < n; i++)
        //     cout << v[i].id << ' ' << v[i].score << endl;

        sort(v.begin(), v.end(),
             [](const student &a, const student &b) { return a.score == b.score ? a.id < b.id : a.score > b.score; });

        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(v[i].id);
        return ans;
    }
};