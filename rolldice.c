#include <stdio.h>        //���������������
#include <stdlib.h>       //����һЩ���ú�������rand��srand
#include <time.h>         //���ڻ�ȡϵͳʱ�����������������
int rollDice() {          //����һ������rollDice
    return rand() % 6 + 1;//rand() �����᷵��һ�������������% 6 ��ȡģ���㣬�õ��Ľ���� rand() ����ֵ���� 6 ����������������ķ�Χ�� 0 �� 5 ��Ȼ��+1 ʹ�ý���ķ�Χ��� 1 �� 6 
}                         //����һ�����������

int main() {
    unsigned int seed;    //����һ���޷�������seed���ڽ����û�����������
    printf("������һ���޷���������Ϊ���������");
    scanf("%u",&seed);    //��ȡ�û����벢�洢��seed��
    srand(seed);          //���������������������

    int point = 0;        //������������ point ���ڼ�¼��ҵĵ����������һ�ֲ��� 7��11��2��3��12 �ĺ�ֵ��
    int sum;              //������������ sum ���ڼ�¼ÿ�����������ӵĺ�ֵ��

    sum = rollDice() + rollDice();//���� rollDice �������Σ����������ӣ��õ���һ�������ӵĺ�ֵ
    
    if (sum == 7 || sum == 11){
        printf("��ϲ����Ӯ�ˣ�\n");
        return 0;
    }else if (sum == 2 || sum ==3 || sum ==12) { 
        printf("���ź��������ˣ�\n");
        return 0;
    }else {
        point = sum;
        printf("��ĵ�����: d%\n",point);
    }

    while (1) {           //"1"������ԶΪ�������  ����һ������ѭ��
        sum = rollDice() + rollDice();

        if (sum == point) {
            printf("��ϲ����Ӯ�ˣ�\n");
            break;
        } else if (sum == 7) {
            printf("���ź��������ˣ�\n");
            break;
        }
    }

    return 0;
}
