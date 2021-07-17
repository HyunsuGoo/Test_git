#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "fitness.h"

void total_number(int count);							// (6~10) �Լ� ����
double average_weight(Fitness** pary, int count);
int max_weight(Fitness** pary, int count);
void print_info(Fitness** pary, int index);
void free_ary(Fitness** pary, int count);

int main()
{
	Fitness* ary[100];									// ����ü ������ ������ �迭 ����
	int i = 0, index;

	printf("\t[ȸ�������� �Է��ϼ���.]\n(ȸ�� ��ȣ�� ������ �Է��ϸ� �����մϴ�.)\n");

	while (i < 100)
	{
		/* �޸𸮸� ���� �����Ҵ��� �ް� �� �� ���� �����Ѵ�. */
		ary[i] = (Fitness*)malloc(sizeof(Fitness));		// �迭�� �޸𸮸� ���� �Ҵ� �Ѵ�. (heap������ ����) 

		printf("ȸ�� ��ȣ : ");
		scanf(" %d", &ary[i]->num);
		if (ary[i]->num < 0)							// ������ �Է��ϸ� ȸ�� �Է��� �����Ѵ�.
		{
			break;
		}
		printf("ȸ�� �̸� : ");
		scanf(" %s", ary[i]->name);
		printf("ü�� : ");
		scanf(" %lf", &ary[i]->weight);
		printf("%d %s %.1lf\n\n", ary[i]->num, ary[i]->name, ary[i]->weight);

		i++;		// while�� �ݺ� Ƚ�� ����
	}

	if (i == 0) return 0;		// �� ó�� �Է¿� ������ ���� ��� i�� 0�̱� ������ �����Ѵ�.
	else {
		printf("\n\t[�� ȸ�� ����]\n");
		total_number(i);											// ��ü ȸ���� ���
		printf("��� ü�� : %.1lf kg\n", average_weight(ary, i));		// ��� ü�� ���
		index = max_weight(ary, i);									// �ִ� ü���� ȸ�� ��ȣ�� index�� ����
		print_info(ary, index);										// ���õ� ȸ���� ������ ���	
		free_ary(ary, i);											// ���� �Ҵ� ���� ����
	}

	return 0;
}