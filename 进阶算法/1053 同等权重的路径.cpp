//����ʹ��bfs������޷�ȷ��Ψһ·��

//�����Ǵ��
#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
//set��Ĭ�����򣬻�����������
map<int, vector<int>>mm;
//vector<int>road(110);err
vector<int>road[110];//��ôд�ſ���//���·��
//vector<int>set(100);��Ҫ��ôд��������ֱ��дһ�����road����������
vector<vector<int>>set;
int w[100];
int n, m, ID, id, k;
long s;
//������������(һ���ռ��һ������)��Ȼ��to_string

queue<int>q;

//bool MySort(int i)
//{
//	if()
//	return A[k + 1] > B[k + 1];
//}
//�����������в�ͨ

void bfs(int x)
{
	int cnt[100];
	q.push(x);//������ڵ�

	int ltcurr=x;//�ϴεĽڵ�


	while (!q.empty())
	{
	
		int curr = q.front();
		q.pop();

		
		if (mm[curr].size() == 0&&cnt[curr]==s)
		{
			set.push_back(road[curr]);
			
		}

		if (cnt[curr] < s)//��ӣ�����s��ֱ�Ӳ����
		{
		
			
			/*if((cnt[curr]+w[curr])==s)
			road[curr].insert(road[curr].end(), w[curr]);
			else
			{
             road[curr].insert(road[curr].end(), w[curr]);
			 road[curr].insert(road[curr].end()," ");

			}*/
			//insert����ָ�����巽����룬push_back����ֱ��ĩβ����
			//��ʵ���ﲻ��Ҫ�������ַ�������ã���Ϊ������Ҫָ��λ�ô�ӡ��
			//�������Ͳ�һ�����ò��룬���Է��ں���ѭ��һ������ӡ�����" "����

			if(ltcurr!=curr)
			{
				cnt[curr] += cnt[ltcurr]+w[curr];
             road[curr].push_back(w[curr]);//err
			 ltcurr = curr;//������һ�νڵ�
			 //��Ľڵ��һֱ���棬ÿ�β��붼���µĵط�
			 // 
			 //������ܳ�������,Ҫ�õ����Ŷ�
			//��β���ȷ��Ψһ·����
			//�ڵ����ȿ϶������ظ��ģ������ȷ��Ψһ��
			//ʹ�õ���ÿ�μ����ϴεĽڵ���������Ȩ�ؼ���

			 //���ӵ��������ˣ�����Ψһ·������û�а취ʵ��
			 //bfsû�а취�ܹ�ѡ��һ���������Ψһ·��
			 //���bfs�в�ͨ
			 
			}
			
			

			

			

		}

		for (int i = 0; i < mm[curr].size(); i++)//ÿ���ڵ�bfs
		{
			/*q.push( mm[mm[curr][i]]);*/
			q.push(mm[curr][i]);

	   }

	}


		
}
int main()
{
	
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> ID >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> id;
			mm[ID].push_back(id);
			//����.push_back(����Ԫ�أ�
		}

	}

	bfs(0);
	/*sort(set.begin(),set.end(),MySort);*///err
	//�����ֵ���Ӵ�С����
	sort(set.begin(),set.end(),greater<vector<int>>());
	//
	//��֪����ô������ζ�Ӧ�±꣬�����һλҲ��һ�����������
	// //��Ӧ�±�ͬ������ʹ�ýṹ�壬�Ժ����ס������Ҫ�ض�ֵ��Ϊ������ʹ�õģ���ʹ�ýṹ��
	// ��Ҫ���ǰѽṹ��߸߹���
	//����뷨�ǶԵģ���Ҫ��ķ���
	//ֱ���ֵ������򼴿ɣ�����ֱ�ӴӴ�С�����������������ϵͳ���Զ�����ÿ���ַ���Ԫ�ش�С��������
	//greater<vector<int>>() �ֵ�������
	for(int i=0;i<set.size();i++)
		for (int j = 0; j < set[i].size(); j++)
		{
			cout << set[i][j];
			if (j != set[i].size())
				cout << " ";
		}

	//set.size()���ж��ٸ���������˼Ҳ���Ǽ�������
	//set[i].size()�����е�һ������λ�õ� ���������ݸ�����






	return 0;
}

//DFS����
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//set��Ĭ�����򣬻�����������
map<int, vector<int>>mm;
//vector<int>road(110);err
vector<int>road;//��ôд�ſ���//���·��
//vector<int>set(100);��Ҫ��ôд��������ֱ��дһ�����road����������
vector<vector<int>>set;
int w[100];
int n, m, ID, id, k;
long s;

void dfs(int curr, int weight)
{//��ʼ��ʱ�����жϸ��ڵ㣬���ֻҪ���ǽ�
	//��ʼ��Ȩ�ؼ�Ϊ���ڵ��Ȩ�ؾ���ͬ��dfs���ƶ���


	if (mm[curr].size() == 0)//Ҷ�ڵ�,��ʱ��û�м��ϵ�ǰȨ��
	{

		if (weight == s)//�ж�Ҷ�ڵ���ϵ�ǰȨ���Ƿ����s
		{

			set.push_back(road);

		}
		//cnt = w[0];
	   //ʵ����cnt�ǻύ����ӵ�
		   //����ÿ�μ�֦��Ҫ��ʼ��cnt
	   //��������û�У��βθı䲻��ʵ�Σ��Ż��ݺ���


		return;
	}

	for (int i = 0; i < mm[curr].size(); i++)//ѭ���������ǵ�ǰ�ڵ��ж��ٸ���֧·����
		//û��������֧·����Ȼ�ٴν����������ݵ���һ���ڵ�
		//ÿһ�ζ��Ƿ�����һ�Σ�Ȼ�󿴿���û��������֧��û�оͽ��������ֻص���һ���ڵ㣬��˻���

	{/*��ǰ��������ݣ�����road,weight,curr����ͬ�����ɣ�дDFS����BFSһ��ע��Ҫͬ��һ���ԣ���Ȼ�����������Ѹ�*/
		//�ɶ���Ҳ��
		//cnt += w[curr];err

		//road.push_back(w[curr]);err
		road.push_back(w[mm[curr][i]]);//��ôд����Ϊ���Ȳ��룬���ϴ��Ĺ̶���ʽ����Զ���ֲ�����ǰ��
		dfs(mm[curr][i], weight + w[mm[curr][i]]);
		//��һ��Ľڵ��Ȩ�ض�Ӧ���ýڵ���ǵ�ǰȨ��
		//һһ��Ӧ��һ�������
		road.pop_back();//���ݼ�֦,��ȥ���һ���ڵ�
						//��Ϊ�Ѿ��жϹ��ˣ�������ȥ��
		//cnt -= w[curr];err


	//����д����������
		//���cnt�����������鷳������δ֪����
		//��Щ���ӵ�������ò�Ҫд��ѭ����
		//��Ҳ�����˾��ǻ᲻�ϵ�������ÿ��ѭ��������һ��
		//�ر����������д�ں�������ε�ʱ������
		//�������ܱ�֤��ʹ��ʱ�õ���Ȼ���ֲ�������������


	}

}

int main()
{

	cin >> n >> m >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> ID >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> id;
			mm[ID].push_back(id);
			//����.push_back(����Ԫ�أ�
		}

	}


	//dfs(0,0);err
	road.push_back(w[0]);//��ǰ��������
	//��ǰ����Ϳ��Ա�֤һ��ʼ�������ݵ�ʱ��,road�о��ж�Ӧ��ǰ�ڵ��Ȩ��
	//�������ͻ�����ͬ�������if�����Ϳ���ֱ�Ӳ������ݣ��Ͳ������
	dfs(0, w[0]);
	/*sort(set.begin(),set.end(),MySort);*///err

	//�����ֵ���Ӵ�С����
	sort(set.begin(), set.end(), greater<vector<int>>());
	//
	//��֪����ô������ζ�Ӧ�±꣬�����һλҲ��һ�����������
	// //��Ӧ�±�ͬ������ʹ�ýṹ�壬�Ժ����ס������Ҫ�ض�ֵ��Ϊ������ʹ�õģ���ʹ�ýṹ��
	// ��Ҫ���ǰѽṹ��߸߹���
	//����뷨�ǶԵģ���Ҫ��ķ���

	//ֱ���ֵ������򼴿ɣ�����ֱ�ӴӴ�С�����������������ϵͳ���Զ�����ÿ���ַ���Ԫ�ش�С��������
	//greater<vector<int>>() �ֵ�������

	//�����������greater���ǵ��򣬶�vector<int>����ָ����Ҫ�ֵ��������Ŀ��
	//�������ָ���˶��������������vector<int>��������ݵ�����������
	//sort�������Ĭ�ϰ����ֵ���������ģ������Ϳ������α�֤��������������ǰ��
	for (int i = 0; i < set.size(); i++)//���ݵ�����
	{
		for (int j = 0; j < set[i].size(); j++)//�������ݵ��������Ϊ��Ҫ���" "���Ե������
		{
			cout << set[i][j];
			if (j != set[i].size() - 1)
				cout << " ";
		}
		cout << endl;//����
	}


	//set.size()���ж��ٸ���������˼Ҳ���Ǽ�������
	//set[i].size()�����е�һ������λ�õ� ���������ݸ�����






	return 0;
}