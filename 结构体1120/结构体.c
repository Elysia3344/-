#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<math.h>
//struct stu
//{
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//};

//int main()
//{
//	struct stu s;
//
//
//
//
//	return 0;
//}

//�������� type define
//typedef struct Stu
//{
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}Stu;
//int main()
//{
//	Stu s;
//
//
//
//
//	return 0;
//}
///�ַ�����Ҫ����""�����ֲ���
typedef struct Stu
{
	char name[20];
	int age[5];
	char tele[20];
	char sex[10];
}Stu;

int main()
{
	Stu s = { "����",20,"13465798101","��" };
	struct Stu s2 = { "����",30,"14568564561","����" };//��ʹ�����Ժ�ԭ���ƻ��ǿ��Ե�.




	return 0;
}
