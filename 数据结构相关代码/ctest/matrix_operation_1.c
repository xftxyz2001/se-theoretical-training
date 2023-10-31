/*
 * 随机生成三个3*3同阶整数方阵A、B、C，验证公式：
 * (1)A*(B+C) = AB + AC
 * (2)(A*B)*C = A*(B*C)
 * (3)(A*B*C)^T = C^T*B^T*A^T
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义维度，即方阵的行数和列数
#define N 3

// 随机生成一个N阶整数方阵
int **randomMatrix()
{
    int i, j;
    int **matrix = (int **)malloc(N * sizeof(int *)); // 定义一个N阶整数方阵

    // 随机生成矩阵元素
    for (i = 0; i < N; i++)
    {
        matrix[i] = (int *)malloc(N * sizeof(int));
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = rand() % 100; // 生成0~99之间的随机整数
        }
    }

    return matrix;
}

// 输出N阶整数方阵
void printMatrix(char *str, int **matrix)
{
    int i, j;
    // 计算str的长度
    int len = 0;
    while (str[len++] != '\0')
        ;

    printf("%s = [\n", str);
    for (i = 0; i < N; i++)
    {
        // 输出空格，使得矩阵对齐
        for (j = 0; j < len + 3; j++)
        {
            printf(" ");
        }
        for (j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j < len + 2; j++)
    {
        printf(" ");
    }
    printf("]\n");
}

// 比较两个N阶整数方阵是否相等
int compareMatrix(int **matrix1, int **matrix2)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}

// 计算两个N阶整数方阵的和
int **addMatrix(int **matrix1, int **matrix2)
{
    int i, j;
    int **matrix = (int **)malloc(N * sizeof(int *)); // 定义一个N阶整数方阵

    // 计算矩阵元素
    for (i = 0; i < N; i++)
    {
        matrix[i] = (int *)malloc(N * sizeof(int));
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return matrix;
}

// 计算两个N阶整数方阵的积
int **multiplyMatrix(int **matrix1, int **matrix2)
{
    int i, j, k;
    int **matrix = (int **)malloc(N * sizeof(int *)); // 定义一个N阶整数方阵

    // 计算矩阵元素
    for (i = 0; i < N; i++)
    {
        matrix[i] = (int *)malloc(N * sizeof(int));
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = 0;
            for (k = 0; k < N; k++)
            {
                matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return matrix;
}

// 计算N阶整数方阵的转置
int **transposeMatrix(int **matrix)
{
    int i, j;
    int **matrixT = (int **)malloc(N * sizeof(int *)); // 定义一个N阶整数方阵

    // 计算矩阵元素
    for (i = 0; i < N; i++)
    {
        matrixT[i] = (int *)malloc(N * sizeof(int));
        for (j = 0; j < N; j++)
        {
            matrixT[i][j] = matrix[j][i];
        }
    }

    return matrixT;
}

int main(int argc, char const *argv[])
{
    int i, j;

    // 设置随机数种子
    srand((unsigned)time(NULL));

    // 生成三个同阶整数方阵
    int **A = randomMatrix();
    int **B = randomMatrix();
    int **C = randomMatrix();

    // 输出三个同阶整数方阵
    printMatrix("A", A);
    printMatrix("B", B);
    printMatrix("C", C);

    // A*(B+C) = AB + AC
    int **A_times_l_B_add_C_r = multiplyMatrix(A, addMatrix(B, C));
    int **A_times_B_add_A_times_C = addMatrix(multiplyMatrix(A, B), multiplyMatrix(A, C));
    printMatrix("A*(B+C)", A_times_l_B_add_C_r);
    printMatrix("AB + AC", A_times_B_add_A_times_C);
    printf("A*(B+C) = AB + AC ? %s\n", compareMatrix(A_times_l_B_add_C_r, A_times_B_add_A_times_C) ? "Yes" : "No");
    printf("\n");

    // (A*B)*C = A*(B*C)
    int **l_A_times_B_r_times_C = multiplyMatrix(multiplyMatrix(A, B), C);
    int **A_times_l_B_times_C_r = multiplyMatrix(A, multiplyMatrix(B, C));
    printMatrix("(A*B)*C", l_A_times_B_r_times_C);
    printMatrix("A*(B*C)", A_times_l_B_times_C_r);
    printf("(A*B)*C = A*(B*C) ? %s\n", compareMatrix(l_A_times_B_r_times_C, A_times_l_B_times_C_r) ? "Yes" : "No");
    printf("\n");

    // (A*B*C)^T = C^T*B^T*A^T
    int **l_A_times_B_times_C_r_T = transposeMatrix(multiplyMatrix(multiplyMatrix(A, B), C));
    int **C_T_times_B_T_times_A_T = multiplyMatrix(multiplyMatrix(transposeMatrix(C), transposeMatrix(B)), transposeMatrix(A));
    printMatrix("(A*B*C)^T", l_A_times_B_times_C_r_T);
    printMatrix("C^T*B^T*A^T", C_T_times_B_T_times_A_T);
    printf("(A*B*C)^T = C^T*B^T*A^T ? %s\n", compareMatrix(l_A_times_B_times_C_r_T, C_T_times_B_T_times_A_T) ? "Yes" : "No");
    printf("\n");

    return 0;
}
