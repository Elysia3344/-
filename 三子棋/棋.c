#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h> 
//#include<string.h>  ��h�ļ������˾Ͳ���Ҫ���Լ�����һ����

#include"game.h"//Ҫ�Ѷ�����ļ����ù�������ʡ�ظ�����
void menu()
{
	printf("*****************************\n");
	printf("****1.��ʼ��Ϸ/0.������Ϸ****\n");
	printf("*****************************\n");

	
}
//��ͬ�ĺ���Ҫ��������������������Ҫ���д��
void game()
{
	char ret = 0;//���͵��߼�������
			//�������ret��Ϊ�˽��մ�����Ӯ�ķ��ű�־,char�����ַ�
	char board[Row][Col] = { 'a' };//��д������ư���
	//�������ַ���������������char
	Initboard(board, Row, Col);
	//�������
	//���ú�����ʱ��ҲҪ�Ѹô���Ķ���д��ȥ��
	//����ʱ����ֻ��д���־�����,�����ڵ��ö��Ƕ���ʱ����д����
	Displayboard(board, Row, Col);
	while (1)//����Ϊ��
	{
	//���
		playermove(board, Row, Col);
		Displayboard(board, Row, Col);
		//�ж���Ӯ
		ret = shengfu(board, Row, Col);//�����ж���Ӯ�Ϳ��Խ������ѭ����ӡ����������������

		if (ret != 'C')//�����ʤ������,����ֵ��Cֱ������whileѭ��,����ֱ�Ӳ���computer
		{
			break;
		}//
		//����
		computermove(board, Row, Col);
		Displayboard(board, Row, Col);
		ret = shengfu(board, Row, Col);//ret���ڴ�ţ������Ͳ���д��ô���Ĵ���
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')

	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("�;�\n");
	}
	//shengfu();�ҷ�һ������û��һ������
	//��Щ����ȫ�����ˣ�Ӧ����ret����ж���Ӯ�ĺ������ж�
		//                               ������ʡ���ּ�ࣩ
}
	
	
	



void test()
{
	srand((unsigned int)time(NULL));//nullҪ��д,�����ǰѳ�srand������������
	int input = 0;

	do
	{
		//�˵�Ҳ���õ��õģ����ֱ�ӿ������Ϻ������ǰ�

		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);//��˳����
		switch (input)
	    {
		   case 1:
			game();
			break;
		   case 0:
			printf("�˳���Ϸ");
			break;
		    default:
			printf("�������");
			break;
	    }

	} while (input);
	//������input����Ϊinput��Ĭ���Ƿ�0����������ֻҪ�Ƿ�0����ѭ����ȥ��
//whileѭ����û,����һ�ξͽ�����
//switch��������ѭ�����㲻��breakҲֻ��һֱ˳��ִ����ȥ��
//���������һ��ﲻ������Ҫ��Ч����һ����˵��Ҫ��break!
//break������ֻ��ͣס����Ϊ0�Ǽ����ԲŻ��Զ�����ѭ��
}



	

	int main()
	{
		test();




		return 0;
	}
