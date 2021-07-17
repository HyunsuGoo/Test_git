#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "fitness.h"

void total_number(int count);							// (6~10) 함수 선언
double average_weight(Fitness** pary, int count);
int max_weight(Fitness** pary, int count);
void print_info(Fitness** pary, int index);
void free_ary(Fitness** pary, int count);

int main()
{
	Fitness* ary[100];									// 구조체 형식의 포인터 배열 선언
	int i = 0, index;

	printf("\t[회원정보를 입력하세요.]\n(회원 번호에 음수를 입력하면 종료합니다.)\n");

	while (i < 100)
	{
		/* 메모리를 먼저 동적할당을 받고 난 뒤 값을 저장한다. */
		ary[i] = (Fitness*)malloc(sizeof(Fitness));		// 배열에 메모리를 동적 할당 한다. (heap영역에 저장) 

		printf("회원 번호 : ");
		scanf(" %d", &ary[i]->num);
		if (ary[i]->num < 0)							// 음수를 입력하면 회원 입력을 종료한다.
		{
			break;
		}
		printf("회원 이름 : ");
		scanf(" %s", ary[i]->name);
		printf("체중 : ");
		scanf(" %lf", &ary[i]->weight);
		printf("%d %s %.1lf\n\n", ary[i]->num, ary[i]->name, ary[i]->weight);

		i++;		// while문 반복 횟수 증가
	}

	if (i == 0) return 0;		// 맨 처음 입력에 음수가 들어올 경우 i가 0이기 때문에 종료한다.
	else {
		printf("\n\t[총 회원 정보]\n");
		total_number(i);											// 전체 회원수 출력
		printf("평균 체중 : %.1lf kg\n", average_weight(ary, i));		// 평균 체중 출력
		index = max_weight(ary, i);									// 최대 체중의 회원 번호를 index에 저장
		print_info(ary, index);										// 선택된 회원의 정보를 출력	
		free_ary(ary, i);											// 동적 할당 영역 해제
	}

	return 0;
}