//
//
//#include<stdio.h> 
//#include<string.h>
//#include<math.h>
//#include<stdlib.h>
//
////��㶨��
//typedef struct node {
//    int data;
//    struct node* next;
//}node;
////���ж��壬����ָ��Ͷ�βָ��
//typedef struct queue {
//    node* front;    //ͷָ��
//    node* rear;     //βָ��
//    //����Ҫ�������ӵ����þͲ���struct,ֱ�Ӷ��������
//}queue;
//
//node* init_node()
//{
//    node* n = malloc(sizeof(node));//���
//    if (n == NULL)
//    {
//        exit(0);
//    }
//    return n;
//    
//}
//queue* init_queue()
//{
//    queue* q = malloc(sizeof(queue));
//    if (q == NULL)
//    {
//        exit(0);
//    }
//    q->front = NULL;
//    q->rear = NULL;
//    return q;//��ס������Ҫ��ʼ��û�����⣡����
//    
//    
//}
//int* empty(queue* q)
//{
//    return q->front == NULL;//ֱ����return�ж��Ƿǣ�Ȼ�󷵻�һ��ֵ
//}
//
//void push(queue* q, int data)
//{
//    node* n = init_node();
//    n->data = data;
//    if (empty(n))
//    {
//        q->front = n;
//        q->rear = n;//1
//    }
//    else
//    {
//        q->rear->next = n;//����ǽ����ݽ���ԭ�����ݵĺ��棬����Ǳ�ʾ���ݵ�һ��
//        q->rear = n;//�����ָ��ָ��n���λ�ã�������1��һ�������б�ʾָ��
//        //�Լ�ѧ������Ǳ�ʾ���ݻ���ָ�룬��Ҫ��죡
//    }
//
//    
//}
//void pop(queue* q)
//{
//    node* n = q->front;
//    if (empty(q))
//    {
//        return;
//    }
//    
//        if (q->front == q->rear)
//        {
//            q->front = NULL;
//            q->rear = NULL;
//            free(n);
//        }
//        else
//        {
//            q->front = q->front->next;
//            free(n);
//        }
//    
//}
//
//void print_queue(queue* q)
//{
//    node* n = init_node();
//    n = q->front;
//
//    while (n != NULL)
//    {
//        printf("%d", n->data);
//        n = n->next;
//    }
//    printf("\n");
//}
//int main() 
//{
//    queue* q = init_queue();
//    ///////////////��Ӳ���/////////////////
//    printf("���\n");
//    for (int i = 1; i <= 5; i++) 
//    {
//        push(q, i);
//        print_queue(q);
//    }
//    ///////////////���Ӳ���/////////////////
//    printf("����\n");
//    for (int i = 1; i <= 5; i++)
//    {
//        pop(q);
//        print_queue(q);
//    }
//    return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//
//
//typedef struct node
//{
//    int data;
//    struct node* next;
//}node;
//
//typedef struct queue
//{
//    node* front;
//    node* rear;
//}queue;
//
//int empty(queue* q)
//{
//    return (q->front == NULL);
//
//
//}
//node* init_node()
//{
//    node* n = (node*)malloc(sizeof(node));
//    if (n == NULL)
//    {
//        exit(0);
//    }
//
//    return n;
//}
//queue* init_queue()
//{
//    queue* q = (queue*)malloc(sizeof(queue));
//    if (q == NULL)
//    {
//        exit(0);
//        //        return q;,exit�Ѿ����˳�����˼��
//    }
//    q->front = NULL;
//    q->rear = NULL;
//
//    return q;
//}
//
//void push(queue* q, int data)
//{
//    node* n = init_node();
//    n->data = data;
//    n->next = NULL;
//    //�������Ҫ������һ��������˵
//    //ÿһ�δ����������������һ���µĿռ�
//    //�㲻��ôд��û��λ���ˣ��ռ�ͻ������
//
//    if (empty(q))
//    {
//        q->front = n;
//        q->rear = n;
//
//    }
//    else//��Ҫ©�ˣ���Ȼִ�в�һ����
//    {
//        q->rear->next = n;
//        q->rear = n;
//    }
//
//
//
//
//}
//
//void pop(queue* q)
//{
//    node* n = q->front;
//    if (empty(q))
//    {
//        printf("no\n");
//        exit(0);
//        //return ;
//        //��exit��Χ��ֱ��return ��������exit�ù�return��
//        //exit��������ȷ�ʱ�return ��,�������ų�����ô��Ĳ��������ڸ����ҵ���.
//    }
//    if (q->front == q->rear)
//    {
//        printf("%d\n", n->data);
//        q->front = NULL;
//        q->rear = NULL;
//
//        //free(n);��������û��ϵ
//
//    }
//    else//���������������
//    {
//        printf("%d\n", n->data);
//        q->front = q->front->next;//ָ����һ�����ͷ���ε�.	
//
//        free(n);
//    }
//}
////void display(queue* q)
////{
////    node* n = init_node();
////    n = q->front;
////    if(empty(q))
////	{
////	        exit(0) ;    //��ʱ����Ϊ�գ�ֱ�ӷ��غ�������
////	    }//�ձ�����ˣ�����
////    while (n != NULL)
////    {
////        printf("%d\n", n->data);
////        n = n->next;
////    }
////    printf("\n");
////}//��������ԣ��������壬�������Ͳ������
//
//int* count(queue* q)
//{
//    int count = 0;//�����ȸ�ֵ0��
//    node* n = init_node();
//    n = q->front;
//    while (n != NULL)
//    {
//        count++;
//        n = n->next;
//    }
//    return count;
//}
//
//
//int main()
//{
//    queue* p = init_queue();
//    int n, a, data, i, c;
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &a);
//        if (a == 1)
//        {
//            scanf("%d", &data);//�ݣ�ȡ��ַû��,����������Ҫ��֪����֪������!����������һֱ����,����ҲҪ�����ȫ������Щ������ܱ��������ᱨ���
//            //��ס��һ�����ݺܿ�����ȡ��ַû���������������
//            push(p, data);
//
//        }
//        else if (a == 2)
//        {
//            pop(p);
//            // display(p);//��Ŀ����ĺ�ɧ����ʵ�������ñ��������ǽ����ӡɾ�������ݣ����ţ��,sb��Ŀ,��Ȼ���������,���������ˣ��Ժ�ˢ�������Ҫ���濴��
//        }
//        else if (a == 3)//else if����ߴ���Ч��
//
//        {
//            c = count(p);
//            printf("%d\n", c);//�������Ǵ�������㣬c����д��count��������˲ţ��Ժ�ע���������Ĵ���
//        }
//    }
//    return 0;
//}

////ѭ������
//#include<stdio.h>
//#include<stdlib.h>
//#define maxsize 50
//typedef struct cir_queue{
//    int data[maxsize];
//    int rear;
//    int front;
//}cir_queue;
//
//cir_queue* init()
//{
//  cir_queue* q=malloc(sizeof(cir_queue));
//	if(q==NULL)
//	{
//		printf("����ռ�ʧ��");
//		exit(0);
//	}
//	else
//	{
//		q->front=0;
//		q->rear=0;
//	}
//	return q;
//}
//
//void push(cir_queue* q,int data)
//{
//	if((q->rear+1)%maxsize==q->front)//������������
//	{
//		printf("�ռ�����");
//		exit(0);
//		
//	}
//	
//	q->rear=(q->rear+1)%maxsize;
//	//���ｫq->rear������һ��λ��
//	q->data[q->rear]=data;
//	//�����q->rear�Ѿ�����һ��λ���ˣ�����ֱ������Ϳ�����
//	
//}
//void pop(cir_queue* q)
//{
//	if(q->front==q->rear)//ѭ�����У���������ǿ϶�����ָ��0��������Ϊ�ղſ�����
//����Ҫ˵���һ�����⣬������ʵѭ�����л���ʲô�����Ƿ�Ϊ���ݸ�ָ��ģ�����һ��ʼ��ָ��ָ��ͬһ��λ�ã���front��rearָ��һ������������ռ��о���һ��
//��Զ���ӵĿռ䣬�������ݣ�����ָ�������ߣ�front��rear��ָ����˷�������ָ�룬���˷��򣬾Ͳ����������ٴ���ȣ�������Ƭ��Զ��ӵĿռ���Ȼ���ڣ�ֻ��
//ָ�벻ָ�����˶��ѣ���Ҫ�����ݺ�ָ�뵱��ͬһ���£�ֻ��ָ��û�б仯��ʱ����ܸ�����һ��ָ��仯�ˣ����Ǳ仯֮�����Ƭ���ݣ�
//
//
//	{
//		printf("����Ϊ��");
//		exit(0);
//	}
//	
////	q->front=0; err
//q->data[q->front]=0;
//
//	//��ɾ��������ֱ�ӽӵ�ѭ���ġ�0���ϣ�ֱ�ӽ�����
//	q->front=(q->front+1)%maxsize; 
//	//ָ����ת����һ��������Ϊ��ͷ
//}
//
//void print(cir_queue* q)
//{
//	int i=q->front;
//	while(i!=q->rear)
//	{
//		i=(i+1)%maxsize;
//		printf("%d",q->data[i]);//��Ϊһ��ʼָ��0�����Կ��־�������һ����ӡ����
//	}
//	printf("\n");
//	
//}
//int main(){
//    cir_queue *q = init();
//    ////////////��Ӳ���///////////////
//    printf("��Ӳ���\n");
//    for(int i=1;i<=6;i++){
//        push(q,i);
//    }
//    print(q);
//    ////////////���Ӳ���///////////////
//    printf("���Ӳ���\n");
//    for(int i=1;i<=3;i++){
//        pop(q);
//        print(q);
//    }
//    return 0;
//}
//

#include<stdio.h>
#include<stdlib.h>
#define maxsize 50
typedef struct queue
{
	int data[maxsize];
	int front;
	int rear;
}queue;

queue* init()
{
	queue* q=malloc(sizeof(queue));
	if(q==NULL)
	{
		exit(0);
	}
	q->front=0;
	q->rear=0;
	
	return q;
	
	
}
void push(queue* q,int data)
{
//	if(q->rear==(q->rear+1)%maxsize) err������һ������ͷһ���������Ǹ�ǰ���һ���������߼����ϸ磬д���벻�����룿
     if((q->rear+1)%maxsize==q->front)
	{
		
		exit(0);
	}
	
	q->rear=(q->rear+1)%maxsize;
	q->data[q->rear]=data;
}

void pop(queue* q)
{
	if(q->front==q->rear)
	{
		printf("no\n");
		exit(0);
	}
//	printf("%d\n",q->front);err,��ӡ�������ݲ���ָ�룡
     
	q->data[q->front]=0;
	q->front=(q->front+1)%maxsize;
	 printf("%d\n",q->data[q->front]);
	 //����ź�������Ϊһ��ʼq->front��0,�����ڶ����������ݣ�����˵�ȵ�λ�ٴ�ӡ��ûë����һ�����־��ǿ�ָ�룬����һ�������߼�����
}

int* count(queue* q)
{
    int count = 0;//�����ȸ�ֵ0��
    int i=q->front;
  
//    while (i!=(i+1)%maxsize)//���������ѭ������򵥵Ĵ�ͷ��β��
while(i!=q->rear)
    {
        count++; 
		i=(i+1)%maxsize;
       
    }
    return count;
}
int main()
{
    queue* p = init();
    int n, a, data, i, c;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &data);//�ݣ�ȡ��ַû��,����������Ҫ��֪����֪������!����������һֱ����,����ҲҪ�����ȫ������Щ������ܱ��������ᱨ���
            //��ס��һ�����ݺܿ�����ȡ��ַû���������������
            push(p, data);

        }
        else if (a == 2)
        {
            pop(p);
            // display(p);//��Ŀ����ĺ�ɧ����ʵ�������ñ��������ǽ����ӡɾ�������ݣ����ţ��,sb��Ŀ,��Ȼ���������,���������ˣ��Ժ�ˢ�������Ҫ���濴��
        }
        else if (a == 3)//else if����ߴ���Ч��

        {
            c = count(p);
            printf("%d\n", c);//�������Ǵ�������㣬c����д��count��������˲ţ��Ժ�ע���������Ĵ���
        }
    }
    return 0;
}

















































