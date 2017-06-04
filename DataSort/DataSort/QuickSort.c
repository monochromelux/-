#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "DataSort.h"

/*
�� ����
txt ���Ͽ��� ���� �޾� �� �� ���� ��ġ�� first�� i, ������ ��ġ�� last�� j�� �����ϰ�, 
pivot�� ��ġ�� first�� �����Ѵ�.
�ǹ� ���Һ��� ���� ���Ҹ� ã�� ������ �Ǵ� i�� j�� ���� �� ���� j�� ���ҽ�Ų ��
i�� ���ҿ� j�� ���Ҹ� ���� ��ȯ�Ѵ�.
�Ǻ� ���ҿ� j�� ���Ҹ� ���� ��ȯ�� �� ������ ���� ���¸� ����ϸ�, j�� �Ǻ��� Ȯ���� ��ġ�� �ȴ�.
�̷��� �ѷ� �������� �κп� ���� ���� quick�Լ��� ���ȣ���Ѵ�.
*/

int compareCount, swapCount; //���� ���� Ƚ���� ���� ��ġ�� �ٲ� Ƚ���� �����ϴ� ��������

void quick(int list[], int first, int last) {
	int i, j, pivot, t;
	if (first < last) { //���� ��ġ�� ���Ұ� ������ ��ġ�� ���Һ��� Ŭ ���
		printf("\n%2d�ܰ� -> ", (swapCount++) + 1); //������ �����Ҷ����� ��ȣ�� �ű�
		i = first; //i = 0++;
		j = last + 1; //j = size--;
		pivot = list[first]; //�ǹ��� ����Ʈ�� first��° ���ҷ� ����
		printf("first:%d  last:%d\n", first, last); //���� first���� last���� ���
		do {
			while (list[++i] < pivot && i <= last); //list[i]�� ���� �ǹ����� �۰� i�� ���� last���� �۰ų� ���������� i�� ������Ŵ
			while (list[--j]  > pivot && j >= first); //list[j]�� ���� �ǹ����� ũ�� j�� ���� first���� ũ�ų� ���������� j�� ���ҽ�Ŵ
			printf("i:%d  j:%d\n", i, j); //i�� j�� ���� ���
			if (i < j) swap(list, i, j); //i < j�϶� i�� j�� ���� ���� ��ȯ
			compareCount++; //�ѹ� ���� �� ���� 1�� ����
		} while (i < j); //i < j�϶� �ݺ�
		swap(list, first, j); //first�� j�� ���� ���� ��ȯ
		
		list[j] = -list[j]; // ��ġ�� ������ ���Ҹ� ǥ���ϱ� ���� ���� �տ� -�� �ٿ���

		for (t = 0; t < size; t++) { //���ĵ� ��� ���
			printf(" %3d ", list[t]);
		}
		printf(" \n");

		quick(list, first, j - 1); // j�� ���� -1�Ͽ� last������ �����ϰ� �ѹ� �� quick�Լ� ����(��� ȣ��)
		quick(list, j + 1, last); // j�� ���� +1�Ͽ� first������ �����ϰ� �ѹ� �� quick�Լ� ����(��� ȣ��)
	}
	else {   // first = last�� ��� �Լ��� ����
		return;
	}
}
void swap(int list[], int i, int j) { //���� ���� ��ȯ�ϴ� �Լ� swap
	int temp;
	temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

void quickSort() {
	int list[100], t;
	FILE *fp;

	if ((fp = fopen("data.txt", "r")) == NULL) { //���� ���⿡ �������� ��� �Լ� ������ �����Ŵ
		printf("DATA FILE open ERROR !!\7\n");
		exit(-1);
	}
	fscanf(fp, "%d", &size); //�迭�� �� ���� ������ ������ ù ���� size������ ����

	for (t = 0; t<size; t++) { //������ �ι�° ���� ������ list�迭�� ����
		fscanf(fp, " %2d ", &list[t]);
	}

	printf("������ ���� : ");
	for (t = 0; t<size; t++) { //�����ϱ� �� ������ ������ ���
		printf("%d ", list[t]);
	}
	printf("\n");

	printf("\n<<<<<<<<<<�� ���� ����>>>>>>>>>>");
	quick(list, 0, size - 1); //�� ���� �ٽ� �Լ� ����

	fclose(fp); //������ ������ �ݾ���

	printf("\n���� ��� : "); //���������� ���ĵ� ��� ���
	for (t = 0; t < size; t++) {
		printf(" %2d ", list[t]);
	}
	printf("\n�� Ƚ�� : %d\t��ȯ Ƚ�� : %d\n", compareCount, swapCount);
	//������ ���� Ƚ���� ���� ��ġ�� �ٲ� Ƚ���� ���
	compareCount = 0; //�������� �ʱ�ȭ
	swapCount = 0;

	getchar();
}