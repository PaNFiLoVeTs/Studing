#include"stdio.h"
#include"locale.h"
#include"stdbool.h"

void menu()
{
	printf("\nMENU:\n");
	printf("1. ������ �������� �������\n");
	printf("2. ������������� ������ � ������� ��������\n");
	printf("3. ������������� ������ � ������� �����������\n");
	printf("4. ����������� ������\n");
	printf("0. ��������� ������ ���������\n");
}

void input(int A[], int N)
{
	int i;
		printf("������� ��������:");
		for (i = 0; i < N; i++)
		{
			scanf_s("%d", &A[i]);
		}
}

void print(int A[], int N)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%d\t", A[i]);
	}
}

void insertSort_up(int A[], int N)
{
	int i,tmp, counter;
	tmp = 0;
	counter = 0;
	for (i = 1; i < N; i++)
	{
		counter = i;
		while ((counter > 0) && (A[counter - 1] > A[counter]))
		{
			tmp = A[counter];
			A[counter] = A[counter - 1];
			A[counter - 1] = tmp;
			counter--;
		}
	}
}

void insertSort_down(int A[], int N)
{
	int i, tmp;
	int counter;
	tmp = 0;
	counter = 0;
	for (i = 1; i < N; i++)
	{
		counter = i;
		while ((counter > 0) && (A[counter - 1] < A[counter]))
		{
			tmp = A[counter];
			A[counter] = A[counter - 1];
			A[counter - 1] = tmp;
			counter--;
		}
	}
}

int Number()
{
	setlocale(LC_CTYPE, "Russian");
	int N;
	printf("������� ���������� ���������:");
	scanf_s("%d", &N);
	return N;
}

void main()
{
	int A[100];
	int t=10;
	int counter;
	int N = Number();
	bool wasinput;
	setlocale(LC_CTYPE, "Russian");
	wasinput = false;
	while (t)
	{
		menu();
		scanf_s("%d", &t);
		switch (t) 
		{
		case 1:
		{
			input(A, N);
			wasinput = true;
			break;
		}
		case 2:
		{
			if (wasinput) 
			insertSort_down(A, N);
			else printf("������� ������!");
			break;
		}
		case 3:
		{
			if (wasinput)
			insertSort_up(A, N);
			else printf("������� ������!");
			break;
		}
		case 4:
		{
			if (wasinput)
				print(A, N);
			else printf("������� ������!");
			break;
		}
		}
	}
}