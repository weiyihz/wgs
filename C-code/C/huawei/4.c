/**
 *��һ������a[N]˳����0~N-1��Ҫ��ÿ��������ɾ��һ��������ĩβʱѭ������ͷ�������У������һ����ɾ��������ԭʼ�±�λ�á���8����(N=7)Ϊ��:��0��1��2��3��4��5��6��7����0->1->2(ɾ��)->3->4->5(ɾ��)->6->7->0(ɾ��),���ѭ��ֱ�����һ������ɾ����

 ��������:
 ÿ������Ϊһ��һ������n(С�ڵ���1000)��Ϊ�����Ա��,�������1000�����a[999]���м��㡣


 �������:
 һ��������һ����ɾ��������ԭʼ�±�λ�á�
 *
 * */
#include <stdio.h>
  
typedef struct queue{
    struct queue *next;
    int val;
}QUEUE_S;
  
int main(void){
    int n, i;
    QUEUE_S q[1000], *p;
  
    while (scanf("%d", &n) != EOF){
  
        /* ��ʼ��ѭ������ */
        for (i = 0; i < n - 1; i++){
            q[i].val = i;
            q[i].next = &q[i + 1];
        }
        q[i].val = i;
        q[i].next = q;
  
        p = q;
        while (1){
            if (p == p->next){
                printf("%d\n", p->val);
                break;
            }
            p->next->next = p->next->next->next; /* ɾ���������֮���Ԫ�� */
            p = p->next->next; /* ����ָ��λ�� */
        }
    }
    return 0;
}