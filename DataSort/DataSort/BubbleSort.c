#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "DataSort.h"

/*
버블 정렬
txt 파일에서 값을 받아 온 뒤 현재 인덱스의 값과 다음 인덱스의 값을 비교하며, 
만약 현재의 값(i)이 다음 값(j)보다 클 경우 둘의 값을 교환한다.
이를 마지막 원소까지 반복 수행한다.
이렇게 한 단계가 끝나고 나면 현재 상태를 출력한 뒤 다음 정렬을 수행한다.
*/

void bubbleSort() {
	int list[100], t;
	int compareCount = 0, swapCount = 0;
	int i, j, temp;
	FILE *fp;

	if ((fp = fopen("data.txt", "r")) == NULL) { //파일 열기에 실패했을 경우 함수 실행을 종료시킴
		printf("DATA FILE open ERROR !!\7\n");
		exit(-1);
	}
	fscanf(fp, "%d", &size); //배열에 들어갈 값의 양으로 파일의 첫 값을 size변수에 저장

	for (t = 0; t<size; t++) {  //파일의 두번째 줄의 값들을 list배열에 저장
		fscanf(fp, " %2d ", &list[t]);
	}

	printf("정렬할 원소 : ");
	for (i = 0; i<size; i++) { //정렬하기 전 정렬할 값들을 출력
		printf("%d ", list[i]);
	}
	printf("\n");

	printf("\n<<<<<<<<<<버블 정렬 수행>>>>>>>>>>");
	for (i = 0; i<size - 1; i++) {
		printf("\n%2d단계 -> ", i + 1); //정렬을 시작할때마다 번호를 매김
		for (j = i + 1; j<size; j++) {
			++compareCount; //한번 비교할 때 마다 1씩 증가
			if (list[i] > list[j]) { //리스트에서 만약 현재의 값(i)이 다음 값(j)보다 클 경우
				temp = list[i];
				list[i] = list[j];
				list[j] = temp; //현재의 값과 다음 값의 위치를 서로 교환한다
				++swapCount; //값이 서로 바뀔 때 마다 1씩 증가
			}
		}
		for (t = 0; t < size; t++) { //정렬된 결과 출력
			printf("%3d", list[t]);
		}
	}

	fclose(fp); //열었던 파일을 닫아줌

	printf("\n\n정렬 결과 : ");  //최종적으로 정렬된 결과 출력
	for (i = 0; i<size; i++) {
		printf("%d ", list[i]);
	}

	printf("\n비교 횟수 : %d \t교환 횟수 : %d\n", compareCount, swapCount);
	//값들을 비교한 횟수와 값의 위치를 바꾼 횟수를 출력

	return 0;
}