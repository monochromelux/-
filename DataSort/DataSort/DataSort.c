#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "DataSort.h" //������ Sort�ڵ���� ��� �� �� �ְ� �ϴ� �������

void main() {
	int manu;

	printf("1.���� ���� | 2.���� ���� | 3.�� ���� | 0.����\n���� ����� �������ּ��� : ");
	scanf("%d", &manu); //�׸� ���� 
	while (1) { //���ѹݺ�
		switch (manu) {
			case 1: // 1�� �Է��� ��� ���� ���� ����
				selectionSort(); //��� ������ ���� SelectionSort.c�� �ִ� �Լ��� selectionSort�� �ҷ���
				break;
			case 2: // 2�� �Է��� ��� ���� ���� ����
				bubbleSort(); //��� ������ ���� BubbleSort.c�� �ִ� �Լ��� bubbleSort�� �ҷ���
				break;
			case 3: // 3�� �Է��� ��� �� ���� ����
				quickSort(); //��� ������ ���� QuickSort.c�� �ִ� �Լ��� quickSort�� �ҷ���
				break;
			case 0: // 0�� �Է��� ��� ���α׷��� ����
				printf("���α׷��� �����մϴ�.\n");
				return 0;
			default: // 0~3�̿��� ���� �Է� �� ��µ�
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
				break;
		}
		printf("\n1.���� ���� | 2.���� ���� | 3.�� ���� | 0.����\n���� ����� �������ּ��� : ");
		scanf("%d", &manu);
	}
}