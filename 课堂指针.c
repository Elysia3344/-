#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<math.h>
int main()
{
	int array[1000];
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", (array + i));
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", *(array + i));
	}






	return 0;
}
void inverse(int* p, int n)//����*
{
	int i = 0;
	for (i = n - 1; i >= 0; i--)
	{
		printf("%d ", *(p + i));//��ӡ��ֵ���ǵ�ַ����*
	}

}
int main()
{

	int n, i, m;
	int a[100] = { 0 };//�Ժ��ڴ�������һ��������С��
	int* p = a;//һ����˵������ֻ��д�������־����ˣ���ֱ��&+������ֱ����һ������Ϊ��λ�ˣ�����д�϶���
	//һ����������ָ�����һ�����������������ȱ�ֱ��int* ���飡
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m);
		*(p + i) = m;//��ֵ������(��Ϊ������ַ����ֵ)
	}
	inverse(p, n);
}
//int main()
//{
//	//int array[1000];
//	//int n, i;
//	//scanf("%d", &n);
//	//for (i = 0; i < n; i++)
//	//{
//	//	scanf("%d", (array + i));
//	//}
//	//for (i = 0; i < n; i++)
//	//{
//	//	printf("%d ", *(array + i));
//	//}
//
//	/*int array[1000];
//	    int n, i;
//    int* pointer;
//		    scanf("%d", &n);
//	    pointer = array;
// 	    for (i = 0; i < n; i++)
//		 {
//		 	        scanf("%d", &pointer[i]);
//		    }
//	 for (i = 0; i < n; i++)
//		 {
//			        printf("%d ", pointer[i]);
//			    }
//*/
//
//	//char* str = "C Language";
//	//str = str + 2;
//	//printf("%s", str);
//
//	/*char* day[7] = { "Sunday","Monday","Tuesday",
//	"Wednesday","Friday","Saturday" };
//	int i;
//	for (i = 0; i < 6; i++)
//	{
//		puts(day[i]);
//	}*/
//
//	
//
//
//
//	return 0;
//}

//int main()
//{
//	void fun(int n);
//	void (*funp)(int m);
//	funp = fun;
//	(*funp)(1);
//
//
//
//
//	return 0;
//}
//void fun(int n)
//{
//	printf("Result :%d", n);
//	return;
//}
//int* search(int(*pRow)[4], int n);
//int main()
//{
//	int score[3][4] = { {60,70,80,90},
//		                {56,89,67,88},
//		                {34,78,90,66} };
//
//	int* pCol;
//	int n, i;
//	scanf("%d", &n);
//	pCol = search(score, n);
//
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", *(pCol + i));
//	}
//	
//
//
//
//
//	return 0;
//}
//int* search(int(*pRow)[4], int n)
//{
//	int* pt;
//	pt = *(pRow + n);
//
//	return pt;
//}

//int main()
//{
//	int array[1000];
//	int n;
//	int* pointer;
//	scanf("%d", &n);
//	for (pointer = array; pointer < array + n; pointer++)
//	{
//		scanf("%d", pointer);
//	}
//	for (pointer = array; pointer < array + n; pointer++)
//	{
//		printf("%d ", *pointer);
//	}
//
//
//
//
//
//	return 0;
//}
//#define N1 100
//#define N2 100
//#define N 200
//
//void link(char s1[], char s2[], char s[]);
//
//int main()
//{
//	char string1[N1], string2[N2], string[N];
//
//	gets(string1);
//	gets(string2);
//
//	link(string1, string2, string);
//
//	puts(string);
//
//
//
//
//	return 0;
//}
//
//void link(char s1[], char s2[], char s[])
//{
//	int index, position;
//
//	position = 0;
//
//	for (index = 0; s1[index] != '\0'; index++)
//	{
//		s[position] = s1[index];
//		position++;
//	}
//	for (index = 0; s2[index] != '\0'; index++)
//	{
//		s[position] = s2[index];
//		position++;
//	}
//	s[position] = '\0';
//	return;
//}

//int main(int argc,char* argv[])
//{
//	int i;
//	printf("%d\n", argc);
//
//	for (i = 1; i < argc; i++)
//	{
//		printf("%s\n", argv[i]);
//	}
//
//
//
//
//	return 0;
//}

//int main()
//{
//	/*int* p = NULL;
//	int n, i;
//	int total;
//	scanf("%d", &n);
//	p = (int*)malloc(n * sizeof(int));
//
//	if (NULL == p)
//	{
//		printf("Error\n");
//		exit(1);
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &p[i]);
//	}
//	total = 0;
//
//	for (i = 0; i < n; i++)
//	{
//		total += p[i];
//	}
//	printf("total =%d\n", total);
//	free(p);*/
//
//	/*char* p[3] = { "Heilongjiang"," Technology"," Institute of" };
//	char* temp;
//	temp = p[1];
//	p[1] = p[2];
//	p[2] = temp;
//	printf("%s%s%s\n", p[0], p[1], p[2]);*/
//
//
//
//	return 0;
//}

///*double average(double* p,int score[100][10], int m, int n)*///err
////��Ҫ��ָ�����������Ϊ��������������٣����ܷ���ֵ��
////���Ҫ��ָ�룬��ָ�����ú����ı�ʵ��.�����ں�������ɣ����ܳ��⡣
////����return��ȥ����Ұָ��.
//double average(int score[100][10], int m, int n)
//{
//	int i, j;
//	
//
//	int sum[100] = { 0 };
//
//
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//
//			sum[i] += score[i][j];//ֱ����ôд�Ͷ��ˣ���Ϊm��һ��ѧ���������൱���ȼ����һ��ѧ����
//			//�ܳɼ�
//		}
//
//
//	}
//	int add = 0;
//	for (i = 0; i < m; i++)
//		add += sum[i];
//
//	double ave = add / (n * m);
//
//	printf("%.2lf",ave);
//}
//int main()
//{
//	int m, n, j, i;
//	scanf("%d%d", &m, &n);
//	int score[100][10] = { 0 };
//	for (i = 0 ;i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &score[i][j]);
//			
//		}
//	}
//
//	 average(score[100][10], m, n);//���ú������ü����ͣ�
//	 //�����鲻������



//int main()
//{
//
//	//int m, n, j, i;
//	//double sum = 0;
//	//	scanf("%d%d", &m, &n);
//	//	int score[100][10] = { 0 };
//	//	for (i = 0; i < m; i++)
//	//	{
//	//		for (j = 0; j < n; j++)
//	//		{
//	//			scanf("%d", &score[i][j]);
//	//			sum += score[i][j];
//	//		}
//	//	}
//	//	double ave = 0;
//	//	ave = sum / (n * m);
//	//	printf("%.2lf", ave);
//	////��nm��ָ�룡		
//
//
//	
//
//		/*if (sz % 2 == 0)
//		{
//			for (i = 0; i < sz / 2; i++)
//			{
//				b[i] = a[sz - 1 - i];
//			}
//		}
//		else
//		{
//			for (i = 0; i < (sz-1)/2; i++)
//			{
//				b[i] = a[sz - 1 - i];
//			}
//		}*///�����چ����ˣ����׻��ҡ�
//		/*for (i = 0; i < sz; i++)
//		{
//			if (b[i] != a[i])
//			{
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("Yes");
//		}
//		else
//			printf("No");*///���浹�ǿ���
//
//
//
//	//char a[100] = { 0 };
//	//char* p = a;
//	//int i, j, n;
//	//gets(p);//�ַ�������gets����scanf
//	//
//	//n = strlen(p);
//	//
//	////���ñ������Բ��ö������
//	//for(i = 0, j = n - 1; i < j; i++, j--)
//	//{
//	//	if (*(p+i)!=*(p+j))
//	//		break;
//	//}
//	//if (i < j)
//	//{
//	//	printf("No");
//	//}
//	//else
//	//{
//	//	printf("Yes");
//	//}
//	//
//
//	
//
//	
//	
//	return 0;
//}

////double average(int score[100][10], int m, int n)
////{
////}
//int main()
//{
//
//	int m, n;
//	
//	scanf("%d%d", &m, &n);
//	int score[100][10] = { 0 };
//	
//	/*double average(score,m,n);*/
//	double sum = 0;
//	int i, j;
//	int(*p)[10] = score;
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", p);//ָ���Ѿ��������ַ�ˣ����Բ�����Ҫ�ٴ���&
//			sum += *(p[j]+i);
//		}
//	}
//	double ave = 0;
//	ave = sum / (n * m);
//	printf("%.2lf", ave);
//	//��nm��ָ�룡		
//
//
//
//	return 0;
//}
//

//	/*int n = 0;
//	scanf("%d", &n);
//	int i;
//	char* p = NULL;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", p);
//	}*/
//
//
//
//	return 0;
//}