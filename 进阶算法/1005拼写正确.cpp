//���ͷָ
#include<iostream>
using namespace std;
int set[100000];
void judge(int x)
{
	if (x == 0)
	{
		cout << "zero";
	}
    
	if (x == 1)
	{
		cout << "one";
	}

	if (x == 2)
		cout << "two";
	if(x==3)
		cout << "three";
	if (x == 4)
		cout << "four";
	if (x == 5)
		cout << "five";
	if (x == 6)
		cout << "six";
	if (x == 7)
		cout << "seven";
	if (x == 8)
		cout << "eight";
	if (x == 9)
		cout << "nine";

}
int main()
{
	
	long long n, ans = 0;
	cin >> n;
	while (n)
	{
		long long num = n % 10;
		ans+= num;
		n /= (long long)10;
		
	}

	int i;
	for (i = 0; ans; i++)
	{
		long long num = ans % 10;
		set[i] = num;
		ans /= 10;

	}

	for (int j = i-1; j >= 0; j--)
	{
		judge(set[j]);
	
		if (j != 0)
		{
			cout << " ";
		}
	}






	return 0;
}
//14�֣��������ݴ���ԭ�����������̫���ʱ��ᱬ,��ʹ��long long 
//�����ַ������;Ϳ��Իر���һ�㣬���Ժܶ�ʱ��
//�ָ����ֵ����ⶼ���Խ����ַ������������⣬���Ҳû��ϵ��,ÿһ��λ�����Ҳ��������
//�ַ���������Ͳ�������������ķ��գ��������ʹ���ַ�������



#include <iostream>
#include<string>
using namespace std;
int main()
{
	string num;//������ʵ����һ���ַ����飬�����ַ����ȿ��ٿռ�
	string number[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	//�Ľ��˵�д������ʵ��ȫ�����õ�ǰ�����ֵ�����±꣬��Ӧ�����������ÿ�ζ��жϡ�
	cin >> num;
	int S = 0;
	for (int i = 0; num[i]; i++)
	{
		/*S += (int)num[i];*///err
		//����д���Ǵ���ģ���Ϊǿ������ת��ֻ�ǰѵ�ǰ����ת��ΪAscll��ֵ
		//���ͺ��ַ����������48��ǿ������ת���ͻὫ�ַ�1ǿ��ת����49
		S += (num[i] - 48);
		//�������ַ��������ò�48������-48�õ�����
	}
	string num1 = to_string(S);
	int length1 = num1.length();
	for (int i = 0; i < length1; i++)
	{
		if (i == length1 - 1) cout << number[num1[i] - 48];
		else cout << number[num1[i] - 48] << " ";

	}
	return 0;
}

#include <iostream>
#include<string>
using namespace std;
int main()
{
	/*char Alp[15][15]={}*/
	/*ֱ����string���Ϳ��Դ���char��ά����*/
	string Alp[10]= { "zero","one","two","three","four","five","six","seven","eight","nine" };
	string n;
	cin >> n;
	int ans = 0;
	/*for (int i = 0; n; i++)*///err
	for (int i = 0;n[i]; i++)//Ҫд�����λ�ã�����ֻд��ͷ
		ans += (n[i]-48);
	
	string New_n = to_string(ans);
	int len = New_n.length();
	for (int i = 0;i<len; i++)
	{
		cout << Alp[New_n[i] - 48];
		if (i != len - 1)
			cout << " ";
	}



	return 0;
}

