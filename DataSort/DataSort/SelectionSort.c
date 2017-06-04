#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "DataSort.h"

/*
���� ����
txt ���Ͽ��� ���� �޾� �� �� ���� ��ġ ���� i�� �ε����� select�� ���� ��
i���� ������ ���ұ��� ���ϸ鼭 select�� ���Һ��� ���� ���Ҹ� select�� ����, 
���� ��ġ�� ���ҿ� select�� ���Ҹ� ���� ��ȯ�Ѵ�.
�̷��� �� �ܰ谡 ������ ���� ���� ���¸� ����� ��
���� ��ġ ���� i�� �ε����� 1 ������Ű�� ���� ������ �����Ѵ�.
*/

void selectionSort() {
	int list[100], t;
	int compareCount = 0, swapCount = 0;
	int select, i, j, temp;
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
	for (i = 0; i<size; i++) { //�����ϱ� �� ������ ������ ���
		printf("%d ", list[i]);
	}
	printf("\n");

	printf("\n<<<<<<<<<<���� ���� ����>>>>>>>>>>");
	for (i = 0; i<size - 1; i++) {
		printf("\n%2d�ܰ� -> ", i + 1); //������ �����Ҷ����� ��ȣ�� �ű�
		select = i;
		for (j = i + 1; j<size; j++) {
			++compareCount; //�ѹ� ���� �� ���� 1�� ����
			if (list[select] > list[j]) {
				select = j; //���� select��ġ�� ������ j��ġ�� ���� �۴ٸ� select�� j�� �ٲ�
			}
		}
		if (select != i) { //������ select�� ���� �ٲ�� i���� �޶��� ���
			temp = list[select];
			list[select] = list[i];
			list[i] = temp; //i��ġ�� ���� select��ġ�� ���� ���� ��ȯ�Ѵ�.
			++swapCount; //���� ���� �ٲ� �� ���� 1�� ����
		}
		for (t = 0; t < size; t++) { //���ĵ� ��� ���
			printf("%3d", list[t]);
		}
	}

	fclose(fp); //������ ������ �ݾ���

	printf("\n\n���� ��� : "); //���������� ���ĵ� ��� ���
	for (i = 0; i<size; i++) {
		printf("%d ", list[i]);
	}

	printf("\n�� Ƚ�� : %d \t��ȯ Ƚ�� : %d\n", compareCount, swapCount);
	//������ ���� Ƚ���� ���� ��ġ�� �ٲ� Ƚ���� ���

	return 0;
}