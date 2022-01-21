#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int N, tmp, ofServers, totalWait, i;
	int *cur = new int[26];
	cin >> N;
	while (N)
	{
		ofServers = N;  //空闲服务台数量
		totalWait = 0;  //总共离开人数
		for (i = 0; i < 26; i++) { cur[i] = 0; }; //初始化

		string store; cin >> store;  //输入一堆顾客
        i = 0;
		while(store[i] != '\0')
		{
			tmp = store[i] - 'A';  //存入相应标号
			if (ofServers == 0)  //无空闲台子
			{
				if (cur[tmp] == 2)  //没有晒到离开时
					totalWait++;
				else if (cur[tmp] == 0) //进来时晒不到
					cur[tmp] = 2;
				else  //晒到了离开时
					ofServers++;
			}
			else
				switch (cur[tmp])
				{
				case 0:ofServers--; cur[tmp] = 1; break;
				case 1:ofServers++; cur[tmp] = 0; break;
				case 2:totalWait++;
				}
            i++;
		}
		if (totalWait == 0)
			cout << "All customers tanned successfully." << endl;
		else
			cout << totalWait << " customer(s) walked away." << endl;
		cin >> N;
	}
	return 0;
}
