#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>

int main()
{
	char arr1[] = "�� �� Զ ϲ �� �� �� ϣ �ţ��� �� ϣ �� �� �� �� һ �� һ ����������������! !";
	char arr2[] = "#############################################################################";
	int left = 0;
	int right = strlen(arr1) - 1;
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);//char��%s
		Sleep(750);/*Ҫʹ��#include<windows.h>
		��Ϣһ�루1000���룩*/
		system("cls");//,���ã����Ǽ������Ļ��ִ��ϵͳ�����һ��������Ҫʹ��#include<stdlib.h>��
		//Ϊ������ܳ��ֳ�ȫ���ַ�������Ч���������ٴ�ӡһ��
		left++;
		right--;

	}
	printf("�� �� Զ ϲ �� �� �� ϣ �ţ��� �� ϣ �� �� �� �� һ �� һ ����������������! !", arr1);
	return 0;
}

