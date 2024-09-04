#include<iostream>

using namespace std;

typedef struct BiTNode
{
    char data; // �����򣬴洢�ַ�
    int   num; // �����򣬴洢����
    struct BiTNode* lchild, * rchild; // ���Һ���ָ��
}BiTNode, * BiTree; // ����������ָ�����Ͷ���

typedef struct StackNode
{
    BiTNode* root; // ָ�����������ָ��
    char   op; // �����
    struct StackNode* next; // ��һ��ջ�ڵ�ָ��
} StackNode, * LinkStack; // ջ����ָ�����Ͷ���

typedef struct StackNode_Post
{
    int num; // ����������
    char  data; // �����������
    struct StackNode_Post* next; // ��һ��ջ�ڵ�ָ��
} Stack_Post, * LinkStack_Post; // �������ʱ���õ���ջ�Ĵ���ṹ




void InitStack(LinkStack& S)  //����һ����ջ

{

    S = NULL;

}

void InitStack_Post(LinkStack_Post& S)  //����һ����ջ(���ں���ǵݹ����)  

{

    S = NULL;

}

/*  */

void Push_root(LinkStack& S, BiTNode* e)      //���ڵ���ջ

{

    StackNode* p;

    p = new StackNode;

    p->root = e;

    p->next = S;

    S = p;

}
//�����ڵ�ѹ��ջ�У����Է������Ƕ��������������б���������������

void Push_op(LinkStack& S, char e)      //��������ջ

{

    StackNode* p;

    p = new StackNode;

    p->op = e;

    p->next = S;

    S = p;

}

void Push_Post_num(LinkStack_Post& S, int e)      //������ջ(���ں���ǵݹ����)  

{

    StackNode_Post* p;

    p = new StackNode_Post;

    p->num = e;

    p->next = S;

    S = p;

}

void Push_Post_data(LinkStack_Post& S, char e)      //�������ջ (���ں���ǵݹ����)

{

    StackNode_Post* p;

    p = new StackNode_Post;

    p->data = e;

    p->next = S;

    S = p;

}



BiTNode* Pop_root(LinkStack& S)  //����ջ

{

    BiTNode* e;

    StackNode* p;

    if (S == NULL)

    {

        printf("�����ʽ�����������������ʽ");

    }

    e = S->root;

    p = S;

    S = S->next;

    delete p;

    return e;

}

char Pop_op(LinkStack& S)  //�������ջ

{

    char e;

    StackNode* p;

    if (S == NULL)

    {

        printf("ջΪ��");

    }

    e = S->op;

    p = S;

    S = S->next;

    delete p;

    return e;

}

char Pop_Post_data(LinkStack_Post& S)  //��ջ (���ں���ǵݹ����)

{

    char e;

    StackNode_Post* p;

    if (S == NULL)

    {

        printf("ջΪ��");

    }

    e = S->data;

    p = S;

    S = S->next;

    delete p;

    return e;

}

int  Pop_Post_num(LinkStack_Post& S)  //��ջ (���ں���ǵݹ����)

{

    int  e;

    StackNode_Post* p;

    if (S == NULL)

    {

        printf("ջΪ��");

    }

    e = S->num;

    p = S;

    S = S->next;

    delete p;

    return e;

}

char  GetTop_op(LinkStack S)    //����ջ��Ԫ��

{

    if (S != NULL)     //ջ�ǿ�

        return S->op;

}

int  GetTop_Post_num(LinkStack_Post S)    //����ջ��Ԫ��(���ں���ǵݹ����)

{

    if (S != NULL)     //ջ�ǿ�

        return S->num;

}

char  GetTop_Post_data(LinkStack_Post S)    //����ջ��Ԫ�� (���ں���ǵݹ����)

{

    if (S != NULL)     //ջ�ǿ�

        return S->data;

}

char Precede(char t1, char t2)  //�ж���������������ȹ�ϵ

{

    char f;

    switch (t2)

    {

    case '+':

        if ((t1 == '(') || (t1 == '#'))

            f = '<';

        else f = '>';

        break;

    case '-':

        if ((t1 == '(') || (t1 == '#'))

            f = '<';

        else f = '>';

        break;

    case '*':

        if ((t1 == '*') || (t1 == '/') || (t1 == ')'))

            f = '>';

        else f = '<';

        break;

    case '/':

        if ((t1 == '*') || (t1 == '/') || (t1 == ')'))

            f = '>';

        else f = '<';

        break;

    case '(':

        f = '<';

        break;

    case ')':

        if ((t1 == '('))

            f = '=';

        else f = '>';

        break;

    case '#':

        if (t1 == '#')

            f = '=';

        else f = '>';

        break;



    }

    return f;

}

int In(char i)  //�ж϶�ȡ�����ַ��Ƿ��ǲ�����

{

    switch (i)

    {

    case '+':  return 1;

    case '-':  return 1;

    case '*':  return 1;

    case '/':  return 1;

    case '(':  return 1;

    case ')':  return 1;

    case '#':  return 1;

    default:  return 0;

    }



}

int In_Post(char i)  //�ж϶�ȡ�����ַ��Ƿ��������

{

    switch (i)

    {

    case '+':  return 1;

    case '-':  return 1;

    case '*':  return 1;

    case '/':  return 1;

    default:  return 0;

    }

}

int  Operate(int a, char theta, int b)

{

    switch (theta)

    {

    case '+': return a + b;

    case '-': return a - b;

    case '*': return a * b;

    case '/': return a / b;

    }

}

void CreateTree_op(BiTree& T, BiTree a, BiTree b, char theta)   //����һ������������a���Һ�����b����������theta�������������

{

    BiTree L;

    L = new BiTNode;

    L->data = theta;

    L->lchild = a;

    L->rchild = b;

    T = L;

}

void CreateTree_num(BiTree& T, BiTree a, BiTree b, int theta)   //����һ������������a���Һ�����b����������theta������������

{

    BiTree L;

    L = new BiTNode;

    L->num = theta;

    L->lchild = a;

    L->rchild = b;

    T = L;

}



void CreateBiTree(BiTree& T, LinkStack& Tree, LinkStack& Optr)  //�ñ��ʽ����������

{

    BiTree a = NULL;

    BiTree b = NULL;

    BiTree c, d;

    T = NULL;

    char ch, theta, f;

    int m = 0;

    ch = getchar();

    while ((ch != '#') || (GetTop_op(Optr)) != '#')

    {

        if (!In(ch))   //�ж϶�ȡ�����ַ��ǲ��������

        { //�ַ�������

            while (!In(ch))

            {

                ch = ch - '0';

                m = m * 10 + ch;

                ch = getchar();

            }

            if (m != 0)

            {

                CreateTree_num(T, a, b, m);

                Push_root(Tree, T);

                m = 0;

            }

        }

        else   //��ȡ�����ַ������������

        {

            switch (Precede(GetTop_op(Optr), ch))    //�ж����ȼ�

            {

            case '<': Push_op(Optr, ch);

                ch = getchar();

                break;

            case '>': theta = Pop_op(Optr);

                c = Pop_root(Tree);

                d = Pop_root(Tree);

                CreateTree_op(T, d, c, theta);

                Push_root(Tree, T);

                break;

            case '=': f = Pop_op(Optr);  //��c������Pop�ķ���ֵ����ֹ�����getchar()���

                ch = getchar();

                break;

            }



        }

    }

}

void PreOrderTraverse(BiTree T)   //����ݹ�

{

    if (T)   //�������ǿ�

    {

        if (T->lchild == NULL && T->rchild == NULL)

        {

            cout << T->num << " ";

        }
        else cout << T->data << " ";

        PreOrderTraverse(T->lchild); //�������������

        PreOrderTraverse(T->rchild); //�������������



    }

}

void InOrderTraverse(BiTree T)    //�������

{

    if (T)   //�������ǿ�

    {

        InOrderTraverse(T->lchild); //�������������

        if (T->lchild == NULL && T->rchild == NULL)

        {

            cout << T->num << " ";

        }
        else cout << T->data << " "; //���ʸ��ڵ�

        InOrderTraverse(T->rchild); //�������������

    }

}

void PostOrderTraverse(BiTree T)   //����

{

    if (T)   //�������ǿ�

    {

        PostOrderTraverse(T->lchild); //�������������

        PostOrderTraverse(T->rchild); //�������������

        if (T->lchild == NULL && T->rchild == NULL)

        {

            cout << T->num << " ";

        }
        else cout << T->data << " "; //���ʸ��ڵ�  

    }

}

void  PostOrderTraverse_Stack(BiTree T, LinkStack_Post S1)       //����ǵݹ�

{

    //������������������ֵ�ջ

    LinkStack S;

    BiTNode* p, * q;

    q = NULL;

    char a = '0';

    int b = 0;

    InitStack(S);

    InitStack_Post(S1);

    p = T;

    while (p || S)

    {

        if (p)

        {

            if (p->lchild == NULL && p->rchild == NULL)   //�ж��Ƿ�������

            {

                Push_Post_num(S1, p->num);

            }
            else Push_Post_data(S1, p->data);

            Push_root(S, p);

            p = p->rchild;

        }

        else

        {

            q = Pop_root(S);

            p = q->lchild;

        }

    }

    while (S1)  //�����׺���ʽ

    {

        if (In_Post(GetTop_Post_data(S1))) //�ж�ջ���ǲ��������

        {//ջ���������

            a = Pop_Post_data(S1);

            cout << a << " ";

        }
        else

        {//ջ��������

            b = Pop_Post_num(S1);

            cout << b << " ";

        }

    }

}



void  EvaluateExpression(BiTree T, LinkStack_Post S1, LinkStack_Post& OPND)

{

    char theta;

    int  a1, b1;

    LinkStack S;

    BiTNode* p, * q;

    q = NULL;

    char a = '0';

    int b = 0;

    InitStack(S);

    InitStack_Post(S1);

    p = T;

    while (p || S)

    {

        if (p)

        {

            if (p->lchild == NULL && p->rchild == NULL)   //�ж��Ƿ�������

            {

                Push_Post_num(S1, p->num);

            }
            else Push_Post_data(S1, p->data);

            Push_root(S, p);

            p = p->rchild;

        }

        else

        {

            q = Pop_root(S);

            p = q->lchild;

        }

    }

    while (S1)  //�õ�������ջ

    {

        if (In_Post(GetTop_Post_data(S1))) //�ж�ջ���ǲ��������

        {//ջ���������

            theta = Pop_Post_data(S1);    //�����

            b1 = Pop_Post_num(OPND);      //����1

            a1 = Pop_Post_num(OPND); //����2

            Push_Post_num(OPND, Operate(a1, theta, b1));  //������������ѹ������ջ��

        }
        else

        {//ջ��������

            b1 = Pop_Post_num(S1);        //���ִ�ջS1��ջ

            Push_Post_num(OPND, b1);     //������ѹ������ջ

        }

    }

}

int main()
{
    LinkStack Tree, Optr; // �������ڵ��ջ
    LinkStack_Post S1, OPND; // �������ֺͲ�������ջ
    BiTree T, Tr, Trl, Trr; // ��
    int sum;

    InitStack(Tree); // ��ʼ�����ڵ�ջ
    InitStack(Optr); // ��ʼ��������ջ
    InitStack_Post(S1); // ��ʼ�����ں���ǵݹ������ջ
    InitStack_Post(OPND); // ��ʼ�����ڴ洢���ֺͲ�������ջ
    Push_op(Optr, '#'); // ��#������ջ��Ϊ��������

    cout << "�������������ʽ��" << endl;
    CreateBiTree(T, Tree, Optr); // �������ʽ����������
    T = Pop_root(Tree); // �����ڵ�ջ��ȡ�����ڵ�

    cout << "����ݹ������" << endl;
    PreOrderTraverse(T); // ����ݹ����������

    cout << endl;
    cout << "�������:" << endl;
    InOrderTraverse(T); // �������������

    cout << endl;
    cout << "����ǵݹ������" << endl;
    PostOrderTraverse_Stack(T, S1); // ����ǵݹ����������

    cout << endl;
    cout << "�沨�����ʽ��";
    PostOrderTraverse(T); // ����沨�����ʽ

    cout << endl;
    EvaluateExpression(T, S1, OPND); // ������ʽ�������
    sum = GetTop_Post_num(OPND); // ��ȡ������

    cout << "������Ϊ��" << sum;
}


//13+12*(25-21)-15/3#
//(100-90)*(23-22)+10-120/60# 
//���ݼ�ס��Ҫ�пո�