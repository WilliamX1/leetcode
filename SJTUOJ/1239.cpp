#include <bits/stdc++.h>

using namespace std;

int main()
{
    double salary; cin >> salary;
    double sum = 0;

    if (salary <= 3500)
    {
        cout << floor(sum);
        return 0;
    }else salary -= 3500;

    if (salary <= 1500)
    {
        sum += 0.03 * salary;
        cout << floor(sum);
        return 0;
    }else sum += 45;

    if (salary <= 4500)
    {
        sum += 0.10 * (salary - 1500);
        cout << floor(sum);
        return 0;
    }else sum += 300;

    if (salary <= 9000)
    {
        sum += 0.20 * (salary - 4500);
        cout << floor(sum);
        return 0;
    }else sum += 900;

    if (salary <= 35000)
    {
        sum += 0.25 * (salary - 9000);
        cout << floor(sum);
        return 0;
    }else sum += 6500;

    if (salary <= 55000)
    {
        sum += 0.30 * (salary - 35000);
        cout << floor(sum);
        return 0;
    }else sum += 6000;

    if (salary <= 80000)
    {
        sum += 0.35 * (salary - 55000);
        cout << floor(sum);
        return 0;
    }else sum += 8750;

    if (salary > 80000)
    {
        sum += 0.45 * (salary - 80000);
        cout << floor(sum);
        return 0;
    }
    return 0;
}
