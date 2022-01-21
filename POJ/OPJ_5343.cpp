#include <iostream>
#include <queue>

using namespace std;

struct node
{
    char ch;
    int num;
    node(char c, int n):ch(c), num(n){};
    node(){};
};

queue<char> B[10];
queue<int> C[4];
queue<node> res;

int main()
{
    int N; scanf("%d", &N);

    char ch;
    int num;
    for (int i = 1; i <= N; i++)
    {
        cin >> ch >> num;
        B[num].push(ch);
    }
    for (int i = 1; i <= 9; i++)
    {
        cout << "Queue" << i << ":";
        while(!B[i].empty())
        {
            cout << B[i].front() << i << " ";
            C[B[i].front() - 'A'].push(i);
            B[i].pop();
        }
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        char tmp = 'A' + i;
        cout << "Queue" << tmp << ":";
        while(!C[i].empty())
        {
            cout << tmp << C[i].front() << " ";
            res.push(node(tmp, C[i].front()));
            C[i].pop();
        }
        cout << endl;
    }

    while(!res.empty())
    {
        cout << res.front().ch << res.front().num << " ";
        res.pop();
    }
    return 0;
}
