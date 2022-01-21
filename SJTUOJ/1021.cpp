#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n; cin >> n;
	int **A = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		A[i] = new int[n + 1];
	A[1][1] = 1;
	int x_min = 1, x_max = n, y_min = 1, y_max = n;
	int dir = 1;  //0上 1左 2下 3右
	int xcur = 1, ycur = 2;
	for (int i = 2; i <= n*n; i++)
	{
		if (xcur == x_min && ycur == y_min && dir == 0)
		{
			y_min++; dir = (++dir) % 4;
		}
		else if (xcur == x_min && ycur == y_max && dir == 1)
		{
			x_min++; dir = (++dir) % 4;
		}
		else if (xcur == x_max && ycur == y_min && dir == 3)
		{
			x_max--; dir = (++dir) % 4;
		}
		else if (xcur == x_max && ycur == y_max && dir == 2)
		{
			y_max--; dir = (++dir) % 4;
		};
		A[xcur][ycur] = i;
		switch (dir)
		{
		    case 0:xcur--; break;
			case 1:ycur++; break;
			case 2:xcur++; break;
			case 3:ycur--; break;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cout << setw(6) << A[i][j];
	return 0;
}