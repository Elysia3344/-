#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
int main()
{
	char x;//�ַ����ķ�ʽ��char,������switch����scanf
	printf("Input Grade: ");
	x = getchar();//�������������˼
	switch (x)
	{
	case'A':
		printf("A is 90~100");
		break;
	case'B':
		printf("B is 80~89");
		break;//��Ҫ©��break,��Ȼ�ͻ����������һ��case��break��ͣǧ��ע�⣡
	case'C':
		printf("C is 70~79");
		break;
	case'D':
		printf("D is 60~69");
		break;
	case'E':
		printf("E is 0~59");
		break;

	default:
		printf("errno");
		break;



	}






	return 0;
}
