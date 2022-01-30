#include <iostream>
using namespace std;

int main()
{
	int N; cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int k; cin >> k;
	double b, c, D;
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> b >> c;
		D = b * b / 4 / c;
		/*for (int j = 0; j < N; j++)
			sum += D >= A[j] ? 1 : 0;
		cout << sum << endl;
		*/
		if (A[0] > D)
		{
			cout << 0 << endl;
			continue;
		}
		if (A[N - 1] <= D)
		{
			cout << N << endl;
			continue;
		}
		int left = 0;
		int right = N;
		int mid = (left + right) / 2;
		while (A[mid] > D || A[mid + 1] <= D)
		{
			if (A[mid] > D)
			{
				right = mid;
				mid = (left + right) / 2;
			}
			else if (A[mid] <= D)
			{
				left = mid;
				mid = (left + right) / 2;
			}
		}
		cout << mid + 1 << endl;
	}
	
	return 0;
}