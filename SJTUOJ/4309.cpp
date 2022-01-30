#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	const int Y = 100;
	int n; cin >> n;
	int** B = new int* [Y + 1];
	for (int j = 1; j <= Y; j++)
		B[j] = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> B[1][i];
	for (int j = 2; j <= Y; j++)
	{
		for (int i = 1; i <= n + 1 - j; i++)
		{
			B[j][i] = B[j - 1][i] > B[j - 1][i + 1] ? B[j - 1][i] : B[j - 1][i + 1];
		}
	}
	int m; cin >> m;
	int l, r, len, k, yushu, max_tmp;
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		len = r - l + 1;
		if (len <= Y)
			printf("%d\n", B[len][l]);
		else
		{
			k = len / Y;
			yushu = len - k * Y;
			max_tmp = B[1][l];
			for (int i = 0; i < k; i++)
			{
				max_tmp = B[Y][l + Y * i] > max_tmp ? B[Y][l + Y * i] : max_tmp;
			}
			if (yushu != 0) max_tmp = max_tmp > B[yushu][r - yushu + 1] ? max_tmp : B[yushu][r - yushu + 1];
			printf("%d\n", max_tmp);
		}
	}
	return 0;
}