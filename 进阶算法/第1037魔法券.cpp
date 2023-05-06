#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
//ѭ��ûʲô���õģ��ܱ����ͱ���

using namespace std;
const int maxn = 1e5+10;
long nc, np;

long NC[maxn], NP[maxn];//�����ÿ������Ҳ��long��һ��Ҫע�����ͣ�
int main()
{
	
	cin >> nc;
	for (int i = 0; i < nc; i++)
	{
		cin >> NC[i];
	}
	cin >> np;
	for (int i = 0; i < np; i++)
		cin >> NP[i];

	sort(NC, NC + nc);
	sort(NP, NP + np);

	int pos1 = nc - 1, pos2 = np - 1;
	long long ans = 0;
	while (pos1 >= 0 && pos2 >= 0 && NC[pos1] > 0 && NP[pos2] > 0)
	{
		ans += (long long)NC[pos1] * NP[pos2];//��ֹ������
		pos1--;
		pos2--;
	}

	int pos3 = 0, pos4 = 0;
	while (pos3 < nc && pos4 < np && NC[pos3] < 0 && NP[pos4] < 0)
	{
		ans+= (long long)NC[pos3] * NP[pos4];
		pos3++;
		pos4++;
	}

	cout << ans;
	

	return 0;
}


