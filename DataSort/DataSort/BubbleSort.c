#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "DataSort.h"

/*
���� ����
txt ���Ͽ��� ���� �޾� �� �� ���� �ε����� ���� ���� �ε����� ���� ���ϸ�, 
���� ������ ��(i)�� ���� ��(j)���� Ŭ ��� ���� ���� ��ȯ�Ѵ�.
�̸� ������ ���ұ��� �ݺ� �����Ѵ�.
�̷��� �� �ܰ谡 ������ ���� ���� ���¸� ����� �� ���� ������ �����Ѵ�.
*/

void bubbleSort() {
	int list[100], t;
	int compareCount = 0, swapCount = 0;
	int i, j, temp;
	FILE *fp;

	if ((fp = fopen("data.txt", "r")) == NULL) { //���� ���⿡ �������� ��� �Լ� ������ �����Ŵ
		printf("DATA FILE open ERROR !!\7\n");
		exit(-1);
	}
	fscanf(fp, "%d", &size); //�迭�� �� ���� ������ ������ ù ���� size������ ����

	for (t = 0; t<size; t++) {  //������ �ι�° ���� ������ list�迭�� ����
		fscanf(fp, " %2d ", &list[t]);
	}

	printf("������ ���� : ");
	for (i = 0; i<size; i++) { //�����ϱ� �� ������ ������ ���
		printf("%d ", list[i]);
	}
	printf("\n");

	printf("\n<<<<<<<<<<���� ���� ����>>>>>>>>>>");
	for (i = 0; i<size - 1; i++) {
		printf("\n%2d�ܰ� -> ", i + 1); //������ �����Ҷ����� ��ȣ�� �ű�
		for (j = i + 1; j<size; j++) {
			++compareCount; //�ѹ� ���� �� ���� 1�� ����
			if (list[i] > list[j]) { //����Ʈ���� ���� ������ ��(i)�� ���� ��(j)���� Ŭ ���
				temp = list[i];
				list[i] = list[j];
				list[j] = temp; //������ ���� ���� ���� ��ġ�� ���� ��ȯ�Ѵ�
				++swapCount; //���� ���� �ٲ� �� ���� 1�� ����
			}
		}
		for (t = 0; t < size; t++) { //���ĵ� ��� ���
			printf("%3d", list[t]);
		}
	}

	fclose(fp); //������ ������ �ݾ���

	printf("\n\n���� ��� : ");  //���������� ���ĵ� ��� ���
	for (i = 0; i<size; i++) {
		printf("%d ", list[i]);
	}

	printf("\n�� Ƚ�� : %d \t��ȯ Ƚ�� : %d\n", compareCount, swapCount);
	//������ ���� Ƚ���� ���� ��ġ�� �ٲ� Ƚ���� ���

	return 0;
}