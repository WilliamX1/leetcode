#include <bits/stdc++.h>

using namespace std;

struct node
{
    string name;
    string job;
    int value;
    int grade;
    int label;
};
node A[128];

bool myCompare(node a, node b)
{
    if (a.job == "BangZhu") return true;
    if (a.job == "FuBangZhu" && b.job == "BangZhu") return false;
    if (a.job == "FuBangZhu") return true;

    if (a.value == b.value) return a.label < b.label;

    return a.value > b.value;
}

bool myCompare2(node a, node b)
{
    if (a.job == "BangZhu") return true;
    if (a.job == "FuBangZhu" && b.job == "BangZhu") return false;
    if (a.job == "FuBangZhu") return true;

    if (a.job == b.job)
        if (a.grade == b.grade)
            return a.label < b.label;
        else return a.grade > b.grade;

    return false;
}

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i].name >> A[i].job >> A[i].value >> A[i].grade;
        A[i].label = i;
    }

    sort(A + 1, A + n + 1, myCompare);
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            A[i].job = "BangZhu";
        else if (i == 2)
            A[i].job = "FuBangZhu";
        else if (4 <= i && i <= 5)
            A[i].job = "HuFa";
        else if (6 <= i && i <= 9)
            A[i].job = "ZhangLao";
        else if (10 <= i && i <= 16)
            A[i].job = "TangZhu";
        else if (17 <= i && i <= 41)
            A[i].job = "JingYing";
        else
            A[i].job = "BangZhong";
    }
    sort(A + 1, A + n + 1, myCompare2);

    for (int i = 1; i <= n; i++)
        cout << A[i].name << " " << A[i].job << " " << A[i].grade << endl;

    return 0;
}
