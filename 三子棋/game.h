#define _CRT_SECURE_NO_WARNINGS
//���ڸ���bug��
#define Row 3
#define Col 3//�����������©����������̵Ĵ�С��������
//����������ʵ�ã�ֱ������������define����


#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<time.h>
//����
void Initboard(char board[Row][Col], int row, int col);//���Լ���board��char��дint��ʲô��
void Displayboard(char board[Row][Col], int row, int col);
void playermove(char board[Row][Col], int row, int col);
void computermove(char board[Row][Col], int row, int col);
char shengfu(char board[Row][Col], int row, int col);
int isfull(char board[Row][Col], int row, int col);
//ǰ���Row��Col��Ϊ�������͵���ʱ����ʹ�õģ�������������������Ǻ�����ʹ�õı����߲����غ϶��壡
// ����Ҫreturnһ��ֵ��,����ֱ�ӿ���дvoid
//Ӯ-"*"
//��-"#"
//ƽ��-"Q"
//����-"C"