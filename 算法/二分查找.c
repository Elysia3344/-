#include<stdio.h>
#include<stdlib.h>
//���ֲ��Ҽ�סһ��Ҫ���򣡣���������������������ģ���Ȼ�Ͳ���
//���ǣ��۰����Ҫ�����Ա�������˳��洢�ṹ�����ұ���Ԫ�ذ��ؼ����������У�ע�����Ҫ���������У�
//����һ������������Բ������������У���ǰһ�ڽ��ܵ���Ʒѡȡ����һ�ѱ�׼����Ϊ10����Ʒ�в��ҳ�Ψһ�Ĵ�Ʒ������������������Ҳ����ʹ�ö��ֲ��ҡ�
int binary_search(int* list,int len,int target)
{
	int low =0;
	int hight=len-1;
	int middle;
	
	while(low<=hight)
	//���Ƿ�ֹѭ���������Ϊ��������߻����ұߣ��������������
	{ 
	     middle=(low+hight)/2;//����һ���Ŀ��Ƚϣ�Ȼ�󿴿�������߻����ұ�(Ч������)
	     if(list[middle]==target)
	     {
		 	printf("�ҵ��ˣ�λ����%d",middle);
		 	
		 	return list[middle];//�����ݷ��ؾ�����
		 }
		
		else if(list[middle]>target)//Ŀ���ʵ��С��˵������ߣ����԰������ұߵ�hight��Ϊ��������Ǹ����ң������������Ϊ��ֹ��©���ݡ�
		{
			hight=middle-1;
		}
		
		else if(list[middle]<target)//ͬ��
				{
					low=middle+1;
				}
	}
	printf("�Ҳ���");
	return -1;
}

int main()
{
	int a[]={3,4,5,8,9,36,44};
	int b=binary_search(a,sizeof(a)/4,4);

	
	
	return 0;
}
