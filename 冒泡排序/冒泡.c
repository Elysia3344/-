#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h> 
//#include<string.h>
//void bubble_sort(int arr[], int sz)//[]��Ҫ©���������������������Ҫ���壡
//{
//	int tmp = 0;
//	int i = 0;
//	//ȷ����������
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//flag���������
//		//��Ϊ����Ҫ������һ�Σ��ٵڶ����ڸ�ֵ��
//		//����Ž���һ��for���������ظ���ֵû�ж������
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j+ 1] = tmp;
//				flag = 0;
//
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}//����flag ��Ϊ���Ż��㷨��
//		//��Ϊ10����������Ҫ9�ˣ�����������������Ҫ��9��
//		//����flag��Ϊ�˼��ٲ���Ҫ���ظ��ж�
//		
//	}
//
//}
//
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//���飬����ʵ����ֻ����Ԫ�صĵ�ַ��&arr[0]
//	bubble_sort(arr,sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//
//
//
//	return 0;
//}

int main()
{
	int arr[10] = { 1,2,3,4,5 };
	printf("%p\n", arr);	//ֱ����������������&
	printf("%p\n", &arr[0]);
	printf("%d\n", *arr);//���������Ǵ�ӡ�������±꣬����%d
	//���ۣ���������������Ԫ�صĵ�ַ
	//�����������sizeof(����������ʱ��ʾ�������顣&����������ʱȡ������ĵ�ַ��
	//��������ʱ��ʾ�������顣


	return 0;
}