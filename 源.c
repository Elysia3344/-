#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>//��Ҫ©����


//int Add(int x,int y)//������һ��Ҫע���Ƿ������Ĵ���ģ�
//{
//	int z = x+y;//��Ҫ��©���ֺţ�
//return z;
//}
int main()
{

    ////int num1 = 100;
    ////int num2 = 200;
    //int sum = 0;//Ҫ�������sum(�͵���˼��
    ////	sum = Add(num1, num2);
    //sum = Add(2, 3);
    //sum = Add(56, 78);//ע�⣬sum�������һ����sum
    //
    //printf("sum=%d\n", sum);//����=���ݵ���ʽ

    int pivotIndex(int* nums, int numsSize)//numsSize���ܹ�������������i�ǵ�ǰ����ʱ����
    {
        int total = 0;
        for (int i = 0; i < numsSize; ++i)
        {
            total += nums[i];//�����м���������i��������total������ֻ�ǰ�total������
        }
        int sum = 0;
        for (int i = 0; i < numsSize; ++i)//��һ��ѭ�������������
        {
            if (2 * sum + nums[i] == total)//֮���������и�nums[i]����Ϊ�����ǰ��û��ֵ����ô�Լ�Ҳ��
                //��С��
            {
                return i;//����iѭ����return��ʾ������

            }
            sum += nums[i];//������ߵ�ֵ�����������������ֵ����Ͳ��ö����ұߵ��ˡ�
            //ע�⣬�����ѭ���������ѭ��������ͬ��������Ȼ��������ֵһ��������Ϊ������ͬ����
            //��ֵ�Ĵ�С��ͬ
        }
        return -1;//��Ŀ����
    }//��Ϊ������һ���ⲿ����������ֻ���ù����ı�����������ɣ��������ﱨ������

    
    return 0;


}

int total = 0;
for (int i = 0; i < numsSize; ++i)
{
    total += nums[i];
}
int sum = 0;
for (int i = 0; i < numsSize; ++i)
{
    if (2 * sum + nums[i] == total)
    {
        return i;

    }
    return -1;//0��-1������
}

