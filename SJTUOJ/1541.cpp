#include <iostream>
using namespace std;

int main()
{
	int k, n; cin >> k >> n;
	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i < k; i++)
		for (int j = 1; j <= n - i; j++)
			arr[j] = arr[j] > arr[j + 1] ? arr[j] : arr[j + 1];
	for (int i = 1; i <= n - k + 1; i++)
		cout << arr[i] << " ";
	return 0;
}