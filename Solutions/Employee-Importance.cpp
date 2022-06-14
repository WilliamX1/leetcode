#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

// Definition for Employee.
class Employee
{
  public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
  public:
    static bool compare(Employee *A, Employee *B)
    {
        return A->id < B->id;
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        sort(employees.begin(), employees.end(), compare);
        /*保存id与下标关系*/
        map<int, int> id_idx;
        for (int i = 0; i < employees.size(); i++)
            id_idx[employees[i]->id] = i;

        set<int> staff_have;
        set<int> staff_tmp;
        int idx = 0, res = 0;
        while (idx < employees.size() && employees[idx]->id != id)
            idx++;

        staff_have.insert(employees[idx]->id);
        staff_tmp.insert(employees[idx]->id);

        while (!staff_tmp.empty())
        {
            int cur = *staff_tmp.begin();
            staff_tmp.erase(staff_tmp.begin());
            staff_have.insert(employees[id_idx[cur]]->id);
            res += employees[id_idx[cur]]->importance;
            for (int i = 0; i < employees[id_idx[cur]]->subordinates.size(); i++)
                if (staff_have.find(employees[id_idx[cur]]->subordinates[i]) == staff_have.end())
                    staff_tmp.insert(employees[id_idx[cur]]->subordinates[i]);
        };
        return res;
    }
};