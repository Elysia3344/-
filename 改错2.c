#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

    int main()
    {
        float x, y;

        printf("Enter x: ");
        scanf("%f", &x);
        /*if (x = 10)*/
        if (fabs(x - 10) <= 0.0000001)//�ڶ��ڵȺ���˵����x=10������ֵ�ǲ�׼ȷ�ģ�
            //if�ж�x��СʱҪ����������ֵ����Ҫ�õ�fabs�������ֵС�ں�С��������

            y = 1 / x;

        //else if (x != 10)//ֱ��else����
        else
            y = x;

        printf("f(%.1f) = %.1f", x, y);//���Ų�Ҫ©��
        return 0;
    }