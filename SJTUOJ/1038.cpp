#include <iostream>

using namespace std;

int M, j;

class linkList
{
private:
    struct node
    {
        int num;
        node* next;
        node* pre;
        node(int n, node* p = NULL, node* N = NULL):num(n),pre(p),next(N){};
    };
    node* head;
public:
    linkList(int M)
    {
        head = new node(1); head->pre = head->next = head;
        node* tmp = head;
        for (int i = 2; i <= M; i++)
            tmp = tmp->next = new node(i, tmp);
        tmp->next = head;
        head->pre = tmp;
    }
    int Ysf(int K)
    {
        K--;
        K %= M - j;
        for (int i = 1; i <= K; i++)
            head = head->next;
        head->pre->next = head->next;
        head->next->pre = head->pre;
        head = head->next;

        return head->num;
    }

};
int main()
{
    cin >> M;
    linkList L(M);

    int tmp;

    for (j = 0; j < M - 1; j++)
    {
        cin >> tmp;
        L.Ysf(tmp);
    }
    cout << L.Ysf(0);
    return 0;
}
