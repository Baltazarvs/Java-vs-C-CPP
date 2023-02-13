#include <stdio.h>
#include <stdlib.h>

#define CRIT_SUM	1
#define CRIT_SUB	2

int** allocate_matrix(int rows, int cols)
{
	int** matrix = (int**)malloc(sizeof(int) * rows);
	int i, j;

	for (i = 0; i < rows; ++i)
		for (j = 0; j < cols; ++j)
			matrix[i] = (int*)malloc(sizeof(int) * cols);

	return matrix;
}

void destroy_matrix(int** ppMatrix, int rows, int cols)
{
	int i;
	for (i = 0; i < rows; ++i)
		free(ppMatrix[i]);
	free(ppMatrix);
}

int** create_matrix(int rows, int cols, int prompt, const char* matrix_name)
{
	int** matrix = allocate_matrix(rows, cols);
	int i, j;

	printf("\n");
	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			if (prompt)
			{
				printf("%s: Enter [%d][%d]: ", matrix_name, i, j);
				scanf("%d", &matrix[i][j]);
			}
			else
				matrix[i][j] = 0;
		}
	}
	return matrix;
}

int** alter_matrix(int crit, int** matrixA, int** matrixB, int rows, int cols)
{
	int** result_matrix = allocate_matrix(rows, cols);
	int i, j;

	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			switch (crit)
			{
				case CRIT_SUB:
					result_matrix[i][j] = matrixA[i][j] - matrixB[i][j];
					break;
				case CRIT_SUM:
				default:
					result_matrix[i][j] = matrixA[i][j] + matrixB[i][j];
			}
		}
	}
	return result_matrix;
}

void prompt_matrix_rs(int* pRows, int* pCols, const char* matrix_name)
{
	printf("[%s] Enter rows: ", matrix_name);
	scanf("%d", pRows);
	printf("[%s] Enter columns: ", matrix_name);
	scanf("%d", pCols);
	printf("[%s] Matrix [%d][%d]\n\n", matrix_name, *pRows, *pCols);
	return;
}


int main()
{
	const char* matrix_name = "2x2 Matrix";
	int rows = 0, cols = 0;

	prompt_matrix_rs(&rows, &cols, matrix_name);

	int** matrixA = create_matrix(rows, cols, 1, "A");
	int** matrixB = create_matrix(rows, cols, 1, "B");
	int** res_matrix = NULL;

	unsigned int choice = 0;
	printf("0) Sum Matrix\t\t1) Subtract Matrix\nChoice: ");
	scanf("%d", &choice);

	if(choice == 0u)
		res_matrix = alter_matrix(CRIT_SUM, matrixA, matrixB, rows, cols);
	else
		res_matrix = alter_matrix(CRIT_SUB, matrixA, matrixB, rows, cols);

	printf("\nA + B\n");
	int i, j;

	for (i = 0; i < rows; ++i)
	{
		printf("[\t");
		for (j = 0; j < cols; ++j)
			printf("%d\t", res_matrix[i][j]);
		printf("]\n");
	}

	destroy_matrix(matrixA, rows, cols);
	destroy_matrix(matrixB, rows, cols);
	destroy_matrix(res_matrix, rows, cols);
	
	getch();

	return 0;
}