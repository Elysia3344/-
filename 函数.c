#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<math.h>
//int get_max(int x, int y)//����;
//
//
//{
//	if (x > y)
//		return x;
// //������ǰѶ�Ӧ��ֵ���ظ����õĺ���,��x��ֵ����ȥ��main������,��return
//	else
//		return y;
//
//}

//
//int main()
//{
	//	//char arr1[20] = "bit";
	//	//char arr2[20] = "##########";
	//	////               bit\0########
	//	//strcpy(arr2, arr1);//Ŀ�ĵأ�������
	//	////����Ӧ���ǰ�arr1������ճ����arr2����
	//	//printf("%s\n", arr2);
	//	////strcpy �ַ�������
	//	////strlen �ַ��������й�
	//
	//	int a = 10;
	//	int b = 20;
	//	int max = get_max(a, b);
	//	
	//	printf("%d\n", max);
	//	max = get_max(100, 300);//ǰ���Ѿ���int,����ֱ��д������
	//	printf("%d\n", max);//���printf����Ҫд����Ϊ�����ǰ�˳��ִ�У����Կ����ظ�ʹ��max
	//	max = get_max(100, get_max(3, 7));//������ôǶ��
	//	printf("%d\n", max);
	//
	//
	//	return 0;
	//}
	// 
	//void Swap(int x, int y)//���÷��ظ�ֵ��ֱ��дvoid������
	//{
	//	int tmp = 0;
	//	/*tmp = a;
	//	a = b;
	//	b = tmp;*///�����ò�����x,y!
	//	tmp = x;
	//	x = y;
	//	y = tmp;
	//}
	//
	//
	//int main()
	//{
	//	int a = 10;
	//	int b = 20;
	//	printf("a = %d\n b = %d\n", a, b);
	//	Swap(a, b);
	//	printf("a = %d\n b = %d\n", a, b);
	//
	//
	//
	//
	//	return 0;
	//}//err
	// 
	//����Ĵ����ǲ��еģ���Ϊ��������ȡַ���޷���������main��a,b��,������Ҫ��ָ��
	// ��ֵ���βε��޸Ĳ���Ӱ��ʵ�Σ�����ַ����.
	//void Swap(int* pa, int* pb)//���÷��ظ�ֵ��ֱ��дvoid������
	//{
	//	int tmp = 0;
	//	tmp = *pa;
	//	*pa = *pb;
	//	*pb = tmp;//�ı߷���߲�Ҫ���˳��
	//}
	//
	//
	//int main()
	//{
	//	int a = 10;
	//	int b = 20;
	//	printf("a = %d\n b = %d\n", a, b);
	//	Swap(&a,&b);
	//	printf("a = %d\n b = %d\n", a, b);
	//
	//
	//
	//
	//	return 0;
	//}

	//int main()
	//{
	//	int a = 10;
	//	int* pa = &a;//paָ�����
	//	*pa = 30;//�����ò���
	//	//���̾���,ȡ��a�ĵ�ַ,ͨ��ָ��������ﵽ��a��ֵ��Ч��,��Ȼ��������������ʽ
	//	printf("%d\n", a);
	//
	//
	//
	//	return 0;
	//}

	//int is_prime(int n)
	//{
	//	int j = 0;
	//	//          j<sqrt(n)Ҳ��,�㷨����,���Ϳ��ʼ�
	//	for (j = 2; j < n; j++)//2->n-1�͹���,1û��Ҫ,n�������������������
	//	{
	//		if (n % j == 0)
	//			return 0;//0�Ǽ�,���ظ����ü�ʲô��û��
	//	}
	//	return 1;//ע�ⲻҪ��������for���棬��Ϊ������ѭ���������֤����������������
	//	//ֻѭ��һ��.
	//	//1��ʾ�棬���ѡ��桱�����Ϣ���ظ�����
	//}



	//
	//
	////��ӡ100-200֮�������
	//int main()
	//{
	//	int i = 0;
	//	for (i = 100; i <= 200; i++)
	//	{
	//		if (is_prime(i) == 1)
	//			printf("%d\n", i);
	//	}








	//	return 0;
	//}

//int is_leap_year(int y)
//{
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//		return 1;//������ֵ�����ú���
//	else
//		return 0;//��ֵ
//}
//
//
//
//
//int main()
//{
//	int year = 0;
//	for (year=1000; year <= 2000; year++)
//	{
//		if (1 == is_leap_year(year))
//			printf("%d\n", year);
//	}
//
//
//
//
//	return 0;
//}
////                         ������arr��ָ��
//int binary_search(int arr[], int k,int sz)//������Ҳ���Ե�
//{//                 ��������������������,����Ӧ�÷�������������ϴ�
//	/*int sz = sizeof(arr) / sizeof(arr[0]);*///����Ҫ�þͷ���ǰ�棡
//	int left = 0;
//	int right = sz - 1;
//	
//
//	while (left<=right)//��Ҫд��������֤������
//	{   
//		int mid = (left + right)/ 2;//ע��Ҫ����while���Ϊ�м�ֵһֱ���ڱ�.
//		
//		//if (mid > k)// err
//		if(arr[mid]>k)
//		{
//			right = mid - 1;
//		}
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;//����mid�����ú���
//	}
//	return -1;
//}
//
//
//
//
//
//
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	//              ����ȥ��������arr��Ԫ�ص�ַ����Ϊ������ܿռ��ܴ�ϵͳĬ��
//	//Ϊ�˽��������⣬���Ǿ��Լ����������ﶨ�壬Ȼ���ϴ���
//	//new
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k,sz);//��Ӣ���ַ�ע��
//	if (ret == -1)
//	printf("�Ҳ���\n");
//   else//if��else���ǰ�����ϵ����Ҫ�����е�һ������ĳһ����������
//	printf("�ҵ���,�±���%d\n", ret);
//	
//	
//
//
//	 
//
//	return 0;
//}
//
//void Add(int* num)//�����num���һ�����ֶ�����
//{
//	(*num)++;
//}
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("num is %d\n", num);
//	Add(&num);
//	printf("num is %d\n", num);
//	Add(&num);
//	printf("num is %d\n", num);
//
//
//
//
//
//
//	return 0;
//}

//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//	printf("%d\n", printf("%d\n", printf("%d\n", 43)));
//	//	printf("%d\n", printf("%d\n",2));
//	// printf("%d\n", 1);
//	//��������Ƕ�ף���������ȴ�ӡ�������ӡ�Ķ�Ϊ�ַ�����
//	//����\n���ַ�Ҳ�������ȥ��,������Ȼ�����ˣ�����\nҲ����һ���ַ���
////����Ϊ43 3 2
//	
//
//
//	return 0;
//}
//#include"add.h"//�ֿ����ź�����ʱ��Ҫ�����
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);//��������
//	printf("%d\n", sum);
//
//
//
//
//
//	return 0;
//}
////��add,��sub,��mul,��div

//int main()
//{
//	printf("hehe\n");
//	main();
//	return 0;//�ݹ飬ͻȻ��ͣ������Ϊջ���
//}
//void print (int n)
//{
//	if (n > 9)//��λ�Ͳ���Ҫ����
//	{
//		print(n / 10);//�ı�������ٴε��øú���
//	}//     /10��Ϊ��ÿ����ȥ��λ��Ϊ����ȡ�����̵�
//	printf("%d  ", n % 10);//��ÿһ���������������ȡ���printf���
//	//%10ʱ����ÿ�ζ�ȡ����λ����  ��998 ���� 9%10 = 9 99%10=9 998%10= 8
//	// 
//	//�ݹ��˳��������ִ���ظ������Լ��ĺ�����������������ʱ�Ű�˳��ִ�к���Ĵ���
//	//���ң��Ǵ����һ�ν���ʱ��ʼִ�У��ٵ���ִ�к���Ĵ��루�������Ե���)
//
//
//}
//int main()
////������ֺ���
//{
//	unsigned int num = 0;
//	//16λϵͳ��һ��int�ܴ洢�����ݵķ�ΧΪ-32768~32767��
//	//��unsigned int�ܴ洢�����ݷ�Χ����0~65535
//
//	scanf("%d", &num);
//	print(num);
//
//
//
//	return 0;
//}
//int my_strlen(char* str)
//{
//	int count = 0;//���������������
//	while (*str !='\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//
//	�������
//	my_strlen("bit")
//	1+my_strlen("it")
//	�Դ�����
//	if (*str != '\0')//ָ�����ע��*��
//	{
//		return 1 + my_strlen(str + 1);
//		���ﲻ��ֱ��дmy_strlen(str),��Ȼ��ѭ��
//		��ôд��str�ļ����ƽ������ܽ�ֵ�Ĵ�Сһֱ�õ�����,����Ժܸ�
//		�⼸�����߼��ǣ���������������ʱ��һֱ��returnһ��ֵ�����ú�����
//		һֱ��return 0(��,������'\0'��,��ֹͣ�������Ǽٵ�ʱ��ǰ��return��ֵ�Ѿ��ڵ��ú������ˡ�
//		
//	}
//	else
//		return 0;
//
//}
//int main()
//{
//	char arr[] = "bit";
//	/*int i = strlen(arr);
//	printf("%d", i);*/
//	����ֱ�����ַ������ȵķ���
//	int len = my_strlen(arr);
//	arr�����飬���鴫�Σ�����ȥ�Ĳ����������飬���ǵ�һ��Ԫ�صĵ�ַ
//	printf("%d", len);
//
//
//
//
//	return 0;
//}
//int Fac1(int n)//ѭ���ķ���
////      ���n��ʵ�δ������ģ����������ֱ��ʹ��
////û��ͨ���βθı�ʵ�ε���������ָ��
//{
//	int i = 0;
//	int j = 1;
//	for (i = 1; i <= n; i++)//�õ���n
//	{
//		j *= i;
//	}
//	return j;
//	
//}
//�ݹ�
//int Fac2(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Fac2(n - 1);
//}
//
//int main()
//{
//	//int i = 0;
//	//int ret = 0;
//	//scanf("%d", &ret);//��Ҫ©��&��
//	//ret = Fac1(i);
//	//printf("%d", ret);  err
//	//��Ҫ���ʹ�ñ������ֹ�Ҫ��ȷ��
//	//n���������������֣�ret������������ֵ��
//
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);//��Ҫ©��&��
//	ret = Fac1(n);
//	printf("%d", ret);
//
//
//	return 0;
//}
//



//1 1 2 3 5 8 13 21 ....
//int Fib1(int n)//�ݹ�
//{
//	
//	if (n<= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//	//��Ȼ����㣬��Ч��̫�ͣ�����Խ�Ӵ�ִ��Խ��
//	//�����е�ʱ���Ƴ��õݹ飬Ҫ�����ʺϵ����ѡ�ò�ͬ���㷨
//}
//int Fib2(int n)//ѭ��
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;//(��Ϊ�߼��϶���C��ʵ������������ĵ����Ǹ���,���ſ��Ե���)
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fib2(n);
//	printf("%d", ret);
//
//
//
//
//	return 0;
//}
// 
// ջ�����
//void test(int n)
//{
//	if (n < 10000)
//	{
//		test(n + 1);
//	}
//}
//int main()
//{
//
//	test(1);
//
//
//
//	return 0;
//}
//

