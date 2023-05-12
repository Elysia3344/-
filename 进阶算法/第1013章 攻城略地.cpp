

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, k;
int occupied, cnt = 0;
//vector<int>city;err
//��Ҫ�����������һ���Ǹ�����һ���Ǻ���
//��һ�����ǿ����ж�����ӵģ����ԣ�����Ҫ������һ��λ�û��к��ӵ�ֵ
//��˾���Ҫ���������͵�int������int��������ź��ӵ�ֵ���������͵������������λ��
//ʹ�õ�ʱ��������������ģ�Ҳ����ֱ��дһ��[]��ʱ���ʾ����ֵ����дһ��[]�͵�����ı�ʾ��ͬ��λ�á�
//int������ֵ���������͵�vector�����㹻�Ŀռ��Ŷ������.
vector<vector<int>>city;
bool visited[1010];

void dfs(int cur)
{
	if (cur == occupied || visited[cur])
		return;

	visited[cur] = true;
	for (int i = 0; i < city[cur].size(); i++)
	{
		dfs(city[cur][i]);
	}
}
int main()
{
	cin >> n >> m >> k;

	int c1, c2;
	city.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> c1 >> c2;
	/*	city[c1] = c2;
		city[c2] = c1;*///err������ȷλ�ã�ֱ��push_back���
		city[c1].push_back(c2);
		city[c2].push_back(c1);

	}

	

	for (int i = 0; i < k; i++)//ѡ����ͬ�ĳ��б�ռ��
	{
		cin >> occupied;
		fill(visited, visited + 1010, false);//��ʼ��
		cnt = 0;
		for (int j = 1; j <= n; j++)//1-n�ĳ�����Ϊ�������
		{
			if (visited[j] != true && j != occupied)
			{
				dfs(j);
				cnt++;
			}
		}

       cout << cnt - 1<<endl;
	}

	
	return 0;
}

//����
//˼������1��ʼ��ÿһ������Ϊ���㣬Ȼ��һֱ����ܷ��ʵ����г��У�
//ֱ������һ�������ܹ�ʹ��ǰ�����г��е�visited֮����ȫ����ͨΪֹ��
//���ȣ����õ���ֹ֮ͣ��ĳ��л᲻���г����ܱ�ǰ�������Ϊ�����ʱ�򸲸ǵĸ��࣬�ܹ��޸����ٵĵ�·��
//��Ϊ���Ǳ��뱣֤���г�����ͨ�����ǰ��Ķ�������ͨ����ĳ��У���ô��ʵ�������Ϊ����������һ���ġ�
//��������ܣ���ô������ǰ��ĳ�����Ϊ���㻹�Ǻ���Ķ��޷�������ͨ�������Ͳ��������ָ��Ǹ���������ʵ��������޷���ͨ��
//��ô�ͻ���Ҫ����һ�����б�����
//
//��ξ���ÿһ�Σ����ǰ���һ�����������ĳ��е���һ������ÿ�λ�һ������Ϊ���㣬�������ӵĳ��о���Ϊһ����
//�������ٵ�·�ķ�������ֱ�ӽ�ÿһ������ֱ����һ��·������������������(�������ô������һ��·��������ͨ����)
//,һֱ������ͨ���г���Ϊֹ��
//
//cnt-1�ܺ���⡣��3��������Ҫ�����߲���ȫ����ͨ.



#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> city;
bool visited[1010];
void dfs(int cur, int occupied)
{
	if (cur == occupied || visited[cur])
		//ֻҪ��ǰ���б�ռ�죬��Ȼ��ǰvisit���ܱ���ǣ���ʾ������ͨ
		//�����visited�Ѿ�����ǣ���˵���Ѿ��ó����Ѿ���ͨ����ֱ�Ӽ�֦��
		return;
	visited[cur] = true;//һֱ��Ƿ��ʱ�ʾ������ͨ�����û�б�Ǿ�˵�����С�������ͨ�ͻ���main�е�ѭ������Ѱ�Ҷ���
	for (int i = 0; i < city[cur].size(); i++)
		dfs(city[cur][i], occupied);

	//֮���Կ����ñ�Ƿ�������Ϊʵ����ֻҪ��������һ������ֻҪ�����ӵ�״̬���������ӷ�ʽ�������ܹ����ʵ����յ��Ǹ����е�
	//��Ϊ�����ظ����ߣ�����ֻҪ�ǳ��˱���ռ�ĳ��У����е�����һ������ֻҪ�ķ��ʹ��ˣ����ǿ������ӵġ�
	//��Ϊһֱ�����ڶ���֮�½�����visit������һֱ����ͨ�ġ�
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	city.resize(n + 1);//������������
	int temp1, temp2;
	for (int i = 1; i <= m; i++)//����ͼ 
	{
		cin >> temp1 >> temp2;
		city[temp1].push_back(temp2);
		city[temp2].push_back(temp1);
		//����1��2���г�Ϊ����Ŀ���
	}
	int occupied, cnt;
	for (int i = 0; i < k; i++)
	{
		cin >> occupied;
		fill(visited, visited + 1010, false);//����visited���� 
		cnt = 0;
		for (int j = 1; j <= n; j++)//����м�����ͨ���� 
			//Ϊʲôһ��Ҫ��1��
			//��Ϊ���������1-N�������occupied��1��ʼ
			//��Ӧ��������

			//���ѭ�������þ��ǽ�ÿһ��û�б�ռ��ĳ��е������㣬��ѯ�Ƿ���ͨ����
			//��Ϊ���ǲ���������ĸ����в��Ƕ��㣬����ȫ������

		{
			if (!visited[j] && j != occupied)
			{
				dfs(j, occupied);
				cnt++;//��ʾһ����ͨ��Ҳ������ͨ����

			}
		}
		cout << cnt - 1 << endl;
	}
	return 0;
}


