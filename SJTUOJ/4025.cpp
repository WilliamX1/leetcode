#include <iostream>
using namespace std;

int divide(long long int* A, int left, int right)
{
	int k = A[left];
	do
	{
		while (left < right && A[right] >= k) --right;
		if (left < right) { A[left] = A[right]; ++left; };
		while (left < right && A[left] <= k) ++left;
		if (left < right) { A[right] = A[left]; --right; };
	} while (left != right);
	A [left] = k;
	return left;
}
void quickSort(long long int* A, int left, int right)
{
	if (left >= right)
		return;
	int mid = divide(A, left, right);
	quickSort(A, left, mid - 1);
	quickSort(A, mid + 1, right);
}

int main()
{
	int X, Y; cin >> X >> Y;
	int N = X * Y;
	long long int* A = new long long int[N];
	

	for (int i = 0; i < N; i++)
		cin >> A[i];
	quickSort(A, 0, N - 1);

    long long int S; cin >> S;
    double result = 0;
	double k = 0;
	for (int i = 1; i < N; i++)
	{
		if (A[i] * i - A[i - 1] >= S)
		{
			result = double((A[i - 1] + S)) / i;
			k = double(100 * i) / N;
			break;
		}
		A[i] += A[i - 1];
	}
	if (result == 0)
	{
		result = double((A[N - 1] + S)) / N;
		k = 100.00;
	}
	printf("%.2f\n%.2f", result, k);
	return 0;
}