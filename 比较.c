#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	if (x < y)
		printf("%d is larger", y);
	else if (x > y)
		printf("%d is larger", x);//ע����δ�ӡ�ĸ�ʽ
	else
		printf("These numbers are equal");




	return 0;
}
