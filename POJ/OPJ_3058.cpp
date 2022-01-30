#include <iostream>
#include <stack>
using namespace std;

struct node
{
    long long int height;
    long long int label;
    node(long long int h, long long int l):height(h), label(l){};
    node(){};
};

long long int A[80010];

int main()
{
    stack<node> s;
    int N; scanf("%d", &N);

    s.push(node(1000000000 + 7, 0));  //…Ë÷√◊Û±ﬂ«Ω

    for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);

    long long int tmp;
    long long int sum = 0;
    for (long long int i = 1; i <= N; i++)
    {
        tmp = A[N - i + 1];
        while(s.top().height < tmp) s.pop();
        sum += i - s.top().label - 1;
        s.push(node(tmp, i));
    }
    printf("%lld", sum);
    return 0;
}
