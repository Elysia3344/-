#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>
//extern int Add(int, int);//��Ȼ�����벻������Add��Ҫ�Լ�дһ�����붨�壩
//int Add(int x, int y)//���庯����Ҫ�ӣ���
//{
//	int z = 0;
//	z = x + y;
//
//	return z;
//
//
//}
//void test()
//{
//	//static int a = 1;
//	//a++;
//	//printf("%d\n", a);//û��static�������ʱ����������ֻ��һ�Σ��������ʵ�֡���������
// �����ӳ��������ڣ�ʹ�����ڲ����ͷ��ʼ��������Ծֲ���
//	////û��static:22222
//	////�У�23456
//	//static����ȫ�ֱ���ʱ���ı�����������ȫ�ֱ���ֻ�����Լ���Դ�ļ���ʹ�á���׼ȷ���Ϊ�ı����������ԣ����ⲿת��Ϊ�ڲ���
//
//}
//
//
//

//int Max(int x, int y)//��Ҫ����
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
//#define MAX(X,Y) (X>Y?X:Y)//��Ҳ���ӣ�
/*#define large(x,y) (x>y?x:y)*///�������ﶼ�ǿ����Լ�����ģ�ֻҪ��������˼����

//
//struct Book
//{
//	char name[20];
//	short price;
//
//
//};






int main()
{
//	int b = 20;
//	////����
//	//int max = Max(a, b);//һ��ʼ����ֵ��ֱ��ʹ��max,�����������������ǲ��Ǻ����͵���������
//	int max = 0;
//	//max = (a > b ? a : b);//���ֲ���Ҫ�õ�ȫ�ֱ���
//	max =MAX(a, b);//��Ҫȫ�ֱ���
//	printf("%d\n", max);

	//int sum = Add(a, b);
	///*int a = 10;
	//int b = 20;
	//int max = 0;
	//max = (a > b ? a : b);
	//printf("%d\n", max);*/
	//
	////typedef �����ض��壨������
	//typedef unsigned int u_int;
	//unsigned int num = 20;
	//u_int num2 = 30;

	//register int a = 10;//register�����a����ɼĴ�������

	//int i = 0;
	//while (i < 5)
	//{
	//	test();//�ֲ�������test()��ǰ���ȫ��ǣ��������test�����ȶȴ��ڵ����ġ�i"
	//	i++;
	//	//printf("%d\n", i);
	//}

	//extern int g_val;//�����ⲿ����
	//printf("%d\n", g_val);

	//int a = 10;
	//int b = 20;
	//int sum = Add(a, b);
	//printf("sum= %d\n", sum);//ע��Ҫ���Ŷ��塣

//#define �����ʶ������
	//�����Զ����-����������#define MAX 100
//
//	int a = 10;//4���ֽ�
//	int* p = &a;//���ڲ���a�ĵ�ַ��֮���Բ�ֱ��ʹ��&a��Ϊ�˱��ں���׷��a��λ�á�int*��Ϊ�˴�ŵ�ַ��ָ�����
//	*p = 20;//*-�����ò�������׷��p/&a,������Ը�ֵ��
//////&a;//ȡ��ַ
////printf("%p\n", &a);//���Ҫ֪����a����&a,����{}��Ҫ��ע�͵��ˡ���ַ������p
//printf("%d\n", a);//����Ǵ�ӡa,�ǻ��ǵ���%d

	//char ch = 'w';
	//char* pc = &ch;
	//*pc = 'a';
	//printf("%d\n");//���ֻ��һ�����������Ͳ���Ҫ�صر�����Ҫ���˭
	////ָ��Ķ��岻�ܸ�һ��ʼ�ı�������һ�£�p��ָ�����

	//double d = 3.14;
	//double* pd = &d;
	//*pd = 5.5;
	//printf("%lf\n", d);
	//printf("%lf\n", *pd);
	//printf("%d\n", sizeof(pd));
	//printf("%d\n", sizeof(double*));//һ���ַ����ʹ�С��һ�����Ҷ�Ϊ%d
	//printf("%d\n", sizeof(int*));//32λ��4�ֽڣ�64��8
	////...

	//struct Book bl = { "c����", 55 };//sturct�ô����ţ������ṹ������
	//printf("����:%s\n", bl.name);
	//printf("�۸�:%dԪ\n", bl.price);//��������Ҫд��������Ҫ����Ϊ�˴�ӡ�������Ŀ�ģ�
	////bl�Ǹ������Ķ��壬name��price��ȫ�ֱ����С���Ҫָ������Ŀ�����Ժ���Ҫ����������β׺
	//bl.price = 15;
	//printf("�޸ĺ�۸�:%d\n", bl.price);//price�Ǳ���������ֱ���޸�

	//struct Book bl = { "c����", 55 };
	//struct Book* pb = &bl;
	////����pb��ӡ���ҵ������ͼ۸�
	////	�ṹ�����.��Ա
	////	�ṹ��ָ��->��Ա
	////
	//
	//printf("%s\n", (*pb).name);
	//printf("%d\n", (*pb).price);
	//
	//printf("%s\n", pb->name);
	//printf("%d\n", pb->price);

 //  	struct Book bl = { "c����", 55 };//bl.nameָ�����������ǰ��ȫ�ֱ�����name(���ƣ�
 //  	strcpy(bl.name, "c++");//"bl"����൱���ַ������ͣ�������strcpy:�ַ�������-�⺯��-string.h
	//printf("%s\n", bl.name);

	//int age = 10;
	//if (age < 18)
	//	printf("δ����\n");
	//else
	//	printf("����\n");

	//int age = 11;
	//if (age < 18)
 //    printf("δ����\n");	
	//else if (age >= 18 && age < 28)
	//		printf("����\n");
	//	else if (age >= 28 && age < 50)
	//		printf("׳��\n");
	//	else
	//		printf("����\n");//һ��Ҫ�����߼�˳�򣬲��ܳ���©������©����ִ�в��ˣ����뱣֤�����ܹ�����ִ�У��������У�
	//



	//int age = 11;
	//if (age < 18)
	//{
	//	printf("δ����\n");
	//	printf("����̸����\n");
	//}//������Ҫ�Ӵ�����
	//else
	//{
	//	if (age >= 18 && age < 28)
	//		printf("����\n");
	//	else if (age >= 28 && age < 50)
	//		printf("׳��\n");
	//	else
	//		printf("����\n");//һ��Ҫ�����߼�˳�򣬲��ܳ���©������©����ִ�в��ˣ����뱣֤�����ܹ�����ִ�У��������У�
	//}

// = ��ֵ ==�ж����

//int num = 4;
//if (5 == num)//������ӣ�
//{
//	printf("hehe/n");
//}//if����ϰ�߼�{}
//
//
//int i = 1;
//while (i < 100)//whileֻ��һ��ѭ����������Ҫif����Ҫдif
//{
//	if (i % 2 == 1)
//		printf("%d\n", i);
//	i++;
//
//
//
//}

//int i = 1;
//while (i < 100)//whileֻ��һ��ѭ����������Ҫif����Ҫдif
//{
//	if (i % 2 != 0)
//		printf("%d\n", i);
//	i++;//���һ������©����Ȼ��Զ����1
//
//
//}



//int i = 1;
//while (i < 100)//whileֻ��һ��ѭ����������Ҫif����Ҫдif
//{
//	printf("%d\n", i);
//	i += 2;
//
//
//}

//int day = 0;
//scanf("%d", &day);
//switch (day)//Ҳ����Ҫ��
//{
//case 1:
//	printf("����1\n");
//	break;
//
//case 2:
//	printf("����2\n");
//	break;
//case 3:
//	printf("����3\n");
//	break;
//case 4:
//	printf("����4\n");
//	break;
//case 5:
//	printf("����5\n");
//	break; 
//case 6:
//		printf("����6\n");
//		break;
//case 7:
//		printf("������\n");
//		break;
//

//int day = 0;
//scanf("%d", &day);
//switch (day)//Ҳ����Ҫ��
//{
//case 1:
//
//
//case 2:
//	
//case 3:
//	
//case 4:
//	
//case 5:
//	printf("������\n");
//	break;
//case 6:
//	
//case 7:
//	printf("��Ϣ��\n");
//	break;
//default:printf("�������\n");//default�ǲ��ڷ�Χ�ڵ�����
//	break;
//



//}

//int n = 1;
//int m = 2;
//switch (n)//n��ʱΪ1��ֱ�ӽ���case 1,Ȼ��һֱ˳��ȥ
//{//switch����Ƕ��ʹ��
//case 1: m++;
//case 2: n++;
//case 3:
//	switch (n)//����nΪ2�ˣ���case 2
//	{
//	case 1:n++;
//	case 2:m++; n++; break;
//	}
//case 5:m++;
//	break;
//default:
//	break;
//}
//printf("m=%d,n=%d\n", m, n);

//int i = 1;
//
//while (i <=10)
//{
//	printf("%d", i);
//	i++;
//}
//
//int i = 1;
//
//while (i <= 10)
//{
//	if (i == 5)
//		break;
//	printf("%d", i);
//	i++;
//}

//
//int i = 1;
//
//while (i <= 10)
//{
//	if (i == 5)
//		continue;
//	printf("%d", i);
//	i++;
//}

//int ch = getchar();//����
//putchar(ch);//���
////printf("%c\n", ch);Ч��һ��,%c��getchar��Щ���͵�

//int ch = 0;//����
//while ((ch = getchar())!= EOF)//��������ŵ�һһ��Ӧ��EOF�Ǽ�������ctrl+z,end of file ->-1
//putchar(ch);//���

//printf("%c\n", ch);Ч��һ��,%c��getchar��Щ���͵�

//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//10��ѭ������ӡ��ʮ��Ԫ��,arr�����ﶨ�壬Ȼ����i��ʵ��ѭ����ӡ
//int i = 0;//�����Ŀ���Ƕ���i,Ҳ����ֱ��д�� int i;
//for (i = 0; i < 10; i++)//forҲ�ǲ��ӣ�for�ĸ�ʽ����Ҫ������һ�𣬲���©һ��//��ʼ�����жϣ�����
//{
//	printf("%d", arr[i]);
//}

//for (;;)//for���������ʡ�ԣ���for���жϲ��ֱ�ʡ�ԣ���ôĬ�Ϻ�Ϊ��
//{
//	printf("hehe\n");
//}
	//

	//int i = 0;
	//int j = 0;
	//for (; i < 10; i++)
	//{
	//	for (; j < 10; j++)
	//	{
	//		printf("hehe\n");
	//	}

	//}//���ܴ�ӡ100����ԭ������Ϊj�ڵ�һ��ѭ����ʱ��j=10û�����,���Ա�����ֻ��ѭ��һ�Σ����,��Ҫ����ʡ��ǰ��ĳ�ʼ����


	//int x, y;
	//for (x=0,y = 0; x < 2 && y < 5; ++x, y++)
	//{
	//	printf("hehe\n");
	//}

	//int i = 1;
	//do {
	//	if (i == 5)
	//		break;
	//	printf("%d", i);//%d������Ǵ�ӡ��ǰ�Ĵ�С����˼��i���ڱ���ֵΪ1��������ȻΪһ��
	//	i++;

	//} while (i <= 10);//do while����whileҪ�ӣ�����Ϊ�Ǵ�1��ʼ������Ҫ��<=���ܵ�10


	//int i = 1;
	//do {
	//	if (i == 5)
	//		continue;
	//	printf("%d", i);//continue��Ҫ���������ڵ�ִ��
	//	i++;
 //       } 
	//while (i <= 10);//do while����whileҪ�ӣ�����Ϊ�Ǵ�1��ʼ������Ҫ��<=���ܵ�10

//int i = 0;
//int n = 0;
//int ret = 1;
//scanf("%d", &n);
//for (i = 1; i <= n; i++)
//{
//	ret = ret * i;
//}
//printf("ret=%d\n", ret);//n�׳˵��㷨

//int i = 0;
//int n = 0;
//int ret = 1;
//int sum = 0;
//
//for (n = 1; n<=3; n++)//���������for�Ǻ��б�Ҫ�ģ�ǰ������ǽ׳˵Ĵ������ӣ�������ֱ��������
//{
//	ret = 1;//�����Ե�֪��retֻ�ܷ���������ܷ��ڵڶ���for���棬��Ϊ���������ͻ��ǰ���ε�i=1��i=2��ret����������for����һ�����壬
//	//����ֻ�ܷ���for������ret,�����Ų���Ӱ��for�ڵ�ѭ��
//	for (i = 1; i <= n; i++)//�����iÿһ�ζ�������Ϊ1����1�ٵ�i��Ŀǰ���ֵ����Ҫһ��һ������ѭ��������֮��������iÿ�ζ�Ϊi�Ĵ�С�Ľ׳�
//	{
//		
//		
//		
//		ret = ret * i;
//		//��������retû������Ϊ1;��Ϊi�����������ˣ�������Ҫ��ret����i����ֵ
//	}
//	sum = sum + ret;//ret��i,sum����for�ܿأ����Բ���������for�������⣡
//}
////ret =1*(1)
////ret= 1*(1*2)
////ret=2*(1*2*3),ret���ú�1*��1*2*3��
//
//printf("sum=%d\n", sum);

//int i = 0;
//int n = 0;
//int ret = 1;
//int sum = 0;
//for (n = 1; n <= 3; n++)
//{
//	ret = ret * n;//��������ret,����࣬nΪ����ʱ����Ϊ���Ľ׳ˡ�
//	sum = sum + ret;
//}
//printf("sum=%d\n", sum);

//char arr1[] = "�� �� Զ ϲ �� �� �� ϣ �ţ��� �� ϣ �� �� �� �� һ �� һ ����������������! !";
//char arr2[] = "#############################################################################";
//int left = 0;
//int right = strlen(arr1) - 1;
////char���ַ������ͣ�����Ҫ��strlen�������ε��Դ���\0����-1����Ϊ�������0��ʼ��
////int right = sizeof(arr1) / sizeof(arr1[0]) - 2;//���þ�Ҫ-2,��Ϊ������ʵ��\0
//while (left <= right)
//{
//	arr2[left] = arr1[left];
//	arr2[right] = arr1[right];
//	printf("%s\n", arr2);//char��%s
//	Sleep(750);/*Ҫʹ��#include<windows.h>
//	��Ϣһ�루1000���룩*/
//	system("cls");//,���ã����Ǻ������Ļ��ִ��ϵͳ�����һ��������Ҫʹ��#include<stdlib.h>��
//	//Ϊ������ܳ��ֳ�ȫ���ַ�������Ч���������ٴ�ӡһ��
//	left++;
//	right--;
//
//}
//printf("�� �� Զ ϲ �� �� �� ϣ �ţ��� �� ϣ �� �� �� �� һ �� һ ����������������! !", arr1);
//
//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//int k = 10;//�Լ���Ҫ�ҵ�����
//int i = 0;
//int sz = sizeof(arr) / sizeof(arr[0]);
//for (i = 0; i < sz; i++)
//{
//	if (k == arr[i])
//	{
//		printf("�ҵ��ˣ��±��ǣ�%d\n", i);
//		break;
//	}
//}
//if (i == sz)//��Ϊ�����ܵ��ڣ���0��ʼ��
//printf("�Ҳ���\n");
//









	return 0; 
}

