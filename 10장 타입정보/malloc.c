#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int num;
	int* pArr;
	int average = 0;
	printf("��� ������ ������ ���ΰ� �ڳ� : ");
	scanf("%d", &num);

	//0�� ������ ���α׷� ������.
	if (num == 0)
	{
		return 0;
	}

	//���� ���� ��ŭ �޸� �����Ҵ��� �մϴ�.
	pArr = (int*)malloc(sizeof(int) * num);

	//�����Ҵ� ����
	if (pArr == NULL)
	{
		printf("malloc error");
		exit(1);
	}

	//������ �ް� �����մϴ�.
	for (int i = 0; i < num; ++i)
	{
		printf("[%d/%d]���� �Է� : ", i + 1, num);
		scanf("%d", &pArr[i]);
	}

	//���
	for (int i = 0; i < num; ++i)
	{
		printf("%d��° ������ ���� : %d\n", i + 1, pArr[i]);
	}

	//��� ���
	for (int i = 0; i < num; ++i)
	{
		average += pArr[i];
	}

	//������ ������ ���� ������ �Ҽ��� ���ϴ� �������ϴ�.
	average /= num;
	printf("��� : %d\n", average);

	//�����Ҵ� ����
	free(pArr);

	system("pause");
	return 0;
}


