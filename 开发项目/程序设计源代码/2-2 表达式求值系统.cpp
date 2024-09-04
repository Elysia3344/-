#include<iostream>

using namespace std;

typedef struct BiTNode
{
    char data; // 数据域，存储字符
    int   num; // 数据域，存储数字
    struct BiTNode* lchild, * rchild; // 左右孩子指针
}BiTNode, * BiTree; // 二叉树结点和指针类型定义

typedef struct StackNode
{
    BiTNode* root; // 指向二叉树结点的指针
    char   op; // 运算符
    struct StackNode* next; // 下一个栈节点指针
} StackNode, * LinkStack; // 栈结点和指针类型定义

typedef struct StackNode_Post
{
    int num; // 用来存数字
    char  data; // 用来存运算符
    struct StackNode_Post* next; // 下一个栈节点指针
} Stack_Post, * LinkStack_Post; // 后序遍历时所用到的栈的储存结构




void InitStack(LinkStack& S)  //构造一个空栈

{

    S = NULL;

}

void InitStack_Post(LinkStack_Post& S)  //构造一个空栈(用于后序非递归遍历)  

{

    S = NULL;

}

/*  */

void Push_root(LinkStack& S, BiTNode* e)      //根节点入栈

{

    StackNode* p;

    p = new StackNode;

    p->root = e;

    p->next = S;

    S = p;

}
//将根节点压入栈中，可以方便我们对整个二叉树进行遍历或其他操作。

void Push_op(LinkStack& S, char e)      //操作符入栈

{

    StackNode* p;

    p = new StackNode;

    p->op = e;

    p->next = S;

    S = p;

}

void Push_Post_num(LinkStack_Post& S, int e)      //数字入栈(用于后序非递归遍历)  

{

    StackNode_Post* p;

    p = new StackNode_Post;

    p->num = e;

    p->next = S;

    S = p;

}

void Push_Post_data(LinkStack_Post& S, char e)      //运算符入栈 (用于后序非递归遍历)

{

    StackNode_Post* p;

    p = new StackNode_Post;

    p->data = e;

    p->next = S;

    S = p;

}



BiTNode* Pop_root(LinkStack& S)  //根出栈

{

    BiTNode* e;

    StackNode* p;

    if (S == NULL)

    {

        printf("输入格式错误，请输入整数表达式");

    }

    e = S->root;

    p = S;

    S = S->next;

    delete p;

    return e;

}

char Pop_op(LinkStack& S)  //运算符出栈

{

    char e;

    StackNode* p;

    if (S == NULL)

    {

        printf("栈为空");

    }

    e = S->op;

    p = S;

    S = S->next;

    delete p;

    return e;

}

char Pop_Post_data(LinkStack_Post& S)  //出栈 (用于后序非递归遍历)

{

    char e;

    StackNode_Post* p;

    if (S == NULL)

    {

        printf("栈为空");

    }

    e = S->data;

    p = S;

    S = S->next;

    delete p;

    return e;

}

int  Pop_Post_num(LinkStack_Post& S)  //出栈 (用于后序非递归遍历)

{

    int  e;

    StackNode_Post* p;

    if (S == NULL)

    {

        printf("栈为空");

    }

    e = S->num;

    p = S;

    S = S->next;

    delete p;

    return e;

}

char  GetTop_op(LinkStack S)    //返回栈顶元素

{

    if (S != NULL)     //栈非空

        return S->op;

}

int  GetTop_Post_num(LinkStack_Post S)    //返回栈顶元素(用于后序非递归遍历)

{

    if (S != NULL)     //栈非空

        return S->num;

}

char  GetTop_Post_data(LinkStack_Post S)    //返回栈顶元素 (用于后序非递归遍历)

{

    if (S != NULL)     //栈非空

        return S->data;

}

char Precede(char t1, char t2)  //判断两个运算符的优先关系

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

int In(char i)  //判断读取到的字符是否是操作符

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

int In_Post(char i)  //判断读取到的字符是否是运算符

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

void CreateTree_op(BiTree& T, BiTree a, BiTree b, char theta)   //创建一棵树，左孩子是a，右孩子是b，数据域是theta用来储存运算符

{

    BiTree L;

    L = new BiTNode;

    L->data = theta;

    L->lchild = a;

    L->rchild = b;

    T = L;

}

void CreateTree_num(BiTree& T, BiTree a, BiTree b, int theta)   //创建一棵树，左孩子是a，右孩子是b，数据域是theta用来储存数字

{

    BiTree L;

    L = new BiTNode;

    L->num = theta;

    L->lchild = a;

    L->rchild = b;

    T = L;

}



void CreateBiTree(BiTree& T, LinkStack& Tree, LinkStack& Optr)  //用表达式创建二叉树

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

        if (!In(ch))   //判断读取到的字符是不是运算符

        { //字符是数字

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

        else   //读取到的字符是四则运算符

        {

            switch (Precede(GetTop_op(Optr), ch))    //判断优先级

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

            case '=': f = Pop_op(Optr);  //用c接受下Pop的返回值，防止后面的getchar()误读

                ch = getchar();

                break;

            }



        }

    }

}

void PreOrderTraverse(BiTree T)   //先序递归

{

    if (T)   //二叉树非空

    {

        if (T->lchild == NULL && T->rchild == NULL)

        {

            cout << T->num << " ";

        }
        else cout << T->data << " ";

        PreOrderTraverse(T->lchild); //先序遍历左子树

        PreOrderTraverse(T->rchild); //先序遍历右子树



    }

}

void InOrderTraverse(BiTree T)    //中序遍历

{

    if (T)   //二叉树非空

    {

        InOrderTraverse(T->lchild); //中序遍历左子树

        if (T->lchild == NULL && T->rchild == NULL)

        {

            cout << T->num << " ";

        }
        else cout << T->data << " "; //访问根节点

        InOrderTraverse(T->rchild); //中序遍历右子树

    }

}

void PostOrderTraverse(BiTree T)   //后序

{

    if (T)   //二叉树非空

    {

        PostOrderTraverse(T->lchild); //后序遍历左子树

        PostOrderTraverse(T->rchild); //后序遍历右子树

        if (T->lchild == NULL && T->rchild == NULL)

        {

            cout << T->num << " ";

        }
        else cout << T->data << " "; //访问根节点  

    }

}

void  PostOrderTraverse_Stack(BiTree T, LinkStack_Post S1)       //后序非递归

{

    //用来储存运算符合数字的栈

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

            if (p->lchild == NULL && p->rchild == NULL)   //判断是否是数字

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

    while (S1)  //输出后缀表达式

    {

        if (In_Post(GetTop_Post_data(S1))) //判断栈顶是不是运算符

        {//栈顶是运算符

            a = Pop_Post_data(S1);

            cout << a << " ";

        }
        else

        {//栈顶是数字

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

            if (p->lchild == NULL && p->rchild == NULL)   //判断是否是数字

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

    while (S1)  //得到计算结果栈

    {

        if (In_Post(GetTop_Post_data(S1))) //判断栈顶是不是运算符

        {//栈顶是运算符

            theta = Pop_Post_data(S1);    //运算符

            b1 = Pop_Post_num(OPND);      //数字1

            a1 = Pop_Post_num(OPND); //数字2

            Push_Post_num(OPND, Operate(a1, theta, b1));  //将运算结果重新压入数字栈中

        }
        else

        {//栈顶是数字

            b1 = Pop_Post_num(S1);        //数字从栈S1出栈

            Push_Post_num(OPND, b1);     //将数字压入数字栈

        }

    }

}

int main()
{
    LinkStack Tree, Optr; // 储存树节点的栈
    LinkStack_Post S1, OPND; // 储存数字和操作符的栈
    BiTree T, Tr, Trl, Trr; // 树
    int sum;

    InitStack(Tree); // 初始化树节点栈
    InitStack(Optr); // 初始化操作符栈
    InitStack_Post(S1); // 初始化用于后序非递归遍历的栈
    InitStack_Post(OPND); // 初始化用于存储数字和操作符的栈
    Push_op(Optr, '#'); // 将#符号入栈作为结束符号

    cout << "请输入整数表达式：" << endl;
    CreateBiTree(T, Tree, Optr); // 创建表达式二叉树函数
    T = Pop_root(Tree); // 从树节点栈中取出根节点

    cout << "先序递归遍历：" << endl;
    PreOrderTraverse(T); // 先序递归遍历二叉树

    cout << endl;
    cout << "中序遍历:" << endl;
    InOrderTraverse(T); // 中序遍历二叉树

    cout << endl;
    cout << "后序非递归遍历：" << endl;
    PostOrderTraverse_Stack(T, S1); // 后序非递归遍历二叉树

    cout << endl;
    cout << "逆波兰表达式：";
    PostOrderTraverse(T); // 输出逆波兰表达式

    cout << endl;
    EvaluateExpression(T, S1, OPND); // 计算表达式结果函数
    sum = GetTop_Post_num(OPND); // 获取计算结果

    cout << "计算结果为：" << sum;
}


//13+12*(25-21)-15/3#
//(100-90)*(23-22)+10-120/60# 
//数据记住不要有空格！