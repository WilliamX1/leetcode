#include <iostream>
#include <queue>
using namespace std;

struct nodeff  //定义结构体
{
    int data1, data2;  //存储分母，分子
    double num;    //存储数值大小
    nodeff(const int& d1, const int& d2, const double& n) :data1(d1), data2(d2), num(n) {};
    nodeff() {};
    friend bool operator < (nodeff a,nodeff b)
    {
        return a.num > b.num;
    }  //重新定义比较函数
    
};
int gcd(int m, int n)
{
    while (m > 0)
    {
        int c = n % m;
        n = m;
        m = c;
    }
    return n;
}//最大公约数n为1时两数互质
int main()
{
	priority_queue<nodeff> q;
	int N; cin >> N;
    nodeff tmp(0,1,0);
	q.push(tmp);
    tmp.data1 = tmp.data2 = tmp.num = 1;
    q.push(tmp);
	for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            if (gcd(j, i) == 1)  //如果不互质，则跳过
            {
                tmp.data1 = i;
                tmp.data2 = j;
                tmp.num = double(i) / j;
                q.push(tmp);
            }
    while (!q.empty())
    {
        cout << q.top().data1 << "/" << q.top().data2 << endl;
        q.pop();
    }
    return 0;
}