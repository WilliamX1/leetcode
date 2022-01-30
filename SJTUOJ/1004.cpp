#include <iostream>
using namespace std;

int main()
{
	int M, T, U, F, D; cin >> M >> T >> U >> F >> D;
	char* A = new char[T + 1];
	int sum = 0;
	for (int i = 1; i <= T; i++)
		cin >> A[i];
	for (int i = 1; i <= T; i++)
	{
		if (A[i] == 'u' || A[i] == 'd')
			sum += U + D;
		else if (A[i] == 'f')
			sum += 2 * F;
		if (sum > M)
		{
			cout << i - 1;
			break;
		}
	}
	return 0;
}