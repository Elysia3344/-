#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<math.h>

	
int main()
{//�ؼ����벽��ʱһ��Ҫ�����д��Ҫ��Ȼ�����˺��ѷ��֣��ر���ϸ��
	int i, j;
	int num[100];
	char name[10][10];//�Ժ��ö�ά���飬��Ϊ���ü򵥣��ܶຯ����Ϊ�ռ乻������,
	//һά���������ú������
	//֮���Կ��԰Ѷ�ά�������һά�����������Ϊ���ʾ���һά����

	int age[100];


	int n = 0;
scanf("%d", &n);
int tmp = 0;
char set[5][5];//��Ϊ������
	
	
		for (i = 0; i < n; i++)

		{
			scanf("%d", &num[i]);
			scanf("%s", &name[i]);
			//����ֻдһ���±꣬Ĭ���Ǵӵ�һ�п�ʼ�ǣ������Զ���
			scanf("%d", &age[i]);

		}
		
		for (i = 0; i < n - 1; i++) //�Ƚ�n-1��
		{
			for (j = 0; j < n - 1 - i; j++)//ÿ�ֱȽ�n-1-i��,
			{
				if (strcmp(name[j], name[j + 1]) > 0)

				{
					/*a[60] = a[j];
					a[j] = a[j + 1];
					a[j + 1] = a[60];*///�ṹ�岻����ôд
					
						strcpy(set[3], name[j]);
					strcpy(name[j], name[j + 1]);
					strcpy(name[j+1], set[3]);//��û�����ȷһ�·�����
					//��Ĵ�����д���򶼲���һ���߼���û�д�������j����j+1�����������
					// ������i����j���������,
					//strcpyֻ�����鸳ֵ����
					//���ܷ�����һ��ѭ�����Ϊ�����������Ѿ���ǰ���ˣ����������ȫ��������,
					//һ��Ԫ�ذ�ң�������Ҫ����һ����

					tmp = num[j];//���Ǻ���������ôд
					num[j] = num[j + 1];
					num[j + 1] = tmp;//�����ñ�����������е�Ԫ��

				    tmp= age[j];
					age[j] = age[j + 1];
					age[j + 1] = tmp;
					
				}
			}
		}
	for (i = 0; i < n; i++)
	{//a������
		/*printf("", ,,);*///������ô͵��������д�ͻ�Բ���
		printf("%3d", num[i]);
		printf("%6s", name[i]);
		printf("%3d", age[i]);//��Ŀ����ռ����λ��д���ٸ����־�����,�����Լ��ո�
		printf("\n");
		//ֻ��char������puts��gets,ţ��,���ɶ�ά�����ֿ�������
	
	}     
	//��ά����ı�����ʵ����һά�����������
	//	һ���ά����ֻдһ���±��������Ǵӵ�һ�п�ʼ��
	//	��ʵ�е������޷Ǿ��������˾͵���һ�У��͵��ڵ���һ��һά���飬��ʵ����һά����ĵ���.

	printf("\n");//ϵͳ��ʽ
	for (i = 0; i < n - 1; i++) //�Ƚ�n-1��
	{
		for (j = 0; j < n - 1 - i; j++)//ÿ�ֱȽ�n-1-i��,
		{
			if (age[j]> age[j + 1])

			{
				

				strcpy(set[3], name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], set[3]);

				tmp = num[j];//���Ǻ���������ôд
				num[j] = num[j + 1];
				num[j + 1] = tmp;//�����ñ�����������е�Ԫ��

				tmp = age[j];
				age[j] = age[j + 1];
				age[j + 1] = tmp;

			}
		}
	}
	for (i = 0; i < n; i++)
	{//a������
		/*printf("  %2d   %2s %2d", num[i], name[i], age[i]);*///�Բ���
	
		printf("%3d", num[i]);
		printf("%6s", name[i]);
		printf("%3d", age[i]);
		printf("\n");

	}

	return 0;
}


