#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h>//ʹ��rand��srand
#include<time.h>//����ʱ���

void menu()//�Լ����Զ�����ַ�ʽ������������˵�
{
	printf("************************************\n");
	printf("****     1.play     0.exit      ****\n");
	printf("************************************\n");
		
}

void game()
{
	int ret = 0;
	int guess = 0;//���ղµ�����
	ret = rand() % 100 + 1;//����1-100�������
	//ע�⣬��Ҫ��ret�Ž�while���Ȼÿ��ѭ�������µ����ֵ��
	//rand����Rand_MAX-32767(���ֵ����д,%100��ֻʣ10λ���ڣ���Ȼ�ᱻ100����,�������99
	
	
    
	/*ret = rand();//�������һ����
	printf("%d\n", ret);*///����rand��ԭ����
	while (1)//����game��ִ�У���Ҫ����������,���1��ʾ���Ϊ�����˼
	{
		printf("�²�����:>");
		scanf("%d", &guess);//��û����guess��¸�der
		//�����ַ���Ҫ��\n����������ĵ�һ������Ч��
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}

		else
		{
			printf("�¶���\n");
			break;//��Ҫ©������ѭ��
		}
	}
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//����ʱ����������������������ʼ��
	//����main������Ͳ����������´򿪲�ִ�У�
	//�������־ͻ�����ԣ�unsignedǿ��ת������(��Ϊsrand������ҪInt��)��NULLΪ�շ�,
	
	do//��do while������Ϸ����Ҫִ��һ��
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);//��Ҫ\n!�����ַ���Ҫ��\n����������ĵ�һ������Ч��
		switch (input)
		{
		case 1://��:����;!
			game();//ֱ������game����
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������/n");
			break;//ÿһ����Ҫдbreak,��ʾִֻ����һ�������



		}

	} while (input);//do while��while��Ҫ��;
	





	return 0;
}
