#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	int len_A = A.length(), len_B = B.length();
	int minus_len = len_A - len_B;
	for (int i = 0; i <= minus_len; ++i)
	{
		if (A[i] != B[0] || A[len_B + i - 1] != B[len_B - 1])
			continue;
		else
		{
			int j = i + 1;
			int out = i + len_B / 2 ;
			while (A[j] == B[j - i] && A[len_B - j + 2*i - 1] == B[len_B + i - j - 1] && ++j && j <= out);
			if (j == out + 1)
			{
				cout << i;
				break;
			}
		}
	}
	return 0;
}