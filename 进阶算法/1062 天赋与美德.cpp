#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>

//�ṹ���ʹ�ã������ˡ�
using namespace std;
int n, l, h, m;
/*	string id[10010];
	int tal[10010], vir[10010];*/
	//err

//�㷨ԭ������Ȱ��������ݴ����һ�������У�Ȼ��ֱ𿪲�ͬ�����������Ҫ������
//��Щ�������൱����ȡpe���������
//ȱ����Ǵ�������̫�࣬ѭ���õĴ���̫�࣬��ʵ��ȡ��������Ƕ����
//���һ�Ҫ�ý�����������Ҫ����i,��Ҫɾ��Ԫ�أ���Щ���趼��û�б�Ҫ��
//Ч��Ҳ�Ƚϵ͡�
//���ǲ�����Ϊʲô�ǲ�����ȷ����������ȡ���龿��Ϊʲô���ˡ�
//����û�д��������Ҹ�����Ŀ��˼���������ڵ��ɸ��ڣ�
	struct _data
	{
		string id;
		int tal, vir;
	};

	//vector<_data>pe(10010);//����ָ�Ĳ����±���ǽṹ����������˼
     //err,��ôд����������û��������
	//vector<_data>sage(100010);//10^5��100000��6�����ֱ�����ˣ�
	//vector<_data>nobleman(100010);
	//vector<_data>foolman(100010);
	//vector<_data>smallman(100010);//������Žṹ��Ҫд()����д������

	vector<_data>sage;//10^5��100000��6�����ֱ�����ˣ�
	vector<_data>nobleman;
	vector<_data>foolman;
	vector<_data>smallman;
	



	//������ô����������ռ����⣬���ǲ��ܶ������Ϊ�����Ϊ��Ҳ���������
	//��Ϊendû�취���������������
	//��pushֱ�Ӳ�������
	
	bool Sort( _data a, _data b)//c++���԰ѽṹ�嵱�������ã�����*Ҳ��
	{
		/*return a > b ? a : b;*///д�������һ������

		if (a.tal + a.vir != b.tal + b.vir)
			//return (a.tal + a.vir) > (b.tal + b.vir) ? (a.tal + a.vir) : (b.tal + b.vir);err
			return (a.tal + a.vir) > (b.tal + b.vir);

		else if (a.vir != b.vir)//�ĸ�Ʒ�¸�������������������츳��Ʒ����ͬ�츳�����Ǿ����ܷ��������
			//return a.vir > b.vir ? a.vir : b.vir;err
			return a.vir > b.vir;
		else
			return a.id < b.id;

		//����id˳���©�ˣ�

	}
	//��Ϊ������жϱ�׼����bool���ͣ���ʾ������������ж�����,����void!
	//����sort�����bool��˵���㲻��Ҫ"?"��ֻ��Ҫ�����ȴ�С�ķ��ž�����
	//�������>��˳�����<������Ҫд�жϹ��̣���ʽ��ס��

	
	//��˼����ôд���ȸ��ӣ���ν�ȫ�Ժ���ά��������bug��Ч��Ҳ��





int main()
{
	
	cin >> n >> l >> h;
vector<_data>pe(n);//�ṹ����������ֱ���ò��������
	//���Ҫʹ��pop_back�ͽ���,��Ҫ��֤���������ģ�
//��Ȼ������������û�б�Ҫ��ôд�ˣ���Ϊ����ֻ����������ݣ�ֻ�ñ䶯pe����
//���������ʱ���㷨Ч�ʾͺܵ���
//��д����������Ч�ʣ�Ȼ����Ǳ����������δ֪����.
	for (int i = 0; i < n; i++)
	{
		cin >> pe[i].id >>pe[i].vir >> pe[i].tal;
	}
	
//	int flag = n;err
// ���ﲻ�ÿ���flag,n��ͱ��ˣ���Ϊ��Ҫ��֤���鶼�����ģ�����ֱ�Ӹı�nʹ��ѭ��ֱ�ӵ�ĩβ��������
	//��Ȼnһֱû���������С�ˣ�����Խ�籨��
	
	for (int i = 0; i < n; i++)
	{
		if (pe[i].vir < l || pe[i].tal < l)
		{
			swap(pe[i], pe[pe.size() - 1]);//��������
			pe.pop_back();
			n--;//n��������һ���С
			
			i--;//����ҲҪ���У���Ϊ����������ݺܿ��ܾ��ǲ��ϸ�ģ��ܵ���˵���Ƕ�Ҫ����
		}
	}

	m = n;
	cout << m << endl;

	

	//ע�⣡ʹ�ý���������������������ݵ���ǰ�����ˣ���ʱ��û�м����������ݣ�
	// ÿһ�ε�����Ҫ���һ�µ�����������ǲ����������ݣ�
	//Ϊ�˷�ֹ�ظ������Ͳ���Ҫ�Ĵ��룬ÿһ��i�����ӣ�ֻ��Ҫ��һ��i--����,������һ��
	//i���Ǹ���һ�ֵ�һ�������൱�ڶԵ��������������!

	for (int i = 0; i < m; i++)
	{
		if (pe[i].vir >= h&&pe[i].tal >= h)
		{
			sage.push_back(pe[i]);//ֱ��Ҫ�������ٲ�����㴴��һ�ѵ�������Ч����
			swap(pe[i], pe[pe.size() - 1]);//��������
			pe.pop_back();
			m--;
			i--;//��һ�����е����������
		}
	}

	sort(sage.begin(), sage.end(), Sort);//bool���Ͳ��ô��ξͲ�д()
	for (int i = 0; i < sage.size(); i++)
	{
		
cout << sage[i].id << " " << sage[i].vir << " " << sage[i].tal<<endl;
		
	}
	


	

	
	for (int i = 0; i < m; i++)
	{
		if (pe[i].vir >= h && pe[i].tal< h)
		{
			nobleman.push_back(pe[i]);
			swap(pe[i], pe[pe.size() - 1]);//��������
			pe.pop_back();
			m--;
			i--;
		
		}
	}
	//sort(Stu.begin(), Stu.end(), SortId); ���Ҫ�����������������������ʽ!
	//������������Ҫ�ĸ�ʽ��û�취��������������ſ��Բ�дbegin,end
	sort(nobleman.begin(), nobleman.end(), Sort);
	for (int i = 0; i < nobleman.size(); i++)
		cout << nobleman[i].id << " " << nobleman[i].vir << " " << nobleman[i].tal<<endl;
		

	

	for (int i = 0; i < m; i++)
	{
		/*if (pe[i].tal<h&&pe[i].vir<h&&pe[i].vir>pe[i].tal)*///err
		//�۸����⽫�����ڸĳɸ��ڵ��²��ֽ���������
		if (pe[i].tal < h && pe[i].vir<h && pe[i].vir>=pe[i].tal)
		{
			foolman.push_back(pe[i]);
			swap(pe[i], pe[pe.size() - 1]);//��������
			pe.pop_back();
			m--;
			i--;
		}
	}

	sort(foolman.begin(), foolman.end(), Sort);
	for (int i = 0; i < foolman.size(); i++)
	cout << foolman[i].id << " " << foolman[i].vir << " " << foolman[i].tal<<endl;
	

	sort(pe.begin(), pe.end(), Sort);
	for (int i = 0; i < pe.size(); i++)
	cout << pe[i].id << " " << pe[i].vir << " " << pe[i].tal << endl;//�����ʵ����ֻʣ��С��
		








	return 0;
}



//�Ż��㷨������ֱ����һ��������Ȼ���ҵ����ʵ������ٲ����ȥ����������ͻ�ܿ���.
//
//�Ż��Ľ�
//����ֱ�ӿ�����������죬����࣬ȱ����ǿɶ��Բ���һ��
//���ֱ����һ��ѭ���У���if���������ݣ�ʡȥû�б�Ҫ����ȡ��������
//�����Ժ����һ�����ݷֲ�ͬ������еģ�ֱ����һ��ѭ����ÿһ�����ݶ��жϷ������Ｔ��
//ʡȥ���������ѭ�����Լ�˫ѭ��ֱ�Ӽ�����������Ż����ȺͿɶ���,���з��������ظ�д�������㷨
//��Щ����û�б�Ҫ�ģ�


#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>

//�ṹ���ʹ�ã������ˡ�
using namespace std;
int n, l, h, m;



struct _data
{
	string id;
	int tal, vir;
}mydata;

//ֱ�Ӹ��ṹ�����������൱���Լ�������һ���µĽṹ��
//���û�������Ҫ�Լ��½�һ����
//��struct _data s
//��Ϊ_data����һ�����ͣ�����ֱ��ʹ�ã���ʾΪ�ṹ�����Ҫһ������

vector<_data>v[5];





bool Sort(_data a, _data b)//c++���԰ѽṹ�嵱�������ã�����*Ҳ��
{
	/*return a > b ? a : b;*///д�������һ������

	if (a.tal + a.vir != b.tal + b.vir)
		//return (a.tal + a.vir) > (b.tal + b.vir) ? (a.tal + a.vir) : (b.tal + b.vir);err
		return (a.tal + a.vir) > (b.tal + b.vir);

	else if (a.vir != b.vir)//�ĸ�Ʒ�¸�������������������츳��Ʒ����ͬ�츳�����Ǿ����ܷ��������
		//return a.vir > b.vir ? a.vir : b.vir;err
		return a.vir > b.vir;
	else
		return a.id < b.id;

	//����id˳���©�ˣ�

}
//��Ϊ������жϱ�׼����bool���ͣ���ʾ������������ж�����,����void!
//����sort�����bool��˵���㲻��Ҫ"?"��ֻ��Ҫ�����ȴ�С�ķ��ž�����
//�������>��˳�����<������Ҫд�жϹ��̣���ʽ��ס��






int main()
{

	cin >> n >> l >> h;

	//for (int i = 0; i < n; i++)
	//{
	//	cin >> pe[i].id >>pe[i].vir >> pe[i].tal;
	//}���ݷֺܶ����з�ʽ��û�б�Ҫ��ȫ������һ������

	//struct _data mydata;�����������Ҫ�Լ��½�һ��

	int m = n;//��ǵ�ǰm�Ĵ�С
	for (int i = 0; i < n; i++)
	{
		cin >> mydata.id >> mydata.vir >> mydata.tal;
		//ֱ�Ӳ���ṹ�壬Ȼ��if�жϲ�������
		if (mydata.vir < l || mydata.tal < l)
		{
			m--;//ʵ�����ݴ�С
			continue;//������������ֱ�ӵ���һ��ѭ�����൱��ֱ������
		}

		if (mydata.vir >= h && mydata.tal >= h)
			v[0].push_back(mydata);
		else if (mydata.vir >= h && mydata.tal < h)
			v[1].push_back(mydata);
		else if (mydata.tal < h && mydata.vir<h && mydata.vir>=mydata.tal)
			v[2].push_back(mydata);
		else
			v[3].push_back(mydata);



	}

	cout << m << endl;
	for (int i = 0; i < 4; i++)//��������
	{
		sort(v[i].begin(), v[i].end(), Sort);
		for (int j = 0; j < v[i].size(); j++)
		{
			//cout << v[i].id << " " << v[i].vir << " " << v[i].tal << endl;err
			//��Ҫͬʱ��ȷ���������ĸ���������ξ��������ж�Ӧ����һ�����ݣ�
			//һ��������Ҳ�����Ŷ������ݣ�����ȷ��ô�����
			cout << v[i][j].id << " " << v[i][j].vir << " " << v[i][j].tal << endl;
		}
	}


	return 0;
}

