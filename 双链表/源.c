#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h> 
#include<string.h>
#include<math.h>
#include<stdlib.h>

//typedef struct line
//{
//	int data;
//	struct line* next;
//	struct line* pre;
//}/**line,Line;*///��ôд�������ֺ�ָ�벻��һ������η���ռ仹Ҫд���������ǻ���ȥ��
//line;
//
//line* initline(line* head)
//{
//	int number = 0;
//	int pos = 1, input_data;
//	printf("����������:", number);
//	scanf("%d", &number);
//	if (number < 1)
//	{
//		/*printf("�Ƿ�����");*/
//		return NULL;//(ֱ�ӽ�������)
//	}
//		printf("�����%d������:", pos++);//��ӡ����&
//		//line head//�����ͷ�����ֱ�Ӵ������õ�
//		head =malloc(sizeof(line));
//		head->next = NULL;
//		head->pre = NULL;
//		scanf("%d", &input_data);
//		head->data = input_data;
//
//		line* list = head;//��Ϊhead��body���ӵĴ����
//		while (pos <= number)
//		{
//		line*	body = malloc(sizeof(line));//ѭ����ÿһ�ο��ٿռ䶼����ȫ�µ�һ�����
//			body->next = NULL;
//			body->pre = NULL;
//			scanf("%d", &input_data);
//			body->data = input_data;
//
//			list->next = body;
//			body->pre = list;
//			list = list->next;
//		}
//
//		return head;
//	
//}
//
////
//// 
////�ܽ�һ�¾���ָ���൱���ߣ���next��pre����������������������ǰ���µĽ�㣬Ȼ��������ݣ����ռ���ǰ�������
////��������
//
////���ԣ���head=temp������������ָ�벻�Ǹ�ֵ�������������ǰ����ݸ�ֵ�ϡ���ͼ�Ϳ���֪����ʵ����ֻҪ
////�����˾Ϳ��Է��ʣ���������Ҫ�ٴθ�ֵ
////temp->next = head;
////head->pre = temp;
////���Ƶľ������������ݣ�ǰ�����Ӿ���ͼ����˵�ġ���Ϊ��ʵ��ͼ�ϵ�pre��next����ʵ������һ��pre/next���������
////��һ�������ϣ�
////head=temp�������ָ����÷����㲻�ǲ���������λ�ô����￪ʼ����ֱ�Ӵ����￪ʼ��Ծ�����£�
////�㲻���ǲ����û�����壬�������תָ�����˼�����磬���ڿ�ͷ����temp�������Ҫ��head�������temp��ʼ��
////�ǲ�����㷨��.
//
//
//
//
//
////����
//line* insertline(line* head, int data_, int add)
//{
//	line* temp = malloc(sizeof(line));
//	temp->data = data_;
//	temp->pre = NULL;
//	temp->next = NULL;
//	int i = 0;
//	if (add == 1)
//	{
//		temp->next = head;
//		head->pre = temp;
//		head = temp;//©��Ҫ�ѿ�ͷָ��temp��ʼ
//	}
//	//if��else֮�䲻�������
//	else
//	{
//		line* body = head;
//		for (i = 1; i < add - 1; i++)//p=p->nextһ��ʼִ��ѭ��ʱ���Ѿ������ڶ����ˣ�����ѭ������
//		{
//			body = body->next;
//		}
//
//		if (body->next == NULL)
//		{
//			body->next = temp;
//			temp->pre = body;
//		}
//		else
//		{
//			body->next->pre = temp;
//			temp->next = body->next;
//			body->next = temp;
//			temp->pre = body;
//		}
//	}
//	return head;
//}
//
//line* deleteline(line* head, int data_)
//{
//	line* list = head;
//	while (list)
//	{
//		if (list->data == data_)
//		{
//			list->pre->next = list->next;
//			list->next->pre = list->pre;
//			free(list);//�ͷ��ڴ�
//			printf("--ɾ���ɹ�--\n");
//			return head;//�鵽ɾ�����Ͻ����ú�����return���Ͳ������ѭ������ִ��
//		}
//	
//		list = list->next;//û�鵽�ͱ��� 
//	}
//	printf("Error:û���ҵ���Ԫ�أ�û�в���ɾ��\n");
//
//	return head;
//}
//void printLine(line* head)
//{
//	line* list = head;
//	int pos = 1;
//	while (list) {
//		printf("��%d��������:%d\n", pos++, list->data);
//		list = list->next;
//	}
//}
//int main()
//{
//	line* head = NULL;
//	printf("����˫�������\n");
//	head = initline(head);
//	printLine(head);
//	//////////create line////////////
//	printf("�������\n");
//	head = insertline(head, 40, 2);     //Ϊ�˼�ֱ��д������
//	printLine(head);
//	//////////insert Line////////////
//	printf("ɾ������\n");
//	head = deleteline(head, 2);       //Ϊ�˼�ֱ��д������
//	printLine(head);
//	//////////delete Line////////////  
//
//
//
//
//
//	return 0;
//}
typedef struct line
{
	int data1;
	int data2;
	struct line* next;
}line;

line* initline()
{

	line* head = malloc(sizeof(line));
	head->next = NULL;
	
  
	line* r = head;
	int i = 0, data_1, data_2;
	for(i=0;i<10;i++)//β��
	{
		line* p = malloc(sizeof(line));
		scanf("%d%d", &data_1, &data_2);
	   p->data1 = data_1;
       p->data2 = data_2;
	   r->next = p;
	   r = p;//������r��ָ����һֱ�ƽ�

	 

	 }
	r->next = NULL;
	
	return head;//���ظ�ͷָ��Ͷ���
	
	
}
int main()
{
	int i = 0, sum1 = 0, sum2 = 0;
	
	line* p = initline();//����������Ҫ�ϴ������

	//for (i = 0; i < 10; i++)
	//���ڴ�������ʱ�ö��ٴδ���һ�����ȽϺ������Ǻ�����Ͳ�֪�������ж೤��������p�Ƿ���������
	while(p)
	{
		sum1 += p->data1;
		sum2 += p->data2;
		p = p->next;
	}

	printf("%d+%di", sum1, sum2);

	return 0;
}

