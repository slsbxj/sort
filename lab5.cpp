#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//сортировка выбором
void SearchSort(int mas[], int size) {

	clock_t start_time, end_time;
	double total_time;
	
	start_time = clock();

	for (int i = 0; i < size - 1; i++) {
		int ind = i;
		for (int j = i + 1; j < size; j++) {
			if (mas[j] < mas[ind]) {
				ind = j;
			}
		}
		int el = mas[i];
		mas[i] = mas[ind];
		mas[ind] = el;
	}

	end_time = clock();
	total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

	printf("\nSearch Sort: ");
	for (int i = 0; i < size; i++) {
		printf("%d,", mas[i]);
	}
	printf("\nSearch Sort time: %f seconds", total_time);
}


//сортировка вставками
void InsertionSort(int mas[], int size) {

	clock_t start_time, end_time;
	double total_time;

	start_time = clock();

	for (int i = 1; i < size; i++) {
		int key = mas[i];
		int j = i - 1;
		while (j >= 0 && mas[j] > key){
			mas[j + 1] = mas[j];
			j = j - 1;
		}
		mas[j + 1] = key;
	}

	end_time = clock();
	total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

	printf("\nInsertion Sort: ");
	for (int i = 0; i < size; ++i) {
		printf("%d,", mas[i]);
	}
	printf("\nInsertion Sort time: %f seconds", total_time);
}


//сортировка пузырьком
void BubbleSort(int mas[], int size) {

	clock_t start_time, end_time;
	double total_time;

	start_time = clock();

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (mas[j] > mas[j + 1]) {
				int el = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = el;
			}
		}
	}

	end_time = clock();
	total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

	printf("\nBubble Sort: ");
	for (int i = 0; i < size; ++i) {
		printf("%d,", mas[i]);
	}
	printf("\nBubble Sort time: %f seconds", total_time);
}


int main() {

	int size;
	printf("Print size of massive:");
	scanf_s("%d", &size);
	
	int* mas1 = (int*)malloc(size * sizeof(int));
	int* mas2 = (int*)malloc(size * sizeof(int));
	int* mas3 = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		mas1[i] = mas2[i] = mas3[i] = rand() % 10;
	}
	
	while (true) {
		int userInput;
		printf("\nSwitch the Sort (1. Search; 2. Insertion; 3. Bubble). Print the number of Sort.");
		scanf_s("%d", &userInput);

		if (userInput > 3 || userInput < 1) {
			printf("\nThe operation is wrong.");
		}
		else {
			switch (userInput) {
			case 1:
				for (int i = 0; i < size; i++) {
					printf("%d,", mas1[i]);
				}
				SearchSort(mas1, size);
				break;
			case 2:
				for (int i = 0; i < size; i++) {
					printf("%d,", mas2[i]);
				}
				InsertionSort(mas2, size);
				break;
			case 3:
				for (int i = 0; i < size; i++) {
					printf("%d,", mas3[i]);
				}
				BubbleSort(mas3, size);
				break;
			}

		}
	}
	free(mas1);
	free(mas2);
	free(mas3);
	return 0;
}