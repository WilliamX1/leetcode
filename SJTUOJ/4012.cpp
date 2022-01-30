#include <iostream>

using namespace std;
int divide(int *A, int left, int right)
{
    int k = A[left];
    do
    {
        while (left < right && A[right] >= k) right--;
        if (left < right){A[left] = A[right]; left++;};
        while (left < right && A[left] <= k) left++;
        if (left < right){A[right] = A[left]; right--;};
    }while(left != right);
    A[left] = k;
    return left;
}
void quickSort(int *A, int left, int right)
{
    if (left >= right) return;
    int mid = divide(A,left,right);
    quickSort(A,left,mid - 1);
    quickSort(A,mid + 1,right);
}
int main()
{
    int n; scanf("%d",&n);
    int *A = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&A[i]);
    quickSort(A,0,n - 1);

    long long int sum = 0;
    int i,j,tmp;
    for (i = 0; i < n - 1; i++)
    {
        tmp = A[i] + A[i + 1];
        sum += tmp;
        for (j = i + 2; j < n && A[j] < tmp; j++)
            A[j - 1] = A[j];
        A[j - 1] = tmp;
    }
    cout << sum;
    return 0;
}
