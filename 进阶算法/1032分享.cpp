#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>//����setfill��setw
using namespace std;

class node
{
public:
	//����������������
	char data;//���Ͳ�Ҫ����дint!
	//int pos;��ǰ��λ���Ѿ����������±��ʾ�ˣ�
	int nextpos = -1;//��Ŀ����Ϊ-1��ʾNULL�����������ʼ��Ϊ-1�������ú���β��
//һ��û�������ݣ���ô��ʼ��Ϊ-1�ͱ�ʾΪ��β.
	int visited = 0;
};
int main()
{
	vector<node> list(100010);
	int beginpos1, beginpos2, n;
	cin >> beginpos1 >> beginpos2 >> n;
	for (int i = 0; i < n; i++)
	{
		int inpos, inNextpos;
		char indata;
		cin >> inpos >> indata >> inNextpos;
		list[inpos].data = indata;//�����ʵ��дҲ�У���Ŀ����Ҫ�������Ҳ���������׺λ��
		list[inpos].nextpos = inNextpos;
		
}
	int t = beginpos1;
	while (true)//������һ�����ʲ����
	{
		/*if (list[t].nextpos == -1)
			break;*///err,������һ���ڵ�Ϊ��
		//Ϊ��ȫ����Ҫ�������ǵ�ǰΪ�յ�ʱ���Ҳ��˳�
		if (t == -1)
			break;

		else
		{
			//list[t].visited == 1;
			list[t].visited = 1;//��д�˸�=�������ˡ�
			//�Ұ���bug
			t = list[t].nextpos;
		}
		
	}

	int judge = 0, tmp = beginpos2, pos;
	while (true)
	{
		//if (list[tmp].nextpos == -1)
		//	break;  err
		if (tmp == -1)
			break;

		if (list[tmp].visited == 1)//��ʾ�ҵ���ͬ���ʣ�����׺��ʼ
		{
			judge = 1;
			pos = tmp;
			break;

		}
		else
		tmp = list[tmp].nextpos;
	}

	if (judge == 1)
	{
		cout << setfill('0') << setw(5) << pos << endl;
		//setfill() ������������ֵĿ��Ʒ���setw() ���������������ȵĿ��Ʒ���
		//����ʹ�� setfill('0') ����ʹ�������е���������롣
		//setfill�����ַ�Ĭ��Ϊ�ո��ַ�
		//��������һ��ʹ�õ�ʱ����ǣ�pos�������pos����5��ʱ����߲�0����5��
	}
	else
	{
		cout << -1 << endl;
	}


	return 0;
}


