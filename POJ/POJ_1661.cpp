#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int x;
    int y;
    int h;
};
bool myCompare(node A, node B){return A.h < B.h;};
int main()
{
    int t, i, j, k, s; cin >> t;
    int N; int MAX;

    for (i = 1; i <= t; i++)
    {
        cin >> N;
        node* A = new node[N + 1];
        int *LeftMinTime = new int[N + 1];
        int *RightMinTime = new int[N + 1];

        for (j = 0; j <= N; j++)
            cin >> A[j].x >> A[j].y >> A[j].h;
        MAX = A[0].h; A[0].h = A[0].y; A[0].y = A[0].x;
        sort(A, A + N + 1, myCompare);

        for (j = 0; j <= N; j++)
        {
            for (k = j - 1; k >= 0; k--)
                if (A[j].x >= A[k].x && A[j].x <= A[k].y)  //找到左端点符合的平台
                    break;
            if (k == -1)  //没有找到
                if (A[j].h > MAX)  //
                    LeftMinTime[j] = 200000000;  //等效为正无穷
                else LeftMinTime[j] = A[j].h;
            else
                if (A[j].h - A[k].h > MAX)
                    LeftMinTime[j] = 200000000;
                else LeftMinTime[j] = A[j].h - A[k].h + min(LeftMinTime[k] + A[j].x - A[k].x, RightMinTime[k] + A[k].y - A[j].x);

            for (k = j - 1; k >= 0; k--)
                if (A[j].y >= A[k].x && A[j].y <= A[k].y)  //找到右端点符合的平台
                    break;
            if (k == -1)  //没有找到
                if (A[j].h > MAX)  //
                    RightMinTime[j] = 200000000;  //等效为正无穷
                else RightMinTime[j] = A[j].h;
            else
                if (A[j].h - A[k].h > MAX)
                    RightMinTime[j] = 200000000;
                else RightMinTime[j] = A[j].h - A[k].h + min(LeftMinTime[k] + A[j].y - A[k].x, RightMinTime[k] + A[k].y - A[j].y);
        }

        cout << min(LeftMinTime[N], RightMinTime[N]) << endl;
    }
    return 0;
}
