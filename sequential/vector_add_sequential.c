#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int n = 1000000;
    char operation[20] = "addition";

    if (argc > 1)
    {
        n = atoi(argv[1]);
    }

    if (argc > 2)
    {
        strcpy(operation, argv[2]);
    }

    int *A = malloc(n * sizeof(int));
    int *B = malloc(n * sizeof(int));
    int *C = malloc(n * sizeof(int));

    if (A == NULL || B == NULL || C == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        A[i] = i;
        B[i] = i * 2;
    }

    double start = omp_get_wtime();

    if (strcmp(operation, "addition") == 0)
    {
        for (int i = 0; i < n; i++)
        {
            C[i] = A[i] + B[i];
        }
    }
    else if (strcmp(operation, "multiplication") == 0)
    {
        for (int i = 0; i < n; i++)
        {
            C[i] = A[i] * B[i];
        }
    }
    else
    {
        printf("Invalid operation. Use addition or multiplication.\n");
        free(A);
        free(B);
        free(C);
        return 1;
    }

    double end = omp_get_wtime();

    printf("Operation: %s\n", operation);
    printf("Vector Size: %d\n", n);
    printf("First 10 results:\n");

    for (int i = 0; i < 10 && i < n; i++)
    {
        printf("C[%d] = %d\n", i, C[i]);
    }

    printf("Sequential Execution Time: %f seconds\n", end - start);

    free(A);
    free(B);
    free(C);

    return 0;
}
