class Solution
{
  public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int stu_cnt = 0, sand = 0;
        while (!students.empty() && stu_cnt < students.size())
        {
            if (students.front() == sandwiches[sand])
            {
                students.erase(students.begin());
                stu_cnt = 0;
                sand++;
            }
            else
            {
                students.push_back(students.front());
                students.erase(students.begin());
                stu_cnt++;
            };
        };
        return sandwiches.size() - sand;
    }
};