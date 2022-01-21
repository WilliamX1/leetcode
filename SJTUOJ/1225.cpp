#include <iostream>
using namespace std;

int qSort(int* A, int left, int right);
void quickSort();
void quickSort(int* A, int left, int right);

int qSort(int* A, int left, int right)
{
	int k = A[left];
	do
	{
		while (left < right && A[right] >= k) right--;
		if (left < right) { A[left] = A[right]; left++; };
		while (left < right && A[left] <= k) left++;
		if (left < right) { A[right] = A[left]; right--; };
	} while (left != right);
	A[left] = k;
	return left;
}
void quickSort()
{
	int N; cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	quickSort(A, 0, N - 1);

	int cur = A[0];  //当前值
	int sum = 1;
	for (int i = 0; i < N; i++)
	{
		if (A[i] > cur)
		{
			cur = A[i];
			sum++;
		}
	}
	cout << sum;
	return;
}
void quickSort(int* A, int left, int right)
{
	int mid;
	if (left >= right) return;
	mid = qSort(A, left, right);
	quickSort(A, left, mid - 1);
	quickSort(A, mid + 1, right);
	return;
}
int main()
{
	quickSort();
	return 0;
}