#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
using namespace std;

//map< int, int<vector> > node;err
map<int, vector<int>>node;
queue<pair<int, int>>q;
vector<int>ans;
//Ҷ�ӽڵ����ֻ���Լ��������治���������ڵ�

void bfs(int x)
{
	int nowlevel = 1;
	int count = 0;
/*q.pushback(nowlevel, count);*///err
	q.push({ x,nowlevel }); //���о���push����������Ҫ������,vector��push_back 
	//�����зŵ��ǽڵ�Ͳ��������ǽڵ��Ҷ�ڵ�����

	
	while (!q.empty())
	{
		int curr = q.front().first;//���.first,currΪ��ǰ�ڵ�
		int newlevel = q.front().second;
		q.pop();

		if (newlevel != nowlevel)
		{
			ans.push_back(count);
			nowlevel = newlevel;
			count = 0;

		}

		if (node[curr].size() == 0)
			count++;

		for (int i = 0; i < node[curr].size(); i++)
		{
			q.push({ node[curr][i],newlevel + 1 });//������һ������ݣ����뵽������

		   /* newlevel += 1;*///������ˣ���������ѭ����һֱ���Ӳ���
			//Ӧ�ð���д�ڲ��������
			//2.������һ�����ڵ�ǰ�ڵ�,
			//��Ҫ��level����curr!

		}

	}

	ans.push_back(count);

}
int main()
{
	int n, m, ID, id, k;
	//     ͷ�ڵ� ��֧�ڵ�
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> ID >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> id;
			node[ID].push_back(id);
		}
	}

	if (m == 0)
	{
		cout << 1;//���ֿ���ֱ��д����""
		return 0;
	}

	bfs(1);
	//�����Ǹ��ڵ�

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i != ans.size() - 1)
		{
			cout << " ";
		}
	}








	return 0;
}

//����
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int N = 150;
map<int, vector<int>> mm;

//map<typename1, typename2> mp;
//���У�typename1�Ǽ�����(�����������ͣ���typename2��ֵ���������ݵĿռ�)�����͡�
int n, m;
vector<int> ans;

void bfs(int x) {
	queue<pair<int, int>> q;
	//һ�����ܲ�����������
	int currLevel = 1;
	int currCount = 0;
	q.push({ x,currLevel });

	while (!q.empty()) {
		int curr = q.front().first;
		int level = q.front().second;
		q.pop();

		if (level != currLevel) {
			ans.push_back(currCount);
			currLevel = level;
			currCount = 0;
		}
		if (mm[curr].size() == 0) //ֻҪ��ǰλ���ӽڵ�����Ϊ0����˵��ΪҶ�ӽڵ㣬����1;
		{
			currCount++;
		}

		for (int i = 0; i < mm[curr].size(); i++) {
			int next = mm[curr][i];
			q.push({ next,level + 1 });
		}//ʵ��bfs

	}
	ans.push_back(currCount);//�������ж���������ʱ�����һ�㻹û���������Ҷ�ڵ���������Ҫ���
	return;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int curr; int count; int t;
		cin >> curr >> count;
		//����curr����ת��û�����
		//�������01��ֵΪ���ͣ���ô�������1�������жϵģ�����ֱ���þ�����
		for (int j = 0; j < count; j++) {
			cin >> t;
			mm[curr].push_back(t);
			//��������������һ��ֵΪt�����ݣ�������size���;
			   //�����ϣ����
			   //�����±����ǰ�ڵ㣬��ǰ�±��������ֵ�����ӽڵ�
			   //��ϣ������㷨Ч��
			   //��ʵ������һ�����������ǹ�ϣ��ÿһ���±궼����ռ�
			   //pushbackһ��Ԫ�ؾ͸����±�һ��ռ�
			   //size--����ͨ������������жϵ�ǰ�ڵ��Ƿ����ӽڵ�
			   //û����Ȼ����Ŀռ�Ϊ0
		}
	}
	if (m == 0) {
		cout << 1 << endl;
		return 0;
	}
	bfs(1);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size() - 1) {
			cout << " ";//����ӡ����Ŀո�,���һ�����ݲ���ӡ
		}
	}
	cout << endl;



	return 0;
}
