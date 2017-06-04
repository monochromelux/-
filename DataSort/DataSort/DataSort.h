#ifndef DATASORT_H //헤더파일 중복 오류를 방지

	int size; //각 파일에서 공통적으로 쓰이는 변수

	void selectionSort(); //선택 정렬에 사용되는 함수

	void bubbleSort(); //버블 정렬에 사용되는 함수

	void quick(int list[], int first, int last); //퀵 정렬에 사용되는 함수들
	void swap(int list[], int i, int j);
	void quickSort();

#endif