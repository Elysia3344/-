#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
int main()
{
	/*int m, n, i, j = 0;
	int sum1 = 1;
	int sum2 = 1;
	printf("Enter m: Enter n: ");
	scanf("%d", &m);
	scanf("%d", &n);

	for (i = 1; i <= m; i++)
	{
		sum1 *= i;
	}
	for (j = 1; j <= n; j++)
	{
		sum2 *= j;
	}
	int SUM = sum1 + sum2;
	printf("%d!+%d!=%d", m, n, SUM);
	*/
	//int n;
	//int i = 0;
	//float sum = 0;
	//printf("Enter n: ");
	//scanf("%d", &n);
	//for (i = 1; i <= n; i++)
	//{
	//	sum += 1.00000000 / (2 * i - 1);//��Ҫ����ѧ��д����,��������λ��Ҫдͬ�����ȵ�����
	//}
	//printf("sum=%.6f", sum);//double��float�����ԣ��ĸ��������ĸ�

	printf("Enter n: ");
	int n;
	int i = 0; int j = 1;
	float sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum += 1.000 / (3 * i - 2) * j;
		j = -j;//��Ҫ����ѧ��д����,��������λ��Ҫдͬ�����ȵ�����
		;//��������ֵ����ֵ����Ҫ�Զ�һ������������������
	}

	printf("sum=%.3f", sum);
	int i = 0;
	int sum = 0;
	int n = 0;


	for (i = 1; i <= 10; i++)
	{
		printf("Enter grade: \n");

		scanf("%d", &n);
		sum += n;

	}
	int j = 0;
	j = sum / 10;
	printf("Class average is %d", j);

	
	
	int n = 0;
	int m = 0;
	int i = 0;
	int w = 0;

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int	e = 0;
	printf("Enter n: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		w++;
		printf("Enter grade %d:", w);
		scanf("%d", &m);
		if (90 <= m && m <= 100)
			a++;
		else if (80 <= m && m <= 89)
			b++;
		else if (70 <= m && m <= 79)
			c++;
		else if (60 <= m && m <= 69)
			d++;
		else
			e++;//������������if������Ҫ����ѭ���
		//��������棬ֻ���ж������һ�������ֵ��ǰ������Ķ��׸���
		//�����жϸ�ֵ��������ֻ�ж�һ�Σ����Է����滹������һ��Ҫ�����
	}
	//�����̶ֹ���ʽ�ģ�ֱ����printf,һֱ�仯�Ĳ���ѭ��

	printf("The number of A(90 ~100):%d\n", a);
	printf("The number of B(80 ~89):%d\n", b);
	printf("The number of C(70 ~79):%d\n", c);
	printf("The number of D(60 ~69):%d\n", d);//������1,���Ĵ���
	printf("The number of E(0 ~59):%d\n", e);

	int n = 0;
	int i, j = 0;
	for (i = 1; i <= 5; i++)
	{


		scanf("%d", &n);
		for (j = 1; j <= n; j++)//��ѭ�����ٴζ����Ե���һ�𣬲����൱������˶��ٸ���
			//��ѭ����������
		{
			printf("*");
		}
		printf("\n");//�����ǵû���
	}



	/*int k,i = 0;
	int count = 0;
	scanf("%d", &k);
	int sum = 0;
	for (i = k; i>0; i--)
	{
		if (i % 13 == 0 || i % 17 == 0)
		{
			count++;
			sum += i;
	}
		if (count == 10)
			break;



	}
	printf("%d", sum);*/

	int num = 0;
	int a, b, c, d, e = 0;
	scanf("%d", &num);
	//a=num/10000   err
	a = num % 100000 / 10000;
	b = num % 10000 / 1000;
	c = num % 1000 / 100;
	d = num % 100 / 10;
	e = num % 10;
	//ǰ��������ǰһ�������������λ�������ȷ�涨��������λ�����Ǵ����ֱ�ӳ�10000
	//������Ŀû�й涨���ޣ�����Ҫ����ȡ����
	//ȡ�����Ϳ��������Լ�����Ҫ�ĳ���5λ�������Ǻá�
	//���ɾ��ǣ�ȡ����ȥ�������ó��Լ���Ҫ�����ȡ�����õ�������
	if (a == e && b == d)
		printf("this number is a huiwen");
	else
		printf("this number is not a huiwen");


	int n = 0;
	int sum = 0;
	printf("Input integers: ");
	do//��Ϊ����Ҫ������һ�����ֲ����ж�����
	{
		scanf("%d", &n);
		if (n > 0)//����������
			//�������do while,��Ȼ����࣬���������һ�����Ǹ������Ǿͻ�ӵ�sum����ȥ��
			//������whileֻ�ڵڶ��β���Ԥ��������Ҫ�ڿ�ͷ�Ÿ�if
		{
			if (n % 2 != 0)
			{
				sum += n;
			}
		}


	} while (n > 0);//Ҫ�ӷֺţ�
	printf("The sum of the odd numbers is %d", sum);

	
	int fen1, fen2, fen5 = 0;
	int money = 0;
	int count = 0;
	printf("Input money: ");
	scanf("%d", &money);
	for (fen5 = 1; fen5 > 0 && fen5 <= (money / 5); fen5++)//������ϵͳ��ʽ�����ò���ô��д
		//ϵͳ������fen5=1��ͷ
	{
		for (fen2 = money / 2; fen2 > 0; fen2--)
		{
			for (fen1 = money / 1; fen1 > 0; fen1--)
			{
				if (5 * fen5 + 2 * fen2 + fen1 == money)
					//fen���������Ǵ�С������ֻ�������г�ÿ�ַ������Ŀ����ԣ���СҪ�Լ�����ȥ
				{
					count++;
					printf("fen5: %d fen2: %d fen1: %d\n", fen5, fen2, fen1);
				}
			}
		}
	}
	printf("count=%d", count);
	//forѭ��Ƕ�׵����ã���ʵ������٣�forѭ���������ʱ���ȴ�˳��ִ�и���ѭ����
//Ȼ����ִ���������ѭ���������Ժ��ٴӵ����ڶ���ѭ����˳��������ִ��
//��С��ѭ��,�������ƣ�����������ѭ��ִ�У�Ȼ�������°�˳��ִ��
//����ִ����С�������Ǵ��
//���������fen--����Ϊ���ǿ���ͨ����money/fen"�����fen����������������ֱ�ӵó����ܵ����������
			//��++��û������ô�
//�Ӵ�С��٣�����ִ��Сѭ���������Żᾫȷ
//����д��=>,���еĲ���ʽ��ֻ����߼�ͷ�ұߵȺţ���<=��>=
//ѭ��һ��Ҫ�޶��÷�Χ����Ȼ����ѭ��


int m, n,i = 0;
scanf("%d%d", &m, &n);
if (m < n)

	for (i = m; i <= n; i++)
	{
		printf("%d\n", i);
	}
else
	for (i = m; i >= n; i--)
	{
		printf("%d\n", i);
	}

int m, n, i, j, k = 0;
int sum1 = 1;
int sum2 = 1;
int sum3 = 1;
printf("Enter m: Enter n: ");
scanf("%d%d", &m, &n);
for (i = 1; i <= m; i++)
{
	sum1 *= i;
}
for (j = 1; j <= n; j++)
{
	sum2 *= j;
}
for (k = 1; k <= n - m; k++)
{
	sum3 *= k;
}
int SUM = 0;
SUM = sum2 / (sum1 * sum3);
printf("result=%d", SUM);


int m = 0;
double count = -1;//count֮����Ҫ-1����Ϊdo whileһ��ʼ��countû���жϾͼ���1��
//Ϊ�˱����-1
double n = 0;
double sum = 0;
do {
	count++;

	sum += m;
	printf("Enter grade, -1 to end:\n");
	scanf("%d", &m);
} while (m != -1);
n = sum / (count);//����Ҫͳһ��
printf("Class average is %.2lf", n);


int m, n, i, j = 0;
int count = 0;
int sum = 0;
printf("Input m: Input n: ");
scanf("%d%d", &m, &n);
for (i = m; i <= n; i++)//��ʾm~n֮�������
{
	for (j = 2; j < i; j++)//1����������2����С������
	{
		{if (i % j == 0)

			break;
		}
	}
	//�������ķ�ʽ���Ǽ��������j<iʱ,����������

	if (i == j)//���Ϲ�����������������Ҫ��else,��Ȼ��9/2Ҳ������������������������
		//���Ǳ���ȷ�����п��ܶ������ǣ�����ȷ��������
	{
		count++;
		sum += i;
	} //���ﲻҪbreak,��Ȼ�㶼ֱ������ѭ����
	//���ﲻ��break����Ϊ�˲��ϼ�������⵱ǰ����i��ѭ�����Ƿ���������

	//�����и�����Ҫ���߼����ǣ���j<iʱ�����ѭ��������ֱ��������Ǿ�һ������i==j.
	// ʹ��break���������Сѭ������Ȼ��ֱ�ӽ�����һ�δ�ѭ����
	//��û�б���������Ȼ�Ͳ���break,ѭ���ͻ�һֱ���У�ֱ�����j==iʱ������Сѭ����
	//�����ʹ����һֱ������Ŀ�ģ�����ֻҪj==i�ͳ���
	//�ܽ������ѭ���г���������ֱ����������������Ϊ����
	//ֻ��ֱ�����û�г��������Ĳ�Ϊ����





}
printf("count=%d, sum=%d", count, sum);

	return 0;
}

