#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>

#include"game.h"//Ҫ�Ѷ�����ļ����ù�������ʡ�ظ�����
void menu()
{
	printf("*****************************\n");
	printf("****1.��ʼ��Ϸ/0.������Ϸ****\n");
	printf("*****************************\n");
	printf("��ѡ��:>");
	
}
//��ͬ�ĺ���Ҫ��������������������Ҫ���д��
void game()
{
	char board[row][col] = { 'a' };//��д������ư���
	Initboard( board, row, col);//���ú�����ʱ��ҲҪ�Ѹô���Ķ���д��ȥ��
	//����ʱ����ֻ��д���־�����,�����ڵ��ö��Ƕ���ʱ����д����
	Displayboard(board, row, col);
	while (1) 
	{
		playermove(board, row, col);
		Displayboard(board, row, col);
		computermove(board, row, col);
		Displayboard(board, row, col);
		int ret = 0;//���͵��߼�������
			//�������ret��Ϊ�˽��մ�����Ӯ�ķ��ű�־
		ret =shengfu(board, row, col);
			if (ret != c)
			{
				break;
			}
	}

	//shengfu();�ҷ�һ������û��һ������
	if (ret == '*')//��Щ����ȫ�����ˣ�Ӧ����ret����ж���Ӯ�ĺ������ж�
		//                               ������ʡ���ּ�ࣩ
	{
		printf("���ʤ");
	}
	else if (ret == '#')
	{
		printf("����ʤ");
	}
	else
	{
		printf("�;�");
	}
	infull();
	if (infull == 1)
	{
		{
			return 0;
		}


	}
}



void test()
{
	srand((unsigned int)time(NULL));//nullҪ��д,�����ǰѳ�srand������������
	int input = 0;
	
	do{//�˵�Ҳ���õ��õģ����ֱ�ӿ������Ϻ������ǰ�

		menu();
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


	}while (input);
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
