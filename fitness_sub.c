#include <stdio.h>
#include <stdlib.h>
#include "fitness.h"

/* 입력받은 회원의 총 인원을 나타내는 함수 */
void total_number(int count)									
{
	printf("전체 회원 수 : %d 명\n", count);
}

/* 입력받은 회원들의 평균 체중을 구하는 함수 */
double average_weight(Fitness** pary, int count)			
{
	int i;
	double sum = 0, avg = 0;
	for (i = 0; i < count; i++)
	{
		sum += pary[i]->weight;								// 회원들의 체중의 총 합
		avg = sum / (double)count;							// 평균 = 총 합 / 개수
	}
	return avg;												// 평균 값 반환
}

/* 최대 체중인 회원을 나타내는 함수 */
int max_weight(Fitness** pary, int count)					
{
	int i;
	double max = pary[0]->weight;							// 체중 비교를 위한 초기값 초기화
	int index = pary[0]->num;								// 번호 비교를 위한 초기값 초기화
	for (i = 1; i < count + 1; i++)							// 단, 체중이 같은 회원이 여러명일 경우 가장 마지막 번호의 회원이 출력된다.
	{
		if (max < (pary[i]->weight))						// 회원의 몸무게를 서로 비교한다.
		{
			max = pary[i]->weight;
			index = pary[i]->num;							// 비교한 몸무게의 크기가 큰 사람의 회원 번호를 index에 저장한다. 
		}
	}
	return index;
}

/* 최대 체중인 회원의 정보를 나타내는 함수 */
void print_info(Fitness** pary, int index)					
{
	printf("최대 체중 회원의 번호 : %d 번\n\n", index);			// 최대 체중의 회원 번호 출력
	printf("\t[최대 체중인 회원]\n");
	printf("회원 번호 : %d 번\n회원 이름 : %s 님\n체중 : %.1lf kg\n", pary[index - 1]->num, pary[index - 1]->name, pary[index - 1]->weight);
}

/* 동적 할당을 해제하는 함수 */
void free_ary(Fitness** pary, int count)									
{
	int i;
	// 동적 할당을 순차적으로 해제(마지막 반복문 실행 시 ary[i]까지 메모리가 할당되기 때문에 count + 1)
	for (i = 0; i < count +1; i++)									
	{
		free(pary[i]);
	}
}