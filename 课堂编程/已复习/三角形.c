#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h> 
//int main()
//{
//	double a, b, c;
//	if (a == b && a == c && b == c)
//	{
//		printf(" equilateral triangle");
//	}
//	else if (a == b || b == c || a == c)
//	{
//		printf("isoceles triangle");
//	}
//	else if (a* a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b)
//	{
//		printf(" right-angled triangle");
//	}
//	else if ((a + b > c && a - b < c) || (a + c > b && a - c < b) || (b + c > a && b - c < a))
//	{
//		printf("arbitrary triangle");
//	}
//	else
//	{
//		printf("It isn't triangle.");
//	}
//
//
//	return 0;
//}
//ֱ�Ӱ���������г�����������û�б�Ҫ�õ�����ȷ��һ����Ϊ���ֵ����
//ע�⣬=�Ǹ�ֵ��==�������
//���ϱ�����چ��£����������в����,���������Ż���
#include<stdio.h> 
#include<math.h>
int main()
{
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);

	

	//else if ((a + b > c && a - b < c) || (a + c > b && a - c < b) || (b + c > a && b - c < a))
			//���چ���,ֱ��д����֮�ͼ���


	//break��������if�����


	if ((a + b > c) && (b + c > a) && (a + c > b))//˳��,��������������η�����ǰ������ִ�У������ͱ����ظ�
	//�ѹ�ͬ�������ǰ�棬��������׸��
	// �����εĹ��Ծͷ���һ��if�У���Ҫ�ֿ�����Ȼ���ܻ��ظ���ӡ�������κ�ֱ���������ظ���
		//��������������֮�ʹ��ڵ����ߣ���&&��Ҫ��||��
	{


		if (a == b && b == c && a == c)//������ȱ�����ôд����Ҫд����ʽ
			printf(" equilateral triangle");
		else if (a == b || b == c || a == c)
			printf("isoceles triangle");

		else if (fabs(a * a + b * b - c * c) < 0.0001 || fabs(c * c + b * b - a * a) < 0.0001 || fabs(a * a + c * c - b * b) < 0.0001)

			printf(" right-angled triangle");//ֱ��������ֻ��һ�������ģ�������||��
		else

			printf("arbitrary triangle");





	}

	if (a + b <= c || b + c <= a || a + c <= b)

		printf("It isn't triangle.");//���������Σ��ų�if


















	return 0;
}
//ֱ�Ӱ���������г�����������û�б�Ҫ�õ�����ȷ��һ����Ϊ���ֵ����
//ע�⣬=�Ǹ�ֵ��==�������
//�������ſ�©��
//����Ϊ�Լ����ش��⣬�ܶ�֪ʶϸ���Ժ�Ӧ��ע��