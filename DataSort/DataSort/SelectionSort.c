#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "DataSort.h"

/*
선택 정렬
txt 파일에서 값을 받아 온 뒤 기준 위치 원소 i의 인덱스를 select에 저장 후
i부터 마지막 원소까지 비교하면서 select의 원소보다 작은 원소를 select에 저장, 
기준 위치의 원소와 select의 원소를 서로 교환한다.
이렇게 한 단계가 끝나고 나면 현재 상태를 출력한 뒤
기준 위치 원소 i의 인덱스를 1 증가시키고 다음 정렬을 수행한다.
*/

void selectionSort() {
	int list[100], t;
	int compareCount = 0, swapCount = 0;
	int select, i, j, temp;
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
	for (i = 0; i<size; i++) { //정렬하기 전 정렬할 값들을 출력
		printf("%d ", list[i]);
	}
	printf("\n");

	printf("\n<<<<<<<<<<선택 정렬 수행>>>>>>>>>>");
	for (i = 0; i<size - 1; i++) {
		printf("\n%2d단계 -> ", i + 1); //정렬을 시작할때마다 번호를 매김
		select = i;
		for (j = i + 1; j<size; j++) {
			++compareCount; //한번 비교할 때 마다 1씩 증가
			if (list[select] > list[j]) {
				select = j; //만약 select위치의 값보다 j위치의 값이 작다면 select를 j로 바꿈
			}
		}
		if (select != i) { //위에서 select의 값이 바뀌어 i값과 달라질 경우
			temp = list[select];
			list[select] = list[i];
			list[i] = temp; //i위치의 값과 select위치의 값을 서로 교환한다.
			++swapCount; //값이 서로 바뀔 때 마다 1씩 증가
		}
		for (t = 0; t < size; t++) { //정렬된 결과 출력
			printf("%3d", list[t]);
		}
	}

	fclose(fp); //열었던 파일을 닫아줌

	printf("\n\n정렬 결과 : "); //최종적으로 정렬된 결과 출력
	for (i = 0; i<size; i++) {
		printf("%d ", list[i]);
	}

	printf("\n비교 횟수 : %d \t교환 횟수 : %d\n", compareCount, swapCount);
	//값들을 비교한 횟수와 값의 위치를 바꾼 횟수를 출력

	return 0;
}