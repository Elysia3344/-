#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<math.h>
//int main()
//{
//	int array[1000];
//	int n, i;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", (array + i));
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *(array + i));
//	}
//
//
//
//
//
//
//	return 0;
//}
//void inverse(int* p, int n)//����*
//{
//	int i = 0;
//	for (i = n - 1; i >= 0; i--)
//	{
//		printf("%d ", *(p + i));//��ӡ��ֵ���ǵ�ַ����*
//	}
//
//}
//int main()
//{
//
//	int n, i, m;
//	int a[100] = { 0 };//�Ժ��ڴ�������һ��������С��
//	int* p = a;//һ����˵������ֻ��д�������־����ˣ���ֱ��&+������ֱ����һ������Ϊ��λ�ˣ�����д�϶���
//	//һ����������ָ�����һ�����������������ȱ�ֱ��int* ���飡
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &m);
//		*(p + i) = m;//��ֵ������(��Ϊ������ַ����ֵ)
//	}
//	inverse(p, n);
//}
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

//int main()
//{
//
//    int n = 0;
//    char a[100];
//    scanf("%d", &n);
//    int i, j;
//   /* int tmp = 0;*///err
//    char tmp;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%s", a[i]);//������scanf��&��
//            //gets��puts���ܶԵ���������Ԫ��ʹ��
//    }
//
//    for (i = 0; i < n - 1; i++)//ѡһ������ȥ�����������ֱȽ�
//    {
//        for (j = 0; j < n - 1 - i; j++)//�ڶ������ظ����������һ�����ֱȽϵĴ���
//        {
//            /*if (strcmp(a[j],a[j+1])>0)  
//            {
//                strcpy(tmp, a[j]);
//                strcpy(a[j], a[j + 1]);
//                strcpy(a[j + 1], tmp);
//            }*///����Ҫ�ö�ά�������
//
//            if (a[j] > a[j + 1])
//            {
//                tmp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = tmp;
//            }
//        }
//    }
//    for (i = 0; i < n; i++)
//        printf("%s\n", a[i]);
//   
//
//
//
//
//    return 0;
//}
// 
// 
//��������鷳����������ַ�����ASCII��ֵ������
//һ�������������⣬�Ϳ���ʹ��C���Ե�qsort������
//����ַ����ıȽϺ���strcmp��strcmp���������������ıȽϾ�������ַ�����ASCIIֵ���Ƚϵģ�
//���£�����һ���ص���������ʹ��qsort���򼴿ɡ�
//#define MAX 100
//
//struct keyValue {
//    char arr[MAX];
//    int len;
//};
//
//// �ص�����--����ASCII����ַ��Ƚ�
//int cmp(const void* a, const void* b) {
//    return strcmp((char*)a, (char*)b);
//}
//
//int main() {
//    int n, i;
//    struct keyValue a[1000];
//    scanf("%d\n", &n);
//    for (i = 0; i < n; i++) {
//        scanf("%[^\n]\n", a[i].arr);
//        a[i].len = strlen(a[i].arr);
//    }
//    qsort(a, n, sizeof(a[0]), cmp);
//    for (i = 0; i < n; i++) {
//        // �������ѭ���ұ�������printf("%s\n", a[i].arr);�������ָ�ʽ���ƶ�ֻ������һ���֣�����ÿ���ַ��������һ���ַ�����֪��bug�������Ը��õ����ַ�ѭ������������������ʱ�临�Ӷ�
//        for (int j = 0; j < a[i].len; j++) {
//            printf("%c", a[i].arr[j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}
//struct str
//{
//	char a[100];
//	int len;
//};
////void num(void* a, void* b)
////{
////	return strcmp(void* a,  void* b);
////}//err
//
//int num(void* a, void* b)//��ס�����ʽ��,��������������������ַ�ָ��׼���Ƚ�
//{
//	return strcmp((char*) a, (char*) b);//����ֵ�������Ǹ������ϴ��Ƚϵ����ͣ����һ��Ҫ��������������
//}
//
//
//int main()
//{
//	int n = 0;
//	int i, j;
//	scanf("%d\n", &n);//���ﲻ��\n�ͻᱨ��
//	//����scanf scanf("%d\n", &n)�е�\n����ʾ�ȴ����з�,
//	//���Ƕ�ȡ�����������Ŀհ��ַ�,
//	//	������һ����֮��,���ǲ���������ʾ��,Ҫ���ٽ��յ�һ���ǿհ��ַ��Ż�ֹͣ
//	//	//��Ŀ�Ͽ����ֲ�������ʹҪ���һ��������ֹͣ
//	struct str b[1000];//�ṹ�����飬����������ö������
//	for (i = 0; i < n; i++)
//	{
//		scanf("%[^\n]\n", b[i].a);//Ҫ��[]��������,�����Ҫ��\n��ֹ��ȡ�����������հ�����,
//		//��Ϊ���������%[^\n]��������\n������������ͣ���Ҳ��Ϊ�����������еķ��ţ�����Ҫ����
//		//����صĿհ��ַ���\n
//		b[i].len = strlen(b[i].a);//�󳤶�
//	}
//
//	qsort(b, n, sizeof(b[0]), num);//��ֵ����������Ԫ�ش�С����������
//	//�����ר������ĺ���
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < b[i].len; j++)
//		{
//			printf("%c", b[i].a[j]);
//			//�������˼Ϊһ���ַ�����Ϊһ��һ���ַ���ӡ�������ȶ����ղ�����
//			 // �������ѭ���ұ�������printf("%s\n", a[i].arr);
//			/*�������ָ�ʽ���ƶ�ֻ������һ���֣�����ÿ���ַ��������һ���ַ���
//				��֪��bug�������Ը��õ����ַ�ѭ�������*/
//		}
//		printf("\n");
//	}
//
//	
//	
//
//
//
//
//	return 0;
//}

//int num(void* a, void* b)//��ס�����ʽ��,��������������������ַ�ָ��׼���Ƚ�
//{
//	return strcmp((char*)a, (char*)b);//����ֵ�������Ǹ������ϴ��Ƚϵ����ͣ����һ��Ҫ��������������
//}


//int main()
//{
//	int n = 0;
//	int i, j;
//	scanf("%d\n", &n);
//	//����scanf scanf("%d\n", &n)�е�\n����ʾ�ȴ����з�,
//	//���Ƕ�ȡ�����������Ŀհ��ַ�,
//	//	������һ����֮��,���ǲ���������ʾ��,Ҫ���ٽ��յ�һ���ǿհ��ַ��Ż�ֹͣ
//	//	//��Ŀ�Ͽ����ֲ�������ʹҪ���һ��������ֹͣ
//	char a[1000][100];
//	char(*p)[100] = a;
//	int len[100];
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%[^\n]\n", p[i]);//Ҫ��[]��������,�����Ҫ��\n��ֹ��ȡ�����������հ�����,
//		//��Ϊ���������%[^\n]��������\n������������ͣ���Ҳ��Ϊ�����������еķ��ţ�����Ҫ����
//		//����صĿհ��ַ���\n
//		//�󳤶�
//		len[i] = strlen(*(p[i]));
//	}
//
//	qsort(*p, n, sizeof(*(p[0])), num);//��ֵ����������Ԫ�ش�С����������
//	//�����ר������ĺ���
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < (len[i]); j++)
//		{
//			printf("%c", p[i][j]);
//			//�������˼Ϊһ���ַ�����Ϊһ��һ���ַ���ӡ�������ȶ����ղ�����
//			 // �������ѭ���ұ�������printf("%s\n", a[i].arr);
//			/*�������ָ�ʽ���ƶ�ֻ������һ���֣�����ÿ���ַ��������һ���ַ���
//				��֪��bug�������Ը��õ����ַ�ѭ�������*/
//		}
//		printf("\n");
//	}
//
//
//
//
//
//
//
//	return 0;
//}



int main()
{

	int array[1000];

	int n;

	int* pointer;

	scanf("%d", &n);

	for (pointer = array; pointer < array + n; pointer++) {

		scanf("%d", pointer);

	}


	for (pointer = array; pointer < array + n; pointer++) {

		printf("%d ", *pointer);

	
	}
	return 0;
}	

#define N1 100
#define N2 100
#define N 200

void link(char s1[], char s2[], char s[]);
int main()
{
	char string1[N1];
	char string2[N2], string[N];

	gets(string1);

	gets(string2);

	link(string1, string2, string);

	puts(string);

	return 0;
}

void link(char s1[], char s2[], char s[])
{
	int index, position;

	position = 0;

	for (index = 0; s1[index] != '\0'; index++) {

		s[position] = s1[index];
		position++;
	}

	for (index = 0; s2[index] != '\0'; index++) {

		s[position] = s2[index];

		position++;

	}


	s[position] = '\0';


	return;

}

//int main()
//{
	//int m, n, i, j;
	//int a[100][10];
	//double sum = 0;
	//scanf("%d%d", &m, &n);
	//for(i=0;i<m;i++)
	//	for (j = 0; j < n; j++)
	//	{
	//		scanf("%d", &a[i][j]);//��©&
	//		sum += a[i][j];
	//	}
	//double ave = sum / (n * m);
	//printf("%.2lf", ave);

	//int m, n, i, j, k;
	//int a[100][10];
	//double sum = 0;
	//scanf("%d%d", &m, &n);
	//for (i = 0; i < m; i++)
	//	for (j = 0; j < n; j++)
	//	{
	//		scanf("%d", &a[i][j]);//��©&
	//		
	//	}
	//
	//scanf("%d", &k);
	//for (j = 0; j < n; j++)
	//{
	//	printf("%d ", a[k][j]);
	//}

//	int m, n, i, j;
//	int a[100][10];
//	double sum = 0;
//	scanf("%d%d", &m, &n);
//	for(i=0;i<m;i++)
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &a[i][j]);
//		
//		}
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (a[i][j] < 60)
//              for (j = 0; j < n; j++)
//		{
//			printf("%d ", a[i][j]);
//			
//		}
//			printf("\n");	//�������ֹͣ��Ҳ�޷���ֹ��������ôд����,����Ӧ�÷�����������
//		}
//		
//		
//	}
//
//
//	return 0;
//}

//int main(int argc,char* argv[])
//
//{
//	int i;
//	printf("%d\n", argc);
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
//	int* p = NULL;
//	int n, i;
//	int total;
//	scanf("%d", &n);
//	p = (int*)malloc(n * sizeof(int));
//	if (NULL == p)
//	{
//		printf("Error\n");
//		exit(1);
//	}
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &p[i]);
//	}
//	total = 0;
//	for (i = 0; i < n; i++)
//	{
//		total += p[i];
//	}
//	printf("total = %d\n", total);
//	free(p);
//
//
//	return 0;
//}
// 

int main()
{//��������Ǹ�����Ŀ���㷨���������ݣ�ע�����濴���ÿ�仰
	int N = 0;
	scanf("%d", &N);	//��ʾ����
	int a[100][100] = { 0 };//����ʱ���Դ�����һ��������������鿴
	int k;//k��ʾ�ŵ���ʲô����

	a[0][(N + 1) / 2 - 1] = 1;//�м���

	int n = N * N;
	int i = 0;
	int j = (N + 1) / 2 - 1;//��Ϊ�����0��ʼ

	for (k = 2; k <= n; k++)
	{
		///*if (k % N == 0)*///���������Ե���������
		if ((k - 1) % N == 0)//�����Ǳ������������N��������ţ�//ע��������������������������
			//���������������Ϣ����ۿ�����ȶ�,��Ҫ������.
		{
			a[i + 1][j] = k;
			i = i + 1;//��ֵ��ȷ�����һ������,����һ��ѭ����䵱���һ�������Ԫ��
			continue;//break��ֱ������������ѭ��������������һ�ε�ѭ����continue���ǽ�����һ��ѭ��
		}



		/*if(i<0)*///����д�ǲ��Եģ�Ҫ�������ʲô״̬�µ�i<0,�յ��ǿ���i��j�ò��ñ������
		if (i - 1 < 0)//���ж�һ��ı����ԣ�,��ס�ж�ʱ�ĸ�λ�ú������ڵ�λ���ǲ�ͬ��
		{
			//i = 0;
			//j = (N + 1) / 2 - 1;//��ʼ��,err

			a[N - 1][j + 1] = k;
			i = N - 1;
			j = j + 1;
		}
		else if (j + 1 > N - 1)
		{
			//int i = 0;
			//int j = (N + 1) / 2 - 1;//��ʼ��,���У���ֻ�ܳ�ʼ��һ�εĽ�����ǶԵģ�������һ��ʼ��ֵ
			a[i - 1][0] = k;

			j = 0;
			i = i - 1;
		}
		else
		{
			a[i - 1][j + 1] = k;
			i = i - 1;
			j = j + 1;
		}
		//�Ҹ�ֵ��Ҳû��ϵ����Ϊ���ջ��ǻᱻ����//���������Ҹ�ֵ��ʱ����ǰ��ȷ������Ҳ���Ҹ���
//ȫ���ж�û�н����Ͳ���Ҫ�ȱ���ֵ������Ҫ���֡����衱�ĸ�ֵ���ڡ�
	}

	int m, p;
	for (m = 0; m < N; m++)
	{	/*	for (m = 0; m < N; m++)*///err,�����Ӱ������m��ֵ�����Բ�����ôд.
		for (p = 0; p < N; p++)
		{
			printf("%4d", a[m][p]);//���4d��ֱ���Զ����Ҷ�����λ�������£����Ҽ��Ҳ�պ��˸���
		}
		printf("\n");
	}
	//��û�д𰸵İ���������̽��������ȷ�𰸵ĵ�·������������ڲ���һ���գ���ϲ�ɺ�.





	return 0;
}
int main()
{
	int m, n, i, j;

	int a[100][10];
	int(*p)[10] = a;
	double sum = 0;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			scanf("%d", (*(p + i) + j));
			sum += *(*(p + i) + j);
		}
	double ave = sum / (n * m);
	printf("%.2lf", ave);




	return 0;
}
