#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<math.h>
//int reverse(int number)
//{
//	int count = 0;
//	while (number != 0)
//	{ 
//		/*if (number < 0)
//		{
//			
//			count++;
//	}
//		if (count == 1)
//	{number = -number;
//		printf("-");
//	}*/
//		int i = number % 10;
//		if (i < 0)//ֱ�����������һ�����жϣ���Ϊ-��������ÿһ�����ģ����Զ�Ҫת��
//		{
//			count++;
//			i = -i;
//		if (count == 1)//����������ֻ��ӡһ������Ϊֻ���ʼ�����ǰ���ӡ���Է���printf��i����ǰ��
//		{
//			printf("-");
//		}
//		}
//			printf("%d", i);
//
//		
//		
//		
//		number =number / 10;
//
//	}
//	
//}
//int main()
//{
//
//	int number = 0;
//	scanf("%d", &number);
//	reverse(number);
//
//
//
//	return 0;
//}

//int fun(int m1,int m2)
//{
//	int count = 0;
//printf("%d's reverse is: ", m1);
//	while (m1 != 0)
//	{
//		
//
//		int i = m1 % 10;
//		m1 = m1 / 10;
//
//
//		printf("%d", i);
//
//	}
//	printf("\n");
//	
//	
//	
//	
//	printf("%d's reverse is: ", m2);
//	while (m2 != 0)
//	{ 
//		
//		int i = m2 % 10;
//		if (i < 0)//ֱ�����������һ�����жϣ���Ϊ-��������ÿһ�����ģ����Զ�Ҫת��
//		{
//			count++;
//			i = -i;
//		if (count == 1)//����������ֻ��ӡһ������Ϊֻ���ʼ�����ǰ���ӡ���Է���printf��i����ǰ��
//		{
//			printf("-");
//		}
//
//		}
//	m2 =m2 / 10;
//	if(i!=0)
//	printf("%d", i);
//
//
//		
//		
//		
//		
//
//	}
//	
//}
//int main()
//{
//
//	int m1, m2;
//	printf("Input m1: ");
//	printf("Input m2: ");
//	scanf("%d%d", &m1,&m2);
//	fun(m1,m2);
//
//
//
//	return 0;
//}

//long fact(int x)
//{
//	int m = 0;
//	int i = 0;
//	int n = 0;
//	int sum1 = 1;
//	int sum2 = 1;
//	int sum3 = 1;
//	
//
//	if (x == 2)
//	{
//		printf("Enter m: ");
//		printf("Enter n: ");
//		scanf("%d%d", &m, &n);
//		for (i = 1; i <= n; i++)
//			sum1 *= i;
//		for (i = 1; i <= (n - m); i++)
//			sum3 *= i;
//
//		printf("A(%d,%d)=%d", n, m, sum1/sum3);
//	}
//
//	if (x == 1)
//	{
//		printf("Enter m: ");
//		printf("Enter n: ");
//		scanf("%d%d", &m, &n);
//		for (i = 1; i <= n; i++)
//			sum1 *= i;
//		for (i = 1; i <= m; i++)
//			sum2 *= i;
//		for (i = 1; i <= (n - m); i++)
//			sum3 *= i;
//
//		printf("C(%d,%d)=%d", n, m, sum1 / (sum2 * sum3));
//
//	}
//}
//int main()
//{
//	int n = 0;
//	printf("  1-Combination\n  2-Permutation\n====================\n");
//		
//		
//	printf(" Please Select(1,2): ");
//   scanf("%d", &n);
//	fact(n);
//
//
//
//	return 0;
//}
//int fac(int n)
//{
//	
//	/*i++;
//	
//	sum *= i;
//	if (i == n)
//	{
//			printf("%d", sum);
//	}
//	fac(n,i,sum);*/
//	//����Ƕ�׵ݹ�����ʱ����������еģ�����������������ú����ݹ����
//	//�㷨̫low,��ݹ���þ���Ҫ�ҳ�n����ʽ�Ĺ��ɣ��������ܺܺõĽ������
//	if (n >= 1)
//	{
//		return n * fac(n - 1);
//	}
//	else
//		return 1;
//	//����return ����ֵ��ͬʱ������n�����ʣ�ͨ��n-1���ﵽ����ѭ����Ч��
//	//0ʱ��return 1,ֵΪ1
//	//1ʱ,1*fac(0)=1*1=1
//	//2,2*1 =2
//	//3*2 =6
//	//4*3*2
//	//5*4*3*2
//	//...
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	fac(n);
//	printf("%d", fac(n));
//
//
//
//
//	return 0;
//}
//

int sum(int x)
{
	int i = 0;
int sum = 0;
	while(x != 0)
	{
		i = x % 10;
		sum += i;
		x = x / 10;
	}
	printf("%d", sum);
}
int main()
{

int n = 0;
scanf("%d", &n);
sum(n);
	




	return 0;
}



		
	





	




		

			


		
		



		


