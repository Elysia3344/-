#define _CRT_SECURE_NO_WARNINGS
int main()
{
	//char arr1[] = "abc";
	//printf("%s\n", arr1);
	printf("%d\n", strlen(arr1));
	int a, b, sum;
	a = 101;
	b = 201;
	sum = a + b;
	printf("sum is %d\n", sum);

	int max(int x, int y);
	int a, b, c;
	scanf("%d,%d", &a, &b);
	c = max(a, b);
	printf("max = %d\n", c);

	int age = 20;
	scanf("%d\n", age);

	/*printf("%s\n", "\"");
	printf("%s\n", "\132");
	printf("%s\n", "\x76");
	printf("%d\n", strlen("c:\test\327\test.c"));*/

	int input = 0;//���������input�����룬��Ϊ����Ҫ�õ�input
	printf("�������\n");//���Ĳ���%d������
	printf("��Ҫ�ú�ѧϰ��(1/0)>:");//>:��ʾ��ʾ��������ѡ��
	scanf("%d", &input);//һ�Ǵ���&������1��0��ѡ��Ҳ��Ҫ���봢�棬��scanf��
	scanf���û��У�
		if (input == 1)//һ����Ӣ�ĵ��ַ��������ĵĶ�����if��else���ǲ��ã���
			if����� = һ��Ҫ == ����Ȼ�Ͳ���
			printf("��offer\n");//ע��һ��Ҫ���б�©��
		else
			printf("������\n");

	int input = 0;//���������input�����룬��Ϊ����Ҫ�õ�input
	printf("��ѩ��������櫽���\n");//���Ĳ���%d������
	printf("������ע����wife�ǣ�(1/0)>:");//>:��ʾ��ʾ��������ѡ��
	scanf("%d", &input);//һ�Ǵ���&������1��0��ѡ��Ҳ��Ҫ���봢�棬��scanf��
	//scanf���û��У�
	if (input == 1)//һ����Ӣ�ĵ��ַ��������ĵĶ�����if��else���ǲ��ã���
		//�����=һ��Ҫ==����Ȼ�Ͳ���
		printf("����ϣ��\n");//ע��һ��Ҫ���б�©��
	else
		printf("���ǰ���ϣ�ţ�\n");

	return 0;
}