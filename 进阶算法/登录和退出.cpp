#include<iostream>
using namespace std;
//Ҫ��������Ч�������ǹؼ�
//˼·:���ַ�ת��Ϊ���֣�ת����λֱ����ӣ�����ӡ�ʱ���������ٵ����롱��һһ�ȶ�
//ͬʱҲ�����˵�Ч��������������.
int main()
{
	int m, maxv = -1, minv = 1e9;
	cin >> m;
	char set;//����һ���������������ַ�":"
	string in, out;
	int hh, mm, ss, beforemax=-1, beforemin=-1;
	string frist, last;
	for (int i = 0; i < m; i++)
	{
		string id;//ÿһ��ѭ�����¶���һ��id,�Ͳ���Ҫ����ԭ��������
		cin >> id;//ע��idÿһ��ֻ��һ��,��ÿһ���Լ��ȶԵ�ǰΪ�������С��Ȼ���¼����
		cin >> hh >> set >> mm >> set >> ss;
		minv = min(minv, hh * 3600 + mm * 60 + ss);
		
		if (minv != beforemin)//��ȡ�������ŵ�id
		{
			beforemin = minv;
			frist = id;
			
		}
      
 cin>> hh >> set >> mm >>set>> ss;

	   maxv = max(maxv, hh * 3600 + mm * 60 + ss);
		 if (maxv != beforemax)
		{
			beforemax = maxv;
			last = id;
		}

	}
	 
	  
	
	cout << frist << " " << last;







	return 0;
}