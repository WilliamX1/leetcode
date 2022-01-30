#include <iostream>

using namespace std;

struct node
{
    int l;
    int r;
    node():l(-1), r(-1){};
};
node A[10010];

void mirror(int x)
{
    if (A[x].l != -1) mirror(A[x].l);
    if (A[x].r != -1) mirror(A[x].r);

    //交换当前节点左右子树
    int tmp, tmp1, tmp2;
    tmp = A[x].l;
    A[x].l = A[x].r;
    A[x].r = tmp;
}

void traverse(int x)
{
    if (A[x].l != -1) traverse(A[x].l);
    if (A[x].r != -1) traverse(A[x].r);
    cout << x << " ";
}

int main()
{
    int n; cin >> n;
    int x, y, z, root;

    cin >> x >> y >> z; root = x;
    A[x].l = y;
    A[x].r = z;

    for (int i = 2; i <= n; i++)
    {
        cin >> x >> y >> z;
        A[x].l = y;
        A[x].r = z;
    }

    mirror(root);
    traverse(root);

    return 0;
}
