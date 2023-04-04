#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct list
{
	int data;
	struct list* next;
}list;

list* initlist()
{
	list* head = malloc(sizeof(list));
	if (head == NULL)
	{
		printf("����ʧ��");
		exit(0);
	}
	else
	{
		head->next = NULL;
	}
	return head;
}

int* creatlist(list* head)//���Ǵ����Ĳ�������
{
	int data;
	printf("������Ҫ���������");
	scanf("%d", &data);

	list* node = initlist();
	node->data = data;//�������ݵĽ��
	if (head != NULL)
	{
		list* p = head;//��λ�õĽ��
		while (p->next != head)//��������head������ָ�����Լ����������һ������ûë��
			//��Ϊ��ѭ��������������������Լ�ʱ�˳�ѭ���͸պ������һ��������
		{
			p = p->next;
		}
		p->next = node;
		node->next = head;
		return 1;
	


	}
	else 
	{
		printf("ͷ�������Ԫ��\n");
		return 0;
	}
}

//��������
list* insertlist(list* head, int pos, int data)
{
	list* node = initlist();//����
	list* p = head;//������������ʹ��
	list* r;//��λ
	r = p;
	node->data = data;
	if (head != NULL)
	{
		for (int i = 1; i < pos; i++)//�����λ�ö���������֮���λ�ã���˸����ݲ��߸�λ�ã�����
			//ѭ������
		{
			r = r->next;

		}
		node->next = r->next;
		r->next = node;
		
	}
	return p;
}

int* deletelist(list* head)
{
	if (head == NULL)
	{
		printf("����Ϊ��");
		return 0;
	}

	list* temp, * ptr;
	temp = head;
	ptr = head->next;//�����������Ϊɾ��������Ҫ���Ա���������ֱ����������

	int del;
	printf("��������Ҫɾ��������");//ϸ��
	scanf("%d", &del);

	while (ptr!= head)
		//������һ�������ǿ���ǰ��
	{
		if (ptr->data == del)
		{
			if (ptr->next == head)//���Ҫɾ����������β���
//��Ϊɾ��β�ڵ��β�ڵ�ǰһ�����ͳ����µ�β�ڵ㣬
//����µ�β�ڵ���Ҫָ�����ͷ�������ǿգ����ص���Լ�¼Ϊ����ǰ��ǰһ�ڵ�.next=������.next��
//�����Ĳ�������ʡȥͷβ�������У�
			{
				temp->next = head;//ֱ������һ��ָ��head�����ͷ�ԭ����
				free(ptr);
				return 1;


			}
			temp->next = ptr->next;
			free(ptr);
			return 1;
		}
	temp = temp->next;
	ptr = ptr->next;
	}

	printf("û���ҵ�Ҫɾ����Ԫ��");//ǰ������ҵ��˾�����������ˣ����һֱû���Ǿ���û���ҵ�
	//©�˺�����������
	return 0;
}

int* display(list* head)
{
	if (head != NULL)
	{
		list* p = head;
		while (p->next != head)
		{
			printf("%d", p->next->data);
			p = p->next;
		}
		return 1;
	}
	//��ȫ�ԣ�����
	else
	{
		printf("ͷ���Ϊ�գ�");
		return 0;
	}
	
}

int main()
{
	
	

		list* head = initlist();//��ʼ�����
		head->next = head;//ѭ������Ŀ�ʼ
		////////ͨ������Ԫ����������/////////
		for (int i = 0; i < 5; i++)
		{  
			creatlist(head);//��������
		}
		display(head);
		////////////����Ԫ��////////////////
		head = insertlist(head, 1, 10);//ѡ��λ�ò�������
		display(head);
		////////////ɾ��Ԫ��////////////////
		deletelist(head);
		display(head);
	



	return 0;
}
