#include <stdio.h>
#include <stdlib.h>
#include "fitness.h"

/* �Է¹��� ȸ���� �� �ο��� ��Ÿ���� �Լ� */
void total_number(int count)									
{
	printf("��ü ȸ�� �� : %d ��\n", count);
}

/* �Է¹��� ȸ������ ��� ü���� ���ϴ� �Լ� */
double average_weight(Fitness** pary, int count)			
{
	int i;
	double sum = 0, avg = 0;
	for (i = 0; i < count; i++)
	{
		sum += pary[i]->weight;								// ȸ������ ü���� �� ��
		avg = sum / (double)count;							// ��� = �� �� / ����
	}
	return avg;												// ��� �� ��ȯ
}

/* �ִ� ü���� ȸ���� ��Ÿ���� �Լ� */
int max_weight(Fitness** pary, int count)					
{
	int i;
	double max = pary[0]->weight;							// ü�� �񱳸� ���� �ʱⰪ �ʱ�ȭ
	int index = pary[0]->num;								// ��ȣ �񱳸� ���� �ʱⰪ �ʱ�ȭ
	for (i = 1; i < count + 1; i++)							// ��, ü���� ���� ȸ���� �������� ��� ���� ������ ��ȣ�� ȸ���� ��µȴ�.
	{
		if (max < (pary[i]->weight))						// ȸ���� �����Ը� ���� ���Ѵ�.
		{
			max = pary[i]->weight;
			index = pary[i]->num;							// ���� �������� ũ�Ⱑ ū ����� ȸ�� ��ȣ�� index�� �����Ѵ�. 
		}
	}
	return index;
}

/* �ִ� ü���� ȸ���� ������ ��Ÿ���� �Լ� */
void print_info(Fitness** pary, int index)					
{
	printf("�ִ� ü�� ȸ���� ��ȣ : %d ��\n\n", index);			// �ִ� ü���� ȸ�� ��ȣ ���
	printf("\t[�ִ� ü���� ȸ��]\n");
	printf("ȸ�� ��ȣ : %d ��\nȸ�� �̸� : %s ��\nü�� : %.1lf kg\n", pary[index - 1]->num, pary[index - 1]->name, pary[index - 1]->weight);
}

/* ���� �Ҵ��� �����ϴ� �Լ� */
void free_ary(Fitness** pary, int count)									
{
	int i;
	// ���� �Ҵ��� ���������� ����(������ �ݺ��� ���� �� ary[i]���� �޸𸮰� �Ҵ�Ǳ� ������ count + 1)
	for (i = 0; i < count +1; i++)									
	{
		free(pary[i]);
	}
}