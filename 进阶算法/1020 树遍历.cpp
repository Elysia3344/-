#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int postorder[50];
int inorder[50];

struct Node
{
	int data;
	Node* lchild;
	Node* rchild;//�Լ����õ�ǰ�Ľṹ�壬Ŀ�ľ���Ϊ�˼̳и��������
};

Node* create(int postL, int postR, int inL,int inR)
{
	if (postL > postR)
	{
		return NULL;
	}

	Node* root = new Node;
	root->data = postorder[postR];

	int i;
	for (i = inL; i <= inR; i++)
	{
		if (inorder[i] == postorder[postR])
			break;
	}

	int leftnum = i - inL;

	root->lchild = create(postL, postL + leftnum - 1, inL, i - 1);
	root->rchild = create(postL + leftnum, postR - 1, i + 1, inR);

	
	return root;
}

int num = 0;
void levelorder(Node* root)
{
	queue<Node*>q;
	q.push(root);

	while (!q.empty())
	{
		Node* now = q.front();
		q.pop();
		cout << now->data;
		num++;
		if (num < n)
			cout << " ";
		if (now->lchild != NULL)
			q.push(now->lchild);
		if (now->rchild != NULL)
			q.push(now->rchild);

	}
}


int main()
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> postorder[i];
	for (int i = 0; i < n; i++)
		cin >> inorder[i];

	Node* root=create(0, n - 1, 0, n - 1);

	levelorder(root);

	return 0;
}

//����



#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
    int data;//��������
    Node* lchild;//child��������/������������,�ֱ����ߵ�������������,���������Ľڵ�
    Node* rchild;
}node;
//���������������ִ���Node*���͸�java��Ч��һ��
//��Ϊһ��node����

const int maxn = 50;

int postorder[maxn], inorder[maxn];
int n; //!!!

//�����Ͼ����Լ�������ͨ������������ȷ�����Ľṹ
//����ȷ����������ȷ�����Һ��ӣ��������Լ��ֻ������Ľṹ
//�����߼�����ͨ������ʵ��
 //�ܵĺ��ľ��ǲ�����Ƶ�е���⣬��ι�������Ȼ��ʹ��DFS��ָ��������������
// �������Ĺ����д����

//����ֻ���������������ȷ�����ڵ�

//�����ǽ�������Ϊ����ʱ�������ݣ�����Ϊ���Һ��ӵ�ʱ�������Ӹ����ڵ������
//Ŀ�ľ���Ϊ���������������ڵ����ݺ�������ĺ����ң�Ȼ����������


//          ��������߿�ʼ ���ұ�      ����  ���   �ұ�           ,�˴�����ʾ���ұ߽�
Node* create(int postL, int postR, int inL, int inR) //����һ����
{
    if (postL > postR) //��ǰ���ڵ��Ѿ�û�ж�Ӧ�ĺ���ʱ,����/�ҽڵ��Ѿ�û��ʱ
    {
        return NULL;
    }

    //Ѱ�Ҳ�����ڵ�

    Node* root = new Node;  //!!!û��ʼ��
    //ÿ�ζ��½�һ��Node��������
    //���return��һ��root�У��ͽ���������������

    root->data = postorder[postR];   //ͨ��������ɣ��ҵ����ڵ�    

    int i;//��ʾ��ǰ���ڵ��λ��
    for (i = inL; i <= inR; i++) {//Ѱ�Ҹ��ڵ��������λ�ã��Ӷ�Ѱ������/�Һ���
        if (inorder[i] == postorder[postR]) {//!!!!
            break;
        }
    }


    int leftNum = i - inL;//��ǰ���ڵ����߽ڵ�ĸ���




 //ѡ���ڵ㷶Χ
    //����Ѱ����������Ȼ������
    //ע����Щ���ͼӶ����൱������/���ƶ�����ȷ����/�������Ľڵ㷶Χ
//һֱ����Ѱ�ҵ����±�


                         //�����������ڵ�ѡ����Χ       ������/���ӽڵ㷶Χ
    root->lchild = create(postL, postL + leftNum - 1, inL, i - 1);  //������
    //postL + leftNum - 1����Ϊ���Ҹ������������߽ڵ�ĸ�����������ֻҪȷ������͸���
    // �������������е�������ڵ�ķ�Χ���ģ�-1����Ϊ�±��0��ʼ
    // 
    // ��ߵ����нڵ㶼����Ϊ���ڵ㣬��Ҫ��һ�ν�һ���ж�.

    //ע�⣬λ�ö����ڶ�Ӧ�����µ��±�

    //i-1��ʾ���ڵ���ߣ�����������߶�����Ϊ��ǰ���ĺ���



    //��������һ��û������,��ȥ�ҵ�ǰ�ڵ���Һ���(���������ԭ��)
    root->rchild = create(postL + leftNum, postR - 1, i + 1, inR);
    //����ʼ���ұ߱���
    //������������.
    //postR-1�������ŵ�ǰ��ǰ���ڵ����Һ��ӣ���ʱ��������û�У�ֻ���Һ��ӣ�
    //�Һ�����Ȼ���ڣ�������һ���ڵ���Ȼ����Ϊ�����ĸ�������˳�����Ҹ������Ե�ǰ�������һλ���������ĸ��ڵ�
    //i+1�����ұ���,��Ϊ��ʱ���ڵ�û�������ӣ�����ң����Դ�ʱ�������еĽڵ㷶Χֻ�����ڸ��ڵ���ұߣ����Լ�һ

 /*   postL + leftNum - 1��postR - 1��ʲô��ͬ��*/
    //Ŀ���ǲ�ͬ�ģ�ǰ����һֱ��������������������ת��Ϊ���������ҵĶ����ҽڵ�ķ�Χ���ǲ�һ����
    //postR�Ƿ�Χ�Ҳ�ı߽磬�ں������Ǹ���ȥ����ǰ���ͼ�һ����

    //��postL + leftNum���ǵ�ǰ��߽�����������ڵ�ĸ��������൱���ų�����ڵ㣬ֻѡ���ҽڵ�
    //��Ϊ���������Ҹ�������ֱ�ӼӾ����ƶ����ҽڵ�

    //inL��inR��˼���Ǽ̳���һ�����Ľ���������κα仯,Ҳ���ǲ���,����postR��Ҳ���ǣ�ʹ�õ�ʱ���Ǽ̳е�
    //������һ�εĽ����ֱ�������þ�����.





    return root;    //���ؽڵ�,�����еĽڵ���������
}

//��α���
int num = 0;    //�������Ѿ�����Ľڵ����
void levelorder(Node* root) //BFS
//rootֻ���ϴ���ͷ�Ľڵ㣬Ҳ����ͷ�ڵ㣬Ȼ�����������ͷ���ĺ��Ӿ���lchild��rchild
//now�ڵ���ǽ�����root�����ݣ�Ȼ���������±���
{
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* now = q.front();
        q.pop();    //����
        printf("%d", now->data);
        num++;
        if (num < n) cout << " ";
        if (now->lchild != NULL) {//�����Ҳ�����У�Ȼ��ѭ�����
            q.push(now->lchild);//nowָ����ָ���ӣ�Ҳ���Ǹ��½ڵ���Ϣ�����±���
        }
        if (now->rchild != NULL) {
            q.push(now->rchild);
        }
    }
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }


    Node* root1 = create(0, n - 1, 0, n - 1);   //!!!

    levelorder(root1);
    return 0;
}

//��˼��д�������û�������������ôֻ�ð�һ�����������д�þͿ�����
//ʣ�µ��ظ����������ݹ飬ѭ������������̫͸����������������������
