#define _CRT_SECURE_NO_WARNINGS



////int Add(int x,int y)//������һ��Ҫע���Ƿ������Ĵ���ģ�
////{
////	int z = x+y;//��Ҫ��©���ֺţ�
////return z;
////}
//int main()
//{
//
//    ////int num1 = 100;
//    ////int num2 = 200;//
//    //int sum = 0;//Ҫ�������sum(�͵���˼��
//    ////	sum = Add(num1, num2);
//    //sum = Add(2, 3);
//    //sum = Add(56, 78);//ע�⣬sum�������һ����sum
//    //
//    //printf("sum=%d\n", sum);//����=���ݵ���ʽ
//
//    int pivotIndex(int* nums, int numsSize)//numsSize���ܹ�������������i�ǵ�ǰ����ʱ����
//    {
//        int total = 0;
//        for (int i = 0; i < numsSize; ++i)
//        {
//            total += nums[i];//�����м���������i��������total������ֻ�ǰ�total������
//        }
//        int sum = 0;
//        for (int i = 0; i < numsSize; ++i)//��һ��ѭ�������������
//        {
//            if (2 * sum + nums[i] == total)//֮���������и�nums[i]����Ϊ�����ǰ��û��ֵ����ô�Լ�Ҳ��
//                //��С��
//            {
//                return i;//����iѭ����return��ʾ������
//
//            }
//            sum += nums[i];//������ߵ�ֵ�����������������ֵ����Ͳ��ö����ұߵ��ˡ�
//            //ע�⣬�����ѭ���������ѭ��������ͬ��������Ȼ��������ֵһ��������Ϊ������ͬ����
//            //��ֵ�Ĵ�С��ͬ
//        }
//        return -1;//��Ŀ����
//    }//��Ϊ������һ���ⲿ����������ֻ���ù����ı�����������ɣ��������ﱨ������
//
//    
//    return 0;
//
//
//}
//
//int total = 0;
//for (int i = 0; i < numsSize; ++i)
//{
//    total += nums[i];
//}
//int sum = 0;
//for (int i = 0; i < numsSize; ++i)
//{
//    if (2 * sum + nums[i] == total)
//    {
//        return i;
//
//    }
//    return -1;//0��-1������
//}
//
//
#include<stdio.h> 
#include<string.h>
#include<math.h>
#include<stdlib.h>

//typedef struct 
//{
//	float Realpart;
//	float Imagepart;
//
//}Complex; 
//
////void Create(Complex &C, float x, float y)//���ڵı���������
//void Create(Complex C, float x, float y)//ֻ�ܺ��������ӡ�ˣ���Ҫ����ȥ��
////ֱ���ں����ﴴ��һ���µĽṹ�壬����
//{
//	C.Realpart = x;
//	C.Imagepart = y;
//	
//	
//}
//float Getreal(Complex C)//����,float����Ϊһ�㶼��С��
//{
//	return C.Realpart;//�ó�ʵ����ֵ
//}
//float GetImag(Complex C)
//{
//	return C.Imagepart;//�鲿��ֵ
//}
//Complex Add(Complex C1, Complex C2)//������֮��,������ô����һ���ṹ�庯��
//{
//	Complex sum;//�ȴ���һ������װ���ܺͣ�Ҳ�ǽṹ��
//	sum.Realpart = C1.Realpart + C2.Realpart;
//	sum.Imagepart = C1.Imagepart + C2.Imagepart;//
//	return sum;
//}
//Complex Sub(Complex C1, Complex C2)
//{
//	Complex difference;
//	difference.Realpart = C1.Realpart - C2.Realpart;
//	difference.Imagepart = C1.Imagepart - C2.Imagepart;
//	return difference;
//}
//int main()
//{
//	Complex a = { 0 };
//	Complex b = { 1,2 };
//	a.Realpart = 1;
//	a.Imagepart = 2;
///*	Create(a, 1, 2);*///�������޷�������.��ס��ʽ��û�취��
//  float c =Getreal(a);
//	float d =GetImag(a);
//	Complex e =Add(a, b);
//	Complex f =Sub(a, b);//��ֵ����Ϊ�˽�ֵ�����������Ա�ۿ�
//
//	return 0;
//}

//int main()
//{
//	/*int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		int t = a[i];
//		a[i] = a[9 - i];
//		a[9 - i] = t;
//
//	}
//	int b[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		b[i] = a[9 - i];
//	}
//	for (i = 0; i < 10; i++)
//	{
//		a[i] = b[i];
//	}*/
//
//
//
//	
//
//
//
//
//	return 0;
//}

//#define MAXSIZE 100//����ʽ��󳤶�
//	typedef struct
//	{
//		float coef;//ϵ��
//		int expn;//ָ��
//
//}Pl;//����ʽ
//	typedef struct
//	{
//		Pl* elem;//����ṹ���ַ��ָ�룩����������ͨ������SqList������Pl��
//		int len;//��ǰ��ĸ���
//	}SqList;
//	//�ṹ����ṹ��֮���������ϵ�������˳���--ͨ������һ���ṹ��Ӷ����ʶ���ṹ�塣

//#define MAXSIZE 10000//����ʽ��󳤶�
//typedef struct//ͼ����Ϣ����
//{
//	char no[20];
//	char name[50];
//	float price;
//
//}Book;
//typedef struct
//{
//	Book* elem;//����ṹ���ַ��ָ�룩����������ͨ������SqList������
//	int len;//ͼ����е�ǰͼ�����
//}SqList;
//����ṹ���ǻ�����������ϵ��ͳ�Ƴ��ȡ�
//�ṹ����ṹ��֮���������ϵ�������˳���--ͨ������һ���ṹ��Ӷ����ʶ���ṹ�塣
//SqList L;
//Status InitList(SqList& L)
//{
//	L.elem = new ElemType[MAXSIZE];
//	if (!L.elem)
//		exit(OVERFLOW);
//	L.len = 0;
//	return OK;
//}
//int main()
//{
//
//	
//	L.elem[1];//��Ȼ��Щ��ϢҲ����Ҫ�Լ�������е�
//
//
//
//
//	return 0;
//}

//int main()
//{
//	int* p;
//	p = (int*)malloc(5 * sizeof(int));//�����ڴ�
//	if (p == NULL)
//	{
//		exit(1);
//	}
//	p[0] = 1000;
//	printf("%d", p[0]);
//	free(p);//�ͷ��ڴ�
//	p = NULL;//�ǵ�����ָ�룬��ֹҰָ�롣
//	return 0;
//}

//typedef struct Node
//{
//	int data;
//	struct node* next;
//}Node,*LinkedList;//������������һ���
//
//LinkedList listinit()
//{
//	Node* L;//Node�ǽṹ��ָ��
//	L = (Node*)malloc(sizeof(Node));//��С��Ȼ�ǽṹ��Ĵ�С�������Ǳ�����
//	if (L == NULL)
//	{
//		printf("����ʧ��");
//	/*	exit(0);*/
//	}
//	L->next = NULL;//���next���õ�ǰ��ṹ���next,��ʵ������ָ��������L,next��������
//	//next��ʵ������һ���ڵ�λ�õ���˼,Ҫ��Ϊʲô����ʵ������Ϊǰ���ڽṹ����next��һ��
//	//�����˽ṹ�壬��������һ��
//	//L��ͷ�ڵ㣬��һ������ʽ��ʼ.
//	//��һ������ֵ����ʼ���������µĽ��
//
//}
//
//LinkedList LinkedListCreatH()//LinkedList���ӽṹ�壬����������
//{
//	Node* L;
//	L = (Node*)malloc(sizeof(Node));
//	L->next = NULL;
//	int x;
//	while (scanf("%d", &x) != EOF)
//	{
//		Node* p;
//		p = (Node*)malloc(sizeof(Node));
//		p->data = x;//������data
//		p->next = L->next;//��һ�����ǲ�����
//		
//		L->next = p;
// 
// ͷ�巨�����õ�һ��p����һ����㣬��֤p������Ȼ��p����L��ǰ�棬���ԲŻᵹ��
//		
//	return L;
//}
//

//
// β�巨
//LinkedList LinkedListCreatT()
//{
//	Node* L;
//	L = (Node*)malloc(sizeof(Node));
//	L->next = NULL;
//	Node* r;
//	r = L; //rʼ��ָ���ն˽��
//	int x;
//	while (scanf("%d", &x) != EOF)
//	{
//		Node* p;
//		p= (Node*)malloc(sizeof(Node));
//		p->data = x;//�������ݶ�����(����
//		r->next = p;
//  r = p; //rʼ��ָ���ն˽��
//		}

//	r->next = NULL;//��ֹrҰָ��
//	return L;
//}
//r=L��r=p�������ǵ�λ����ѭ��������һ����������Զ��ָ��β��λ�ã��������ܱ�֤��һ��������Զ�ڵ�һ��
// �������ָ�����ͷ�巨���������ǵ���
//void printList(LinkedList L)
//{
//	Node* p = L->next;
//	int i = 0;
//	while (p)
//	{
//		printf("�� % d��Ԫ����: % d\n", ++i, p->data);
//		p = p->next;
//	}
//}
//
//LinkedList LinkedListReplace(LinkedList L, int x, int k)
//{
//	Node* p = L->next;
//	/*while (p->data == x)
//	{
//		p->data = k;
//		
//	}*///p����Ĳſ���
//	while (p)
//	{
//		if (p->data == x)
//		{
//			p->data = k;
//
//		}
//		p = p->next;
//	}
//	return L;
//}
//
//LinkedList LinkedListInsert(LinkedList L, int i, int x)
////ֻ��ѡ���Ѿ������õ�L��Ϊ������ѣ�������˵�����Ĳ���,ǰ�������ݶ�����
//{
//	Node* pre;//�����Ϊ��ָ��L��������������,���Ϊ�˴��ݵ�L�����ڼ���λ�õĽ��
//	pre = L;
//	int tempi = 0;
//	for (tempi = 1; tempi < i; tempi++)
//	{
//		pre = pre->next;//ʹpre����iλ�õ�ǰ��
//	}
//	Node* p;//���ڴ洢���ݵĽ��
//	p = (Node*)malloc(sizeof(Node));
//	p->data = x;//�ִ����ˣ�����Ԫ�ض�û��
//	p->next = pre->next;//������ط����iλ��
//	pre->next = p;//��������
//
//	return L;//�ǵð����յ�ֵ���ظ�L����,��Ϊָ����L������pre��ֵ������L
//}
//
//LinkedList LinkedListDelete(LinkedList L, int x)
//{
//	Node* p, *pre;//*ÿһ���ַ���Ҫ��
//	p = (Node*)malloc(sizeof(Node));
//	pre = L->next;
//	while (p->data != x)
//	{
//		pre = p;
//		p = p->next;
//
//	}
//	pre->next = p->next;
//	free(p);
//	return L;
//}
//
//
//int main()
//{
//	LinkedList list;//��ʼ����һ������
//	printf("�����뵥��������ݣ���EOF��β\n");
//	list = LinkedListCreatT();
//	printList(list);
//
//	//����
//	int i;
//	int x;
//	printf("������������ݵ�λ�ã�");
//	scanf("%d", &i);
//	printf("������������ݵ�ֵ��");
//	scanf("%d", &x);
//	LinkedListInsert(list, i, x);
//	printList(list);
//
//	//�޸�
//	printf("�������޸ĵ����ݣ�");
//	scanf("%d", &i);
//	printf("�������޸ĺ��ֵ��");
//	scanf("%d", &x);
//	LinkedListReplace(list, i, x);
//	printList(list);
//
//	//ɾ�� 
//	printf("������Ҫɾ����Ԫ�ص�ֵ��");
//	scanf("%d", &x);
//	LinkedListDelete(list, x);
//	printList(list);
//
//
//	return 0;
//}

//#include<stdio.h>;
//#include<stdlib.h>;//��malloc����
//
//typedef struct node
//{
//	int num;
//	int score;
//	struct node* next;
//}linklist;
//
//linklist* creat_list(int a, int b)
//{
//	linklist* s, * head;
//	int i, x, y;
//	head = malloc(sizeof(linklist));
//	head->next = NULL;
//	for (i = 0; i < a + b; i++)
//	{
//		scanf("%d%d", &x, &y);
//		s = malloc(sizeof(linklist));
//		s->next = NULL;
//		s->num = x;
//		s->score = y;
//		s->next = head->next;
//		head->next = s;
//
//	}
//	return head;
//
//
//
//}
//
//void put_out(linklist* head)//������� 
//{
//	linklist* p;
//	p = head->next;
//	while (p != NULL)
//	{
//		printf("%d %d\n", p->num, p->score);
//		p = p->next;
//	}
//}
//
//void Sort(linklist* head)//ð������
//{
//	linklist* p, * s, * t;
//	int a_temp, b_temp;
//	p = head->next;//p�Ľ����Ϊ�������ӵڼ������ֿ�ʼ�ȶ�
//	while (p->next != NULL)//pָ��next��Ϊ�˱�֤t�Ĵ���
//	{
//		s= head->next;//��һ���Ƚϵ�����
//		t = s->next;//�����һ������
//
//		while (t != NULL)
//		{
//			if (s->num > t->num)//��������������С����ǰ��
//			{
//				a_temp = s->num;
//				b_temp = s->score;
//				s->num = t->num;
//				s->score = t->score;
//				t->num = a_temp;
//				t->score = b_temp;
//			}
//			s = s->next;
//			t = t->next;
//		}
//		p = p->next;//һ�ֽ�����ֱ�ӵ��ڶ������ֿ�ʼ����ȶ�
//
//	}
//
//}
//int main()
//{
//	linklist* p;//������
//	int a, b;
//	scanf("%d%d", &a, &b);
//	p = creat_list(a, b);//�������� 
//	Sort(p);//���� 
//	put_out(p);//��� 
//	return 0;
//}

#include<stdio.h>
#include <malloc.h>
#include <string.h>
//.���ݽṹ - ����Ļ�������
typedef struct node
{
	int data;
	struct node* next;

}linklist;
//Ҳ��������node*,node
//          ��д��ָ�� ����ָ������Ϊnode,��ôд�ͷ���ܶ�

linklist* creat_list(int* count)
{
	linklist* head, * p;
		head = malloc(sizeof(linklist));
		head->next = NULL;
		
		int x, n, i;
		scanf("%d", &n);
		(*count) = n;
	/*	while (scanf("%d", &x) != EOF)*/
		for(i=0;i<n;i++)
		{
			scanf("%d", &x);
			p = malloc(sizeof(linklist));
			p->next = NULL;
			p->data = x;
			p->next = head->next;
			head->next = p;
		}

		return head;//ͷ����ͷ�巨һ��Ҫ���ظ�����

	//ͷ/β�巨һ�㶼������һ���Բ���������ݣ�һ�ε�һ���ò���
		//������ȫ�Ϳ��Դ��浹����룬ֱ����ô����ok�������ͷ�巨

}

void show(linklist* head)
{
	linklist* p = head->next;//������Ϊheadһ��ʼһ���ǿյģ�ͷ��㣩������Ҫ��ָ����һ��λ�÷�ֹ�ұ�
	if (p == NULL)//����ָ�����ݣ�����û�н�㣬������������û�У���Ȼ��whileʱ����ѭ����
	{
		printf("Link list is empty\n");
	}
	else
	{
		while (p != NULL)
		{
			printf("%d ", p->data);
			p = p->next;//��һ�������ˣ����Ƕ���ѭ���ġ�
		}
		printf("\n");
	}
	
}
void Insert(linklist* head,int a,int x,int* count)//λ�ú�������
{
	linklist* pre, *p;
	pre = head;//ֱ����Ⱦ͵���ָ��
	int t;
	/*�ҵ���t��λ��֮ǰ�Ľ�㼴��a-1�����*/
	 /* for��int i=0;i<t-1;i++) */
	for (t = 1; t < a; t++)
	{
		pre = pre->next;
	}
	p = malloc(sizeof(linklist));
	//p->next = NULL;//û��Ҫ����Ϊ���������������ˣ�����ͷ��㲻��������
	p->data = x;

	p->next = pre->next;//��ͷ�巨ȥ�������ˣ�����������������Ȼ���ڸ�ֵ(�����ǲ��룩
	pre->next = p;
	/*�������1*/
	(*count)++;
	printf("insert OK\n");

	

}

void Delete(linklist* head, int n,int* count)
{
	linklist* pre, * p = head;//preʹ��ʱû����ռ�,���ʹ�ö�Ҫ���䣡
	//֮ǰһֱ��������һ�����������ּ�*p=head->next,����ͷָ����һ��ʼ�Ͳ����ּ�ָ����һ��λ�ã�
	pre = malloc(sizeof(linklist));

	int i;
	
for(i=0;i<n;i++)
		//������ǲ���ĳ��Ԫ�أ�����ĿҪ�����������ĸ�λ�õ�ֵ��
	{
		pre = p;
		p = p->next;
	}
	pre->next = p->next;
	free(p);

/*�������ȥ1*/
	(*count)--;
	printf("delete OK\n");
	
	

}

void get(linklist* head, int x)//�õ�����ֱ��ͨ������Ȼ���ӡ����
{
	linklist* pre = head;
	int i;
	for (i = 0; i < x; i++)
	{
		pre = pre->next;
	}
	printf("%d\n", pre->data);

}
int main()
{int    n, a, e, count;
	
	char    order[7];
	linklist* p = creat_list(&count);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", order);

		if (!strcmp(order, "get"))
		{
			scanf("%d", &a);
			/*�жϲ���λ���Ƿ�Ϸ�,*/
			if (a > count || a < 1)
				printf("get fail\n");
			else
				get(p, a);
		}
		else
			if (!strcmp(order, "insert"))
			{
				scanf("%d%d", &a, &e);
				/*�жϲ���λ���Ƿ�Ϸ�����a=Count+1����ʾ����������β��*/
				if (a > count + 1 || a < 1)
					printf("insert fail\n");
				else
					Insert(p, a, e, &count);
			}
			else
				if (!strcmp(order, "delete"))
				{
					scanf("%d", &a);
					/*�ж�ɾ��λ���Ƿ�Ϸ�*/
					if (a > count || a < 1)
						printf("delete fail\n");
					else
						Delete(p, a, &count);
				}
				else
					if (!strcmp(order, "show"))
					{
						show(p);
					}
	}


//for (i = 0; i < n; i++)
//{
//	scanf("%d", &num);
//	a[i] = num;
//}
//for (; i >= 0; i--)
//{
//	printf("%d", a[i]);
//}
//
//scanf("%d", &m);
//for (i = 0; i < m; i++)
//{
//	char w;
//	scanf("%s", &w);
//ͷ�巨�ɴ���

	/*if (w == "show")
	{
		show(p);
		break;
}
	else if (w == "delete")
	{
		delete(p);
		break;
	}
	else if (w == "insert")
	{
		insert(p);
		break;
	}
	else if (w == "get")
	{
		get(p);
		break;
	}*///�ַ�������ôд��




	return 0;

}

