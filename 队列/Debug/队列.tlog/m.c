
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}node;

typedef struct queue
{
    node* front;
    node* rear;
}queue;

int empty(queue* q)
{
    return (q->front == NULL);
    
    
}
node* init_node()
{
    node* n = (node*)malloc(sizeof(node));
    if (n == NULL)
    {
        exit(0);
    }

    return n;
}
queue* init_queue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    if (q == NULL)
    {
        exit(0);
//        return q;,exit�Ѿ����˳�����˼��
    }
    q->front = NULL;
    q->rear = NULL;

    return q;
}

void push(queue* q, int data)
{
    node* n = init_node();
    n->data = data;
    n->next=NULL;
    //�������Ҫ������һ��������˵
    //ÿһ�δ����������������һ���µĿռ�
    //�㲻��ôд��û��λ���ˣ��ռ�ͻ������

    if (empty(q))
    {
        q->front = n;
        q->rear = n;

    }
else//��Ҫ©�ˣ���Ȼִ�в�һ����
{
    q->rear->next = n;
    q->rear = n;
}




}

void pop(queue* q)
{
    node* n = q->front;
    if(empty(q))
    {
		printf("no\n");
		exit(0) ;
		//return ;
		//��exit��Χ��ֱ��return ��������exit�ù�return��
		//exit��������ȷ�ʱ�return ��,�������ų�����ô��Ĳ��������ڸ����ҵ���.
	}
    if (q->front==q->rear)
    { 
	printf("%d\n",n->data);
        q->front = NULL;
        q->rear = NULL;
       
        //free(n);��������û��ϵ
      
    }
    else//���������������
	{
	printf("%d\n",n->data);
    q->front = q->front->next;//ָ����һ�����ͷ���ε�.	
	
    free(n);
	}
}
//void display(queue* q)
//{
//    node* n = init_node();
//    n = q->front;
//    if(empty(q))
//	{
//	        exit(0) ;    //��ʱ����Ϊ�գ�ֱ�ӷ��غ�������
//	    }//�ձ�����ˣ�����
//    while (n != NULL)
//    {
//        printf("%d\n", n->data);
//        n = n->next;
//    }
//    printf("\n");
//}//��������ԣ��������壬�������Ͳ������

int* count(queue* q)
{
	int count=0;//�����ȸ�ֵ0��
    node* n = init_node();
    n = q->front;
    while (n != NULL)
    {
        count++;
        n = n->next;
    }
   return count;
}


int main()
{
    queue* p=init_queue();
    int n, a, data, i,c;
    scanf("%d", &n);
    for ( i = 0; i < n;i++)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &data);//�ݣ�ȡ��ַû��,����������Ҫ��֪����֪������!����������һֱ����,����ҲҪ�����ȫ������Щ������ܱ��������ᱨ���
            //��ס��һ�����ݺܿ�����ȡ��ַû���������������
            push(p,data);

        }
       else if (a == 2)
        {
          pop(p);
         // display(p);//��Ŀ����ĺ�ɧ����ʵ�������ñ��������ǽ����ӡɾ�������ݣ����ţ��,sb��Ŀ,��Ȼ���������,���������ˣ��Ժ�ˢ�������Ҫ���濴��
        }
        else if (a == 3)//else if����ߴ���Ч��
        
        {
         c=count(p);
         printf("%d\n",c);//�������Ǵ�������㣬c����д��count��������˲ţ��Ժ�ע���������Ĵ���
        }
    }
   return 0;
}
