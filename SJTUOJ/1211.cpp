#include <iostream>

using namespace std;

class bTree
{
    struct node
    {
        int left;
        int right;
        int parent;
        node(int p = 0):parent(p){};
    };
    node* A;  //存放结点的数组
    int root;  //头结点位置
    int length;  //数组长度
public:
    bTree();
    bool isCBT();
};
bTree::bTree()
{
    scanf("%d",&length);
    A = new node[length + 1];
    for (int i = 1; i <= length; i++)
    {
        scanf("%d%d",&A[i].left,&A[i].right);
        if (A[i].left) A[A[i].left].parent = i;
        if (A[i].right) A[A[i].right].parent = i;
    }
    root = 1;
    while(A[root].parent != 0) root = A[root].parent;  //寻找根结点
}
bool bTree::isCBT()
{
    int *B = new int[2 * length + 1];  //模拟一个栈
    int cur_out = 1; B[1] = root;
    int cur_in = 1;
    while(B[cur_out] != 0)
    {
        B[++cur_in] = A[B[cur_out]].left;
        B[++cur_in] = A[B[cur_out]].right;
        cur_out++;
    };
    for (int i = cur_out; i <= cur_in; i++)
        if (B[i] != 0) return false;
    return true;
}
int main()
{
    bTree T;
    if (T.isCBT()) printf("%c",'Y');
    else printf("%c",'N');
    return 0;
}
