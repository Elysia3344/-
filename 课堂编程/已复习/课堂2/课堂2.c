#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
int main()
{
	int m, n, i, j = 0;
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

//	printf("Enter n: ");
//	int n;
//	int i = 0; int j = 1;
//	float sum = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum += 1.000 / (3 * i - 2) * j;
//		j = -j;//��Ҫ����ѧ��д����,��������λ��Ҫдͬ�����ȵ�����
//		;//��������ֵ����ֵ����Ҫ�Զ�һ������������������
//	}
//
//	printf("sum=%.3f", sum);
//	int i = 0;
//	int sum = 0;
//	int n = 0;
//
//
//	for (i = 1; i <= 10; i++)
//	{
//		printf("Enter grade: \n");
//
//		scanf("%d", &n);
//		sum += n;
//
//	}
//	int j = 0;
//	j = sum / 10;
//	printf("Class average is %d", j);
//
//	
//	
//	int n = 0;
//	int m = 0;
//	int i = 0;
//	int w = 0;
//
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int	e = 0;
//	printf("Enter n: ");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		w++;
//		printf("Enter grade %d:", w);
//		scanf("%d", &m);
//		if (90 <= m && m <= 100)
//			a++;
//		else if (80 <= m && m <= 89)
//			b++;
//		else if (70 <= m && m <= 79)
//			c++;
//		else if (60 <= m && m <= 69)
//			d++;
//		else
//			e++;//������������if������Ҫ����ѭ���
//		//��������棬ֻ���ж������һ�������ֵ��ǰ������Ķ��׸���
//		//�����жϸ�ֵ��������ֻ�ж�һ�Σ����Է����滹������һ��Ҫ�����
//	}
//	//�����̶ֹ���ʽ�ģ�ֱ����printf,һֱ�仯�Ĳ���ѭ��
//
//	printf("The number of A(90 ~100):%d\n", a);
//	printf("The number of B(80 ~89):%d\n", b);
//	printf("The number of C(70 ~79):%d\n", c);
//	printf("The number of D(60 ~69):%d\n", d);//������1,���Ĵ���
//	printf("The number of E(0 ~59):%d\n", e);
//
//	int n = 0;
//	int i, j = 0;
//	for (i = 1; i <= 5; i++)
//	{
//
//
//		scanf("%d", &n);
//		for (j = 1; j <= n; j++)//��ѭ�����ٴζ����Ե���һ�𣬲����൱������˶��ٸ���
//			//��ѭ����������
//		{
//			printf("*");
//		}
//		printf("\n");//�����ǵû���
//	}
//
//
//
//	/*int k,i = 0;
//	int count = 0;
//	scanf("%d", &k);
//	int sum = 0;
//	for (i = k; i>0; i--)
//	{
//		if (i % 13 == 0 || i % 17 == 0)
//		{
//			count++;
//			sum += i;
//	}
//		if (count == 10)
//			break;
//
//
//
//	}
//	printf("%d", sum);*/
//
// 
//	int num = 0;
//	int a, b, c, d, e = 0;
//	scanf("%d", &num);
//	//a=num/10000   err
//	a = num % 100000 / 10000;
//	b = num % 10000 / 1000;
//	c = num % 1000 / 100;
//	d = num % 100 / 10;
//	e = num % 10;
//	//ǰ��������ǰһ�������������λ�������ȷ�涨��������λ�����Ǵ����ֱ�ӳ�10000
//	//������Ŀû�й涨���ޣ�����Ҫ����ȡ����
//	//ȡ�����Ϳ��������Լ�����Ҫ�ĳ���5λ�������Ǻá�
//	//���ɾ��ǣ�ȡ����ȥ�������ó��Լ���Ҫ�����ȡ�����õ�������
//	if (a == e && b == d)
//		printf("this number is a huiwen");
//	else
//		printf("this number is not a huiwen");
//
//
//	int n = 0;
//	int sum = 0;
//	printf("Input integers: ");
//	do//��Ϊ����Ҫ������һ�����ֲ����ж�����
//	{
//		scanf("%d", &n);
//		if (n > 0)//����������
//			//�������do while,��Ȼ����࣬���������һ�����Ǹ������Ǿͻ�ӵ�sum����ȥ��
//			//������whileֻ�ڵڶ��β���Ԥ��������Ҫ�ڿ�ͷ�Ÿ�if
//		{
//			if (n % 2 != 0)
//			{
//				sum += n;
//			}
//		}
//
//
//	} while (n > 0);//Ҫ�ӷֺţ�
//	printf("The sum of the odd numbers is %d", sum);
//
//	
//	int fen1, fen2, fen5 = 0;
//	int money = 0;
//	int count = 0;
//	printf("Input money: ");
//	scanf("%d", &money);
//	for (fen5 = 1; fen5 > 0 && fen5 <= (money / 5); fen5++)//������ϵͳ��ʽ�����ò���ô��д
//		//ϵͳ������fen5=1��ͷ
//	{
//		for (fen2 = money / 2; fen2 > 0; fen2--)
//		{
//			for (fen1 = money / 1; fen1 > 0; fen1--)
//			{
//				if (5 * fen5 + 2 * fen2 + fen1 == money)
//					//fen���������Ǵ�С������ֻ�������г�ÿ�ַ������Ŀ����ԣ���СҪ�Լ�����ȥ
//				{
//					count++;
//					printf("fen5: %d fen2: %d fen1: %d\n", fen5, fen2, fen1);
//				}
//			}
//		}
//	}
//	printf("count=%d", count);
//	//forѭ��Ƕ�׵����ã���ʵ������٣�forѭ���������ʱ���ȴ�˳��ִ�и���ѭ����
////Ȼ����ִ���������ѭ���������Ժ��ٴӵ����ڶ���ѭ����˳��������ִ��
////��С��ѭ��,�������ƣ�����������ѭ��ִ�У�Ȼ�������°�˳��ִ��
////����ִ����С�������Ǵ��
////���������fen--����Ϊ���ǿ���ͨ����money/fen"�����fen����������������ֱ�ӵó����ܵ����������
//			//��++��û������ô�
////�Ӵ�С��٣�����ִ��Сѭ���������Żᾫȷ
////����д��=>,���еĲ���ʽ��ֻ����߼�ͷ�ұߵȺţ���<=��>=
////ѭ��һ��Ҫ�޶��÷�Χ����Ȼ����ѭ��
//
//
//int m, n,i = 0;
//scanf("%d%d", &m, &n);
//if (m < n)
//
//	for (i = m; i <= n; i++)
//	{
//		printf("%d\n", i);
//	}
//else
//	for (i = m; i >= n; i--)
//	{
//		printf("%d\n", i);
//	}
//
//int m, n, i, j, k = 0;
//int sum1 = 1;
//int sum2 = 1;
//int sum3 = 1;
//printf("Enter m: Enter n: ");
//scanf("%d%d", &m, &n);
//for (i = 1; i <= m; i++)
//{
//	sum1 *= i;
//}
//for (j = 1; j <= n; j++)
//{
//	sum2 *= j;
//}
//for (k = 1; k <= n - m; k++)
//{
//	sum3 *= k;
//}
//int SUM = 0;
//SUM = sum2 / (sum1 * sum3);
//printf("result=%d", SUM);
//
//
//int m = 0;
//double count = -1;//count֮����Ҫ-1����Ϊdo whileһ��ʼ��countû���жϾͼ���1��
////Ϊ�˱����-1
//double n = 0;
//double sum = 0;
//do {
//	count++;
//
//	sum += m;
//	printf("Enter grade, -1 to end:\n");
//	scanf("%d", &m);
//} while (m != -1);
//n = sum / (count);//����Ҫͳһ��
//printf("Class average is %.2lf", n);
//
//
//int m, n, i, j = 0;
//int count = 0;
//int sum = 0;
//printf("Input m: Input n: ");
//scanf("%d%d", &m, &n);
//for (i = m; i <= n; i++)//��ʾm~n֮�������
//{
//	for (j = 2; j < i; j++)//1����������2����С������
//	{
//		{if (i % j == 0)
//
//			break;
//		}
//	}
//	//�������ķ�ʽ���Ǽ��������j<iʱ,����������
//
//	if (i == j)//���Ϲ�����������������Ҫ��else,��Ȼ��9/2Ҳ������������������������
//		//���Ǳ���ȷ�����п��ܶ������ǣ�����ȷ��������
//	{
//		count++;
//		sum += i;
//	} //���ﲻҪbreak,��Ȼ�㶼ֱ������ѭ����
//	//���ﲻ��break����Ϊ�˲��ϼ�������⵱ǰ����i��ѭ�����Ƿ���������
//
//	//�����и�����Ҫ���߼����ǣ���j<iʱ�����ѭ��������ֱ��������Ǿ�һ������i==j.
//	// ʹ��break���������Сѭ������Ȼ��ֱ�ӽ�����һ�δ�ѭ����
//	//��û�б���������Ȼ�Ͳ���break,ѭ���ͻ�һֱ���У�ֱ�����j==iʱ������Сѭ����
//	//�����ʹ����һֱ������Ŀ�ģ�����ֻҪj==i�ͳ���
//	//�ܽ������ѭ���г���������ֱ����������������Ϊ����
//	//ֻ��ֱ�����û�г��������Ĳ�Ϊ����
//
//
//
//
//
//}
//printf("count=%d, sum=%d", count, sum);


int i, j;
/*int n = 0;*///err
int a[10];
int flag = 0;
//�㻹���������Ӧ�����ʹ��
for (i = 0; i < 10; i++)
{
	scanf("%d", &a[i]);//���Լ��ඨ��һ��n��ʲô�����������������ʲô�ã�


}
for (i = 0; i < 10; i++)
{
	for (j = 0; j < 10; j++)
	{
		if (i != j && a[i] == a[j])

			break;
	}

	if (a[i] != a[j])
		//�������������������ж��ֲ��ż����ȼ��������ֵ�jҲ���٣�����������
		//���Ѿ�����ѭ���ˣ����������жϷŽ�ȥ��������ȥ���ǲ��ͺ���Ĵ��붼�����ˣ�
		//д�����߼�һ��Ҫ���,����Ҫ��������������Լ�д�Ĵ���
	{
		printf("%d ", a[i]);
		flag++;
	}





}
if (flag == 0)
printf("None");//����������棿
//��������ǶԵģ���Ϊ����������һ�����ݣ�����������Ϊѭ��һֱ�ظ���None�����ʵ��
//���ﲻ����else������ǰ�棬��Ϊ����ǰ������������кܶ����������������㡣�����˼��ǰ��
//���Ǹ������Ǽٵ�ʱ������None��������flag����¼�����ˡ�


int n = 0;
int a[10];
printf("Input n:");
scanf("%d", &n);
printf("Input %d integers:", n);
int i = 0;
int x = 0;
for (i = 0; i < n; i++)
{
	scanf("%d", &a[i]);//�ո������⣡,�ᵼ�����ݵ�һ�����벻��ȥ��



}
printf("Input x:");
scanf("%d", &x);

for (i = 0; i < n; i++)
{
	if (a[i] == x)
	{
		printf("index = %d", i);
		break;
	}
	if (i == n - 1)
		//������ָi�����һ����ʱ����Ϊǰ����������������ô����ǲ�������
		//���Ǹ�if������������õ�ѭ��������ж������ķ���
		printf("Not found");
	//return 0;main��������������0
}

/*printf("Not found");*///err,ܳ���֮꣬ǰд����ȥ����ccccccccccc������
//�Ҵ�����ϣ�����㷢�����ֿ���ʺ�






	void printArray(int a[][3]);
	int main(void)
	{

		int array1[2][3] = { {1,2,3},{4,5,6} };
		puts("Values in array1 by row are:");
		printArray(array1);

		int array2[2][3] = { 1,2,3,4,5 };
		puts("Values in array2 by row are:");
		printArray(array2);

		int array3[2][3] = { {1,2},{4} };
		puts("Values in array3 by row are:");
		printArray(array3);

		return 0;
	}
	void printArray(int a[][3])
	{
		int i, j;

		for (i = 0; i <= 1; i++)
		{
			for (j = 0; j <= 2; j++)
			{
				printf("%d ", a[i][j]);//�ǵÿո񣬲��ܿտ�
			}
			printf("\n");
		}
		printf("\n");
		return;
	}

		int a = 0;
		int n = 0;
		scanf("%d", &a);
		int i = 0;
		int sum = 0;
		for (i = 0; i < a; i++)
		{
			scanf("%d", &n);
			sum += n;
		}
		printf("Total of array element values is %d", sum);
		//����

		/*int i = 0;
	int n = 0;
	char a[10];
	int b[10];
	int k =strlen(a);
	scanf("%d", &n);
	for (i = 0; i < k; i++)
	{
		a % (10*10)
	}*///err
	/*k = strlen(a);*///�����ʱ���Ҫд[],����ʱ���üӣ�,strlenֻ�������ַ���

//���뵥����,������ѷ������������λ����˻��ǻ�Ϊ�ַ���ת�����
	//j = 0;
	//
	//for (i = 0; i < sz-1; i++)
	//{
	//	if (a[i] % 2 != 0)
	//	{
	//		b[i] = a[i];
	//	}
	//}
	////for (i = 0; i < k-1; i++)
	////{
	////	for ( j=i+1 ; j<k; j++)//��������forѭ������һ��������ʱ�򣬻�Ӱ�쵽ѭ������(��i=0��������ֵ}��
	////		//����һ����������������Ҫֱ��дj=1,��Ϊ��Ƚϵ����Ǵӵ�һ����ȫ�����ֱȽϵ�
	////		//���һ��������ȫ�����ֱȽϵģ���i+1���
	////	{

	////		if (b[i] < b[j])
	////		{
 ////               int tmp = b[i];
	////			b[i] = b[j];
	////			b[j] = tmp;
	////		}
	////		
	////		
	////		
	////		
	////	}
	////}
	//
	//for (i = 0; i < sz-1; i++)
	//	printf("%d", b[i]);

//int i = 0;
//char a[10] = { 0 };
//char b[10] = { 0 };
// int k =strlen(a);
//scanf("%s", &a);
//
//for (i = 0; i < k; i++)
//{
//	if (a[i] % 2 != 0)
//	{
//		b[i] = a[i];
//	}
//	else
//		break;
//	
//}
//int n = 0;
// /*sscanf(b, "%d", &n);*/
////û�а취��֤������ȫ���ǿյģ���������sccanf������
//
//printf("%d",n);
//����
		int n = 0;
		int a[10] = { 0 }; //�������Ҫ��ʼ��������ܻ���Ԥ�ⲻ���ĺ�����������ݲ�׼ȷ)����Ҫ͵��
		int i = 0;
		//��������Ҫ�����ڿ��Գ䵱�������,����һ��������ܶ������
		scanf("%d", &n);
		while (n != 0)
		{
			a[i] = n % 10;//ȡ��λ��
			n = n / 10;//���һλ����10��0��,������ȥ��ԭ�ȵĸ�λ
			i++;
		}
		int j;
		int flag = 0;
		for (j = i; 0 <= j; j--)//������㷨
		{
			if (a[j] % 2 != 0)//����
			{
				if (a[j] < 0)
				{
					if (flag == 0)
					{
						printf("-");
						flag++;//�����ǰ�棨˳�򣩣����flag��������Ϊ��ֻ��ӡһ����-����
					}

					a[j] = -a[j];//�߼���������
					printf("%d", a[j]);

				}
				else
					printf("%d", a[j]);

			}

		}

		
int i = 0;
float flag = 0;
int a[10000];//��ֹջ��������
int add = 0;
float sum = 0;

do
{
	i++;
	flag++;
	printf("Enter grade, -1 to end:\n");
	scanf("%d", &a[i]);//����������i��Ҫ��for����Ȼ��ѭ������i++����
	if (a[i] != -1)
		add += a[i];

} while (a[i] != -1);

sum = add / (flag - 1);//�������ͽ�������Ͷ�Ҫͳһ��
//�տ�ʼ����ͻ�++����������-1Ҳ��һ�Σ�����Ҫ-1
printf("Class average is %.2f", sum);


int n = 0;
int a[10];
int i = 0;
printf("Input n: ");
scanf("%d", &n);

//int k = strlen(a);������ַ������õģ�int��Ҫ�ã�
printf("Input %d integers: ", n);

for (i = 0; i < n; i++)
{
	scanf("%d", &a[i]);
}

int j = 0;
for (i = 0; i < n - 1; i++)//��һ����Ϊ����������10��ֻ��9��
{
	for (j = i + 1; j < n; j++)
	{

		if (a[i] < a[j])
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;

		}
	}
}
printf("After sorted: ");//���������ӡ����Ҫ��ӡ���ֻ��һ��
for (i = 0; i < n; i++)
	printf("%d ", a[i]);//ǰ��ֻ�ǰ�����ɸ�ֵ�������������Ҫ������һ��ѭ������������
	//��һֱ������©�������
			

		

			int n = 0;
			int i;
			int j;
			printf("Input n: ");
			scanf("%d", &n);
			int a[10];
			int max = -1;
			printf("Input %d integers: ", n);
			for (i = 0; i < n; i++)
			{
				/*scanf("%d", &n);*///�㿴������ǰ�涼����n���ﻹ��
				scanf("%d", &a[i]);

			}
			//for (i = 0; i < n - 1; i++)
			//{
			//	for (j = i + 1; j < n; j++)
			//	{
			//		if (a[i] < a[j])
			//		{
			//			max = a[j];
			//		}
			//		else
			//			max = a[i];//�㸴�ӻ���

			//	}
			//}
			//һ����˵���漰����������˫ѭ�������ֻ�Ǳȴ�С��ѭ���㹻��
			//�����±���򵥵��󷨾���ѭ���õ�i����һ��������¼������
			//int flag = 0;
			//for (i = 0; i < n; i++)//��Ҫ�Ҽ�������
			//{
			//
			//if (a[i] < a[i + 1])
			//{
			//	max = a[i + 1];
			//	flag++;
			//}//��Ҫ��else�ˣ��Ƚ�ʱ�Ѿ���0��1��1��2�Ա���
			//printf("max=%d, index=%d", max, flag);
			////����������Ǿ��޵ģ�һ����һ�����ܴ���ʹ���,���ֻ������,��Ϊ�����ıȽϾ�
			////����Ե�ǰ���������������׻���Ҫ˫ѭ��

			//����
			int index = 0;
			for (i = 0; i < n; i++)
			{
				if (a[index] < a[i]) //������index=0��i=0�ȣ��Զ�������i=1ѭ��������
					index = i;
			}
			printf("max=%d,index=%d\n", a[index], index);
			//��������õ�ѭ����iһֱ��ѭ�����ӣ�index�Ӷ���ֻ����������Żᱻ��ֵi
			//�����ȱ�֤�����a[index]�����ľͲ����֮�⣬���һ���ȷ���±꣬���Ƕ�һ��һ
			/*
			�������ʱ��һ��Ҫ���Լ���������Լ�д��ÿһ�����룡
				�ٲ�����Ҫ�ο������ϵģ�����Ҫ����ҲҪ���濴��������ôд�ģ�
				�м��������棬����������*/


			int n = 0;
			printf("Input n:");
			scanf("%d", &n);
			printf("Input array:");
			int i = 0;
			int j;
			int a[10][10];//ϵͳû��ʾ�ͱ��Ҷ����С
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)//˫ѭ����������
				{
					scanf("%d", &a[i][j]);
				}
			}
			//int row = 0; err
			int col = 0;
			int flag = 0;//�����棬�о���͸�

			for (i = 0; i < n; i++)
			{
				flag = 1;//��©�˼����ȴ��ڰ���
				col = 0;
				for (j = 0; j < n; j++)
				{
					if (a[i][col] < a[i][j])
						col = j;
				}//�жϸ������

				//for (i = 0; i < n; i++)
				//{
				//	if (a[row][col] > a[i][col])
				//		row = i;
				//}//������С
				//����������ûʲô���⣬������������ʵ���˲��ң�ʵ�ʲ�Ȼ���������ͻ�ִ�е����
				//ִ�е����Ľ�����кܴ����col�ָ������µ�ֵ��Ȼ��ʹ��������������㣬
				//��ô�Ͳ��ı�row�����ˣ�Ȼ�����ͻ��

				for (j = 0; j < n; j++)
					if (a[i][col] > a[j][col])//i��һ��ѭ������һֱ����ģ���Ҫ��i��ѭ��
					{
						flag = 0;
						break;//������ǰ
					}

				if (flag == 1)
				{
					//printf("a[%d][%d]=%d", row, col, a[row][col]);err
					printf("a[%d][%d]=%d", i, col, a[i][col]);
					break;//�ҵ���������ѭ������ֹ����ѭ�����¸�ֵ
		//���break���ܸ��ų�ȥ��Ҫ�Ž�ȥ�����ܵ����ų�����breakֻ��������ǰѭ����
			//������Ĵ�ѭ����û�н���������Ҫbreak


				}//��Ҫ����©����������ţ����ϰ��һ��Ҫ���ã���ֹ����Ĵ���
				//˼άһ��Ҫ���򻯣���Ҫ���Լ���˼ά����任��
				// 
				//�����ڸ������ݵ�ʱ�򿴿���֮ǰ�ı�����û�д���һ���������һ�Σ�



			}

			//�ܶ�ʱ����˼·���ԣ��������ڳ���ִ�еĳ��ֺ�˳���ϵ��߼��������⣬�����˳��
			//�����˼·����д����

			int n, m = 0;
			scanf("%d%d", &m, &n);
			int a[20][20];
			int b[20][20];
			int i, j = 0;
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
				{
					scanf("%d", &a[i][j]);


				}
			}
			for (i = 0; i < m; i++)
				for (j = 0; j < n; j++)
					b[j][i] = a[i][j];//�����ϵĸ�ֵ
					//���⿪ѭ������ֹscanfû��ȫ���뱻��ֵ��������



			for (i = 0; i < n; i++)
				//�����ʽ�ĸı䣬���������б���������У�ע��ѭ����n��m�Ի���
				//��ֵʱѭ����˳����Ҫ���������ʽ��Ҫ���������
			{
				for (j = 0; j < m; j++)
				{
					printf("%4d", b[i][j]);

				}
				printf("\n");//ÿ�н������ٻ��У����ź���
			}

			//����������


			int n = 0;
			int a[10] = { 0 };
			int i = 0;
			int j;
			scanf("%d", &n);
			while (n != 0)
			{
				a[i] = n % 10;
				n = n / 10;
				i++;
			}
			int m, k, tmp;
			for (j = 0; j < i - 1; j++)//��������
			{
				for (k = 1; k < i; k++)
				{
					if (a[j] < a[k] && j <= k)
						//Ҫ����j<=k����Ȼ������j��������һ�ζԵ��Ͱ׸���,��������Ҫ��
					{
						tmp = a[j];
						a[j] = a[k];
						a[k] = tmp;
					}

				}
			}

			for (m = 0; m < i; m++)
				printf("%d", a[m]);


			for (j = 0; j < i - 1; j++)
			{
				for (k = 1; k < i; k++)
				{
					if (a[j] > a[k] && j <= k)
					{
						tmp = a[j];
						a[j] = a[k];
						a[k] = tmp;
					}

				}
			}
			printf(" ");
			for (m = 0; m < i; m++)
				if (a[m] != 0)
					printf("%d", a[m]);
			//ֱ�Ӵ�ӡ���������������ַ




			int n;
			printf("Input n:\n");
			scanf("%d", &n);
			int a[20][20];
			printf("Input array:\n");
			int i, j;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					scanf("%d", &a[i][j]);


				}
			}
			int sum = 0;
			for (i = 0; i < n - 1; i++)//n-1��ʾȥ�����һ�к���
			{
				for (j = 0; j < n - 1; j++)
				{
					if (i != n - 1 && j != n - 1 && i + j != n - 1)
						//������Խ��ߵĹ��ɾͼ�ס��(��������Խ��ߵ�������ɣ�
						//���ľ��ǣ����Լ���֪����i,j,n֮��Ĺ�ϵ������һ���������������
						//�Ӷ���ʾ�����Խ���
						//������һ�κ�������Ϊһ��n����kҲ����.
					{
						sum += a[i][j];
					}

				}
			}
			printf("sum=%d", sum);

			int i;
			float pay;
			float Hours = 0;
			float Charge = 0;
			int Car = 0;
			float a[10];
			//��һ�β���ֵ�������ٶ����ݣ����벻���Ĵ���
		   //�����ԣ�����û�о���
			for (i = 0; i < 3; i++)
			{
				scanf("%f", &a[i]);//ţͷ�������졣�����������ﶼҪ�ģ�
			}
			printf("  Car          Hours         Charge\n");
			//ceil������С��ֱ��ȡ��
			for (i = 0; i < 3; i++)
			{

				Car++;
				if (a[i] < 3)
				{
					pay = 2.00;
				}
				else if (3 <= a[i] && a[i] < 19)
				{
					pay = 2.00 + ceil(a[i] - 3) * 0.5;
				}
				else
				{
					pay = 10.00;
				}
				Charge += pay;
				Hours += a[i];
				printf("   %d            %.1f           %.2f\n", Car, a[i], pay);
				//Ĭ��float����6λ�����Ա���һλС��ҲҪǿ����
				//�������ۼӵ�ֱ�Ӵ���ȥ����Ϊÿ���˵õ��Ķ��Ƕ�����
				//���ͺ���Ҫ�����Ե����ͻ�ʹ�ó�����Ԥ��ֵ���ྶͥ��
				//��������ô���붼û�ã���Ϊ���ѭ���Ѿ��������ˣ�
				//һ��һ�����������û�в��������
			}



			printf("TOTAL           %.1f          %.2f", Hours, Charge);





	return 0;
}

