#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "DataSort.h" //각각의 Sort코드들을 사용 할 수 있게 하는 헤더파일

void main() {
	int manu;

	printf("1.선택 정렬 | 2.버블 정렬 | 3.퀵 정렬 | 0.종료\n정렬 방법을 선택해주세요 : ");
	scanf("%d", &manu); //항목 선택 
	while (1) { //무한반복
		switch (manu) {
			case 1: // 1을 입력할 경우 선택 정렬 실행
				selectionSort(); //헤더 파일을 통해 SelectionSort.c에 있는 함수인 selectionSort를 불러옴
				break;
			case 2: // 2을 입력할 경우 버블 정렬 실행
				bubbleSort(); //헤더 파일을 통해 BubbleSort.c에 있는 함수인 bubbleSort를 불러옴
				break;
			case 3: // 3을 입력할 경우 퀵 정렬 실행
				quickSort(); //헤더 파일을 통해 QuickSort.c에 있는 함수인 quickSort을 불러옴
				break;
			case 0: // 0을 입력할 경우 프로그램을 종료
				printf("프로그램을 종료합니다.\n");
				return 0;
			default: // 0~3이외의 값을 입력 시 출력됨
				printf("잘못 입력하셨습니다.\n");
				break;
		}
		printf("\n1.선택 정렬 | 2.버블 정렬 | 3.퀵 정렬 | 0.종료\n정렬 방법을 선택해주세요 : ");
		scanf("%d", &manu);
	}
}