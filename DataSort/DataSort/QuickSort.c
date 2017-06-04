#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "DataSort.h"

/*
퀵 정렬
txt 파일에서 값을 받아 온 뒤 시작 위치를 first와 i, 마지막 위치를 last와 j로 설정하고, 
pivot의 위치는 first로 설정한다.
피벗 원소보다 작은 원소를 찾을 때까지 또는 i와 j가 만날 때 까지 j를 감소시킨 뒤
i의 원소와 j의 원소를 서로 교환한다.
피봇 원소와 j의 원소를 서로 교환한 후 현재의 정렬 상태를 출력하며, j는 피봇의 확정된 위치가 된다.
이렇게 둘로 나뉘어진 부분에 대해 각각 quick함수를 재귀호출한다.
*/

int compareCount, swapCount; //값을 비교한 횟수와 값의 위치를 바꾼 횟수를 저장하는 전역변수

void quick(int list[], int first, int last) {
	int i, j, pivot, t;
	if (first < last) { //시작 위치의 원소가 마지막 위치의 원소보다 클 경우
		printf("\n%2d단계 -> ", (swapCount++) + 1); //정렬을 시작할때마다 번호를 매김
		i = first; //i = 0++;
		j = last + 1; //j = size--;
		pivot = list[first]; //피벗을 리스트의 first번째 원소로 정함
		printf("first:%d  last:%d\n", first, last); //현재 first값과 last값을 출력
		do {
			while (list[++i] < pivot && i <= last); //list[i]의 값이 피벗보다 작고 i의 값이 last보다 작거나 같을때까지 i를 증가시킴
			while (list[--j]  > pivot && j >= first); //list[j]의 값이 피벗보다 크고 j의 값이 first보다 크거나 같을때까지 j를 감소시킴
			printf("i:%d  j:%d\n", i, j); //i와 j의 값을 출력
			if (i < j) swap(list, i, j); //i < j일때 i와 j의 값을 서로 교환
			compareCount++; //한번 비교할 때 마다 1씩 증가
		} while (i < j); //i < j일때 반복
		swap(list, first, j); //first와 j의 값을 서로 교환
		
		list[j] = -list[j]; // 위치가 정해진 원소를 표시하기 위해 값의 앞에 -를 붙여줌

		for (t = 0; t < size; t++) { //정렬된 결과 출력
			printf(" %3d ", list[t]);
		}
		printf(" \n");

		quick(list, first, j - 1); // j의 값을 -1하여 last값으로 설정하고 한번 더 quick함수 실행(재귀 호출)
		quick(list, j + 1, last); // j의 값을 +1하여 first값으로 설정하고 한번 더 quick함수 실행(재귀 호출)
	}
	else {   // first = last일 경우 함수를 종료
		return;
	}
}
void swap(int list[], int i, int j) { //값을 서로 교환하는 함수 swap
	int temp;
	temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

void quickSort() {
	int list[100], t;
	FILE *fp;

	if ((fp = fopen("data.txt", "r")) == NULL) { //파일 열기에 실패했을 경우 함수 실행을 종료시킴
		printf("DATA FILE open ERROR !!\7\n");
		exit(-1);
	}
	fscanf(fp, "%d", &size); //배열에 들어갈 값의 양으로 파일의 첫 값을 size변수에 저장

	for (t = 0; t<size; t++) { //파일의 두번째 줄의 값들을 list배열에 저장
		fscanf(fp, " %2d ", &list[t]);
	}

	printf("정렬할 원소 : ");
	for (t = 0; t<size; t++) { //정렬하기 전 정렬할 값들을 출력
		printf("%d ", list[t]);
	}
	printf("\n");

	printf("\n<<<<<<<<<<퀵 정렬 수행>>>>>>>>>>");
	quick(list, 0, size - 1); //퀵 정렬 핵심 함수 실행

	fclose(fp); //열었던 파일을 닫아줌

	printf("\n정렬 결과 : "); //최종적으로 정렬된 결과 출력
	for (t = 0; t < size; t++) {
		printf(" %2d ", list[t]);
	}
	printf("\n비교 횟수 : %d\t교환 횟수 : %d\n", compareCount, swapCount);
	//값들을 비교한 횟수와 값의 위치를 바꾼 횟수를 출력
	compareCount = 0; //전역변수 초기화
	swapCount = 0;

	getchar();
}