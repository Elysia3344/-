#include<iostream>
#include<vector>
#include<algorithm>//�㷨������sort����
using namespace std;

//���ڶ�����ݲ��öԵ������ݽ�������
//�ṹ��(��������)+����(��Ŷ���ṹ�壩����
//�����㿪�������鷴��д�������������������ַ����ͻ������Լ�����������̫��������
//�ṹ��Ϳ�����Զ���������Ч��


struct _data
{
	string id;
string name;
	int mark;
	
};



bool SortId(_data a,_data b)//ֱ��д�������������ṹ�弴��
{
	return a.id < b.id;
}

bool SortName(_data a, _data b)//ֱ��д�������������ṹ�弴��
{
	if(a.name !=b.name)
		//��Ҫ©����Ŀ��Ϣ��
	//����м���ѧ�����������꼶��ͬ�������������ǵ�ID������˳������ǽ�������
	return a.name < b.name;

	else
		return a.id < b.id;
	
}

bool SortMark(_data a, _data b)//ֱ��д�������������ṹ�弴��
{
	if (a.mark != b.mark)
		return a.mark < b.mark;

	else
		return a.id < b.id;
}


int main()
{
	int n, c;
	cin >> n >> c;
	
	//vector<int>Stu err
	vector<_data>Stu(n);//ֱ�Ӱѽṹ������ֵ����������ü���
	//ע����������Ҫд(n)��ʾ��������������Ȼ������ʼֻ��1�����ᱨ��

	for (int i = 0; i < n; i++)
	{
		cin >>Stu[i].id  >> Stu[i].name >> Stu[i].mark;
	}


	if (c == 1)
		sort(Stu.begin(), Stu.end(), SortId);
	if (c == 2)
		sort(Stu.begin(), Stu.end(), SortName);
	if(c==3)
		sort(Stu.begin(), Stu.end(), SortMark);

	
	for (int i = 0; i < n; i++)
	{
		cout << Stu[i].id << " " << Stu[i].name << " " << Stu[i].mark << endl;
	}

	
		
	






	return 0;
}