#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
{
//	//char arr1[] = "abc";
//	//printf("%s\n", arr1);
	//printf("%d\n", strlen(arr1));
	//int a, b, sum;
	//a = 101;
		//b = 201;
		//sum = a + b;
		//printf("sum is %d\n", sum);

	//int max(int x, int y);
	//int a,b,c;
	//scanf("%d,%d",&a,&b);
	//c = max(a,b);
	//printf("max = %d\n", c);

	//int age = 20;
		//scanf("%d\n", age);

	/*printf("%s\n", "\"");
	printf("%s\n", "\132");
	printf("%s\n", "\x76");
	printf("%d\n", strlen("c:\test\327\test.c"));*/

	//int input = 0;//���������input�����룬��Ϊ����Ҫ�õ�input
	//printf("�������\n");//���Ĳ���%d������
	//printf("��Ҫ�ú�ѧϰ��(1/0)>:");//>:��ʾ��ʾ��������ѡ��
	//scanf("%d", &input);//һ�Ǵ���&������1��0��ѡ��Ҳ��Ҫ���봢�棬��scanf��
	//scanf���û��У�
	//if(input == 1)//һ����Ӣ�ĵ��ַ��������ĵĶ�����if��else���ǲ��ã���
	//	if�����=һ��Ҫ==����Ȼ�Ͳ���
	//printf("��offer\n");//ע��һ��Ҫ���б�©��
	//else
	//printf("������\n");

	//int input = 0;//���������input�����룬��Ϊ����Ҫ�õ�input
	//printf("��ѩ��������櫽���\n");//���Ĳ���%d������
	//printf("������ע����wife�ǣ�(1/0)>:");//>:��ʾ��ʾ��������ѡ��
	//scanf("%d", &input);//һ�Ǵ���&������1��0��ѡ��Ҳ��Ҫ���봢�棬��scanf��
	////scanf���û��У�
	//if (input == 1)//һ����Ӣ�ĵ��ַ��������ĵĶ�����if��else���ǲ��ã���
	//	//�����=һ��Ҫ==����Ȼ�Ͳ���
	//	printf("����ϣ��\n");//ע��һ��Ҫ���б�©��
	//else
	//	printf("���ǰ���ϣ�ţ�\n");

	//int line = 0;
	//	printf("����\n");
	//while (line < 20000)//����ָ���д��С������ģ�������д����
	//{printf("��һ�д��룺%d\n",line);
	//line++;


	//}
	//if (line >= 20000)
	//	printf("��offer\n");

	//int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 //    int i = 0;
	//
	//	while (i < 10)//������ַ���0��ʼ��˵���ܶ�Σ������ַ���Ҫ�á�����������Ȼ��һƬ�հ�,ѭ����while����if!
	//{
	//	printf("%d", arr[i]);
	//	i++;
	//}//�����������������ʾ�����������﷨����ע���ַ����úÿ���������û�д���ʲô�ط�����Ӣ�ģ���Сд���ַ���û��©���߼Ӷ�

	//int a = 1;
	//int b = a << 2;
	//printf("%d\n", a);
	//printf("%d\n", b);//����1��4���ֽڣ�

	////&�ǡ��롱��ֻҪ�����ж�Ӧ�Ķ���������0����ô���ն�Ӧ�Ķ�����ҲΪ0������Ϊ1��Ϊ1.
	//|�ǡ��򡱣�ֻҪ��1����1���������෴��
	//	^�ǡ���򡱣���ͬΪ0������Ϊ1������Ϊ��1��
	/*int a = 3;
	int b = 5;
	int c = a ^ b;
	printf("%d\n", c);

	= Ϊ��ֵ�� == �ж����
		a += 20;
		a = a + 20;(������ͬ)

	��1��0��0��1*/

	//int arr[10] = { 0 }; /*10������Ԫ�ص�����*/
	//	int sz = 0;
	//printf("%d\n", sizeof(arr));
	//sz = sizeof(arr) /  sizeof(arr[0]);//ǰ���Ѿ�������˾Ͳ����ٴζ���int��,������Ϊһ������Ҫ����������������
	//printf("%d\n", sizeof (sz));

	//int num1 = 10;
	//int num2 = 20;
	//if (num1 > num2)
	//printf("%d\n", num1);
	//else
	//printf("%d\n", num2);





//
//	return 0;
//}

//int Max(int x, int y)//�����ⲿ������int main()�������Ҫ��;
//{
//	if(x > y)//Ҫ���뺯����Ҫ������
//return x;
//else
//return y;
//
//}//���Ŷ���һ�����ڴ�������
//
//
//int main()
//{
//	//int num1 = 10;
//	//int num2 = 20;
//	//int Max = 0;
//	//Max = (num1, num2);
//	//printf("Max=%d\n", Max);//�������ӣ�����
//
//	//int num1 = 10;
//	//int num2 = 20;
//	//int max = 0;//@
//	//max = Max(num1, num2);
//	//printf("max=%d\n", max);
//	////����max�ǲ�ͬ�ģ�@�������ַ���������max,�൱��һ����λ����Max�Ǻ�����
//	///*�������Ľ�����Ҫǰ������һ�����壬����дһ�����룡*/
//
//	//int a = 0;
//	//int	arr[] = { 1,2,3,4,5,6 };//arrֻ���Լ���һ�����壬���Ǻ�����
//	//printf("%d\n", sizeof(a));
//	//printf("%d\n", sizeof(int));
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr) / sizeof(arr[0]));//�����arr������arr
//
//	//int a = 0;//4���ֽڣ�32��bitλ
//	//int b = ~a;//~��������λ����ȫ��������
//	//00000000000000000000000000000000
//	//11111111111111111111111111111111
//	int a = 10;
//	/*int b = a++;*/
//	int b = ++a;//��������b����a�Ǳؼӵģ���ǰ��bҲ�żӡ�
//	
//	printf("a=%d,b=%d\n",a, b);



//int a = 0;
//int b = 5;
//int c = a && b;
////int c = a || b;
//printf("c=%d\n", c);
//���������⣬������




return 0;

	}
