#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initboard(char board[Row][Col], int row, int col)//�ַ����Ͳ�Ҫ©,�����ַ���ʽҪд�ã�
{
	int i = 0;
      int j = 0;
   for (i = 0; i < row; i++)
   
	for (j = 0; j < col; j++)
	{
		//printf(" ", board[i][j]);err
		board[i][j] = ' ';//�ȸ�board��ֵ�հ�
	}
   

}
void Displayboard(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{

		for (j = 0; j < col; j++) //% c�Ǵ�ӡ�ַ�����˼
		{//�������������޷��������ʱ�����濴��������һ�飬��Ҫ�����������ͺ�������
		//�ܶ�ʱ������û��ģ������������̣�ʵ�ڲ��о͵��ԣ�


			printf(" %c ", board[i][j]);//��Ϊ�����ַ���Ҫ�����Ź����п��ܷ�������
			//��ӡboard�Ŀհ�����
			if (j < col )//����ǽ��������ݺ����
			{
				printf("|");//�հ��Դ�ӡ|
			}
		}

		printf("\n");//�ǵû���,ÿһ�д�ӡ�����ͻ�����һ��




	//��ӡ�ָ���
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)//�����colֻ�Ǽ򵥵���Ҫѭ��һ�¶���
			{
				printf("---");//�Լ���������ַ����ĸ��ط����л������ϣ���ͷ����ĸ�ѭ����
				//��ӡ��Щ�ַ���ʱ��Ҳ����Ҫ�����Ź���λ�õģ�����û�У�
				//֮���Բ�һ�������������Ϊ�����밴˳��������Щ���ݣ�(���������ǲ�ͬ�ģ��ֿ�������)
				//�������ܳ��ֳ�������Ҫ����̬
				if (i < col - 1)
					printf("|");//---�Դ�ӡ|


			}
			printf("\n");//ͬ��
		}

	}
	



	
}
void playermove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	/*for (i = 0; i < col ; i++)
	{
		for (j = 0; j < row ; j++)
		{
			printf("*"��board[i][j]);

		}

	}*/
	while (1)
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d%d", &x, &y);
		//�ж�x,y����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)//���Ի��ı��
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';//��ֵ���ж�����ǲ�ͬ����˼

				break;
			}
			else
			{
				printf("���걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������!\n");
		}//if��Ƕ��ʹ��

	}
}
void computermove(char board[Row][Col], int row, int col)
{ 
	int x = 0;
  int y = 0;
  printf("������;>\n");
  
 while (1)
 { 
	x =rand() % row;//���ֵȡ������������һ����ȡ��С��row,col��ֵ
	y=rand() % col;
	if (board[x][y] == ' ')
	{
		board[x][y] = '#';
		break;
	}
	
	
 }
}
int isfull(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;//�������֣�����int
}
char shengfu(char board[Row][Col], int row, int col)
{
	/*if (board[i][j] == '*')
	{
		printf("���ʤ");
	}
	else if (board[i][j] == '#')
	{
		printf("����ʤ");
	}
	else
	{
		printf("�;�");
	}*/
	
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}//������
		for(i = 0; i < col; i++)
		{
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
				return board[1][i];
		}//������
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
			return board[1][1];
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
			return board[1][1];
		if (1 == isfull(board, Row, Col))//�����ж�ֱ��ת����ת��isfull��ȥ�������
		{
			return 'Q';
		}
	
	return 'C';//���϶����Ǿͷ���C
}
	


