// 假设函数sift(Elemtype A[],int n，int flag)能将A数组调整为一个大根堆。
// 当flag为0时，表示当前除了堆尾元素外，其余元素构成堆，该算法可从堆尾向上将其调整为一个大根堆；
// flag为1时，表示堆顶元素的左右子树分别是堆，该算法从堆顶向下将其调整为一个大根堆。

// 某优先队列采用顺序存储，通过调用sift算法，
// 写出进队EnterQueue(SeqQueue *Q, ElemType x)和出队DelQueue(SeqQueue *Q, ElemType *x)操作。
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef int Elemtype;

typedef struct
{
    Elemtype *data;
    int last;
} SeqQueue;

// 从堆尾向上将其调整为一个大根堆
// void sift0(Elemtype A[], int n)
// {
//     int i, j;
//     Elemtype x;
//     i = 0;
//     j = 2 * i + 1;
//     x = A[i];
//     while (j < n)
//     {
//         // 右节点大于左节点
//         if (j < n - 1 && A[j] < A[j + 1])
//             j++;
//         if (x >= A[j])
//             break;
//         A[i] = A[j];
//         i = j;
//         j = 2 * i + 1;
//     }
//     A[i] = x;
// }

// 从堆顶向下将其调整为一个大根堆
// void sift1(Elemtype A[], int n)
// {

// }

// 自下而上调整为大根堆（从i节点开始调整）
// void sift_up(SeqQueue *Q, int i)
// {
//     int j = i / 2; // i节点父节点为j
//     Elemtype temp = Q->data[i];
//     while (j > 0 && temp > Q->data[j])
//     { // 如果temp比父节点大，则上移temp直到合适位置
//         Q->data[i] = Q->data[j];
//         i = j;
//         j = i / 2;
//     }
//     Q->data[i] = temp; // 将temp放到合适位置
// }

// 自上而下调整为大根堆（从i节点开始调整）
// void sift_down(SeqQueue *Q, int i)
// {
//     int j = i * 2; // i节点左子节点为j
//     Elemtype temp = Q->data[i];
//     while (j <= Q->last)
//     { // 如果有子节点
//         if (j < Q->last && Q->data[j + 1] > Q->data[j])
//         { // 如果右子节点比左子节点大
//             j++;
//         }
//         if (temp >= Q->data[j])
//         { // 如果temp比子节点中的最大值都大，则退出循环
//             break;
//         }
//         Q->data[i] = Q->data[j]; // 否则将较大的子结点移到父节点位置上
//         i = j;
//         j = i * 2;
//     }
//     Q->data[i] = temp; // 将temp放到合适位置
// }

void sift(Elemtype A[], int n, int flag)
{
    // 当flag为0时，从堆尾向上调整为大根堆
    if (flag == 0) {
        for (int i = n / 2; i >= 1; i--) { // 从n/2开始至堆顶依次调整
            int j = i;
            while (j * 2 <= n) { // 沿较大的孩子结点向下筛选
                int k = j * 2;
                if (k + 1 <= n && A[k + 1] > A[k]) {
                    k++;
                }
                if (A[j] < A[k]) {
                    Elemtype temp = A[j];
                    A[j] = A[k];
                    A[k] = temp;
                    j = k;
                } else {
                    break;
                }
            }
        }
    }
    // 当flag为1时，从堆顶向下调整为大根堆
    else if (flag == 1) {
        int i = 1, j = 2 * i; // i指向当前待调整的结点，j指向i的左孩子
        while (j <= n) { // 当i有左孩子时循环进行比较
            if (j + 1 <= n && A[j + 1] > A[j]) { // 如果存在右孩子且比左孩子大，则j指向右孩子
                j = j + 1;
            }
            if (A[i] < A[j]) { // 如果i比其孩子结点小，则交换i和j的值
                Elemtype temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i = j;
                j = 2 * i;
            } else {
                break;
            }
        }
    }

    // if (flag == 0)
    // {
    //     sift_up(A, n);
    //     // for (int i = 1; i < n; i++) {
    //     //     sift_up(A, i);
    //     // }
    // }
    // else
    // {
    //     sift_down(A, 0);
    //     // for (int i = n / 2; i >= 0; i--) {
    //     //     sift_down(A, i);
    //     // }
    // }
    // return;
    // int i, j;
    // Elemtype x;
    // i = 0;
    // j = 2 * i + 1;
    // x = A[i];
    // flag == 0 ? sift0(A, n) : sift1(A, n);

    // if (flag == 0)
    // {
    //     while (j < n)
    //     {
    //         // 右节点大于左节点
    //         if (j < n - 1 && A[j] < A[j + 1])
    //             j++;
    //         if (x >= A[j])
    //             break;
    //         A[i] = A[j];
    //         i = j;
    //         j = 2 * i + 1;
    //     }
    // }
    // else
    // {
    //     while (j < n)
    //     {
    //         if (j < n - 1 && A[j] < A[j + 1])
    //             j++;
    //         if (x >= A[j])
    //             break;
    //         A[i] = A[j];
    //         i = j;
    //         j = 2 * i + 1;
    //     }
    // }
    // A[i] = x;
}

SeqQueue *InitQueue()
{
    SeqQueue *Q = (SeqQueue *)malloc(sizeof(SeqQueue));
    Q->data = (Elemtype *)malloc(sizeof(Elemtype) * MAXSIZE);
    Q->last = -1;
    return Q;
}

void EnterQueue(SeqQueue *Q, Elemtype x)
{
    Q->data[++Q->last] = x;
    sift(Q->data, Q->last + 1, 0);
    // sift(Q->data, Q->last, 0);
}

void DelQueue(SeqQueue *Q, Elemtype *x)
{
    // *x = Q->data[Q->last--];
    *x = Q->data[0];
    Q->data[0] = Q->data[Q->last--];
    sift(Q->data, Q->last + 1, 0);
    // sift(Q->data, Q->last, 1);
    // sift(Q->data, Q->last--, 1);
}

void output(SeqQueue *Q)
{
    for (int i = 0; i <= Q->last; i++)
    {
        printf("%d ", Q->data[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{

    SeqQueue *Q = InitQueue();
    EnterQueue(Q, 100);
    output(Q);
    EnterQueue(Q, 50);
    output(Q);
    EnterQueue(Q, 51);
    output(Q);
    EnterQueue(Q, 200);
    output(Q);
    EnterQueue(Q, 70);
    output(Q);
    EnterQueue(Q, 150);
    output(Q);
    EnterQueue(Q, 300);
    output(Q);

    Elemtype x;
    DelQueue(Q, &x);
    output(Q);
    DelQueue(Q, &x);
    output(Q);
    DelQueue(Q, &x);
    output(Q);

    return 0;
}
