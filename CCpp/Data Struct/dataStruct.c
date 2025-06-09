#include <stdio.h>
#include <stdlib.h>

// 定义最大表长度
#define MAXSIZE 100

// 定义顺序表结构体
typedef struct
{
    int data[MAXSIZE];
    int length;
} SeqList;

// 初始化顺序表
void InitList(SeqList *L)
{
    L->length = 0;
}

// 输入创建有序表
void CreateList(SeqList *L)
{
    int num, i;
    printf("请输入表中的元素个数: ");
    scanf("%d", &num);

    printf("请输入有序表的元素: ");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &L->data[i]);
    }
    L->length = num;
}

// 合并两个有序表
void MergeList(SeqList LA, SeqList LB, SeqList *LC)
{
    int i = 0, j = 0, k = 0;

    while (i < LA.length && j < LB.length)
    {
        if (LA.data[i] <= LB.data[j])
        {
            LC->data[k++] = LA.data[i++];
        }
        else
        {
            LC->data[k++] = LB.data[j++];
        }
    }

    while (i < LA.length)
    {
        LC->data[k++] = LA.data[i++];
    }

    while (j < LB.length)
    {
        LC->data[k++] = LB.data[j++];
    }

    LC->length = k;
}

// 输出顺序表
void PrintList(SeqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main()
{
    SeqList LA, LB, LC;
    InitList(&LA);
    InitList(&LB);
    InitList(&LC);

    printf("创建第一个有序表:\n");
    CreateList(&LA);

    printf("创建第二个有序表:\n");
    CreateList(&LB);

    MergeList(LA, LB, &LC);

    printf("合并后的有序表为:\n");
    PrintList(LC);

    return 0;
}