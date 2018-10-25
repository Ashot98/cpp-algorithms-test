#include <iostream>
#include <vector>
#include <time.h>

using std::cout;
using std::endl;
using std::vector;

//==================== Test function ====================
void runTest();

//==================== Sorting functions ====================
void bubbleSort(int *, int);
void insertionSort(int *, int);

//==================== Helper functions ====================
void swap(int &, int &);

int main() {

	runTest();

	system("pause");
	return 0;
}

//==================== Test function ====================
void runTest() {
	srand(time(NULL));
	const int SIZE = 50000;
	const int RANGE = 500000;

	int startTime, endTime;
	int testingArr[SIZE];

	int inputArr[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		inputArr[i] = rand() % RANGE;
	}

	// ==================== Bubble Sort ====================
	for (int i = 0; i < SIZE; ++i) {
		testingArr[i] = inputArr[i];
	}

	cout << "Starting Bubble Sort" << endl;
	startTime = clock();
	//bubbleSort(testingArr, SIZE);
	endTime = clock();
	cout << "Bubble Sort Runtime: " << endTime - startTime << endl;
	/*cout << "Bubble Sort Result: " << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << testingArr[i] << ' ';
		if ((i + 1) % 10 == 0) cout << endl;
	}*/

	// ==================== Insertion Sort ====================
	for (int i = 0; i < SIZE; ++i) {
		testingArr[i] = inputArr[i];
	}
	cout << "Starting Insertion Sort" << endl;
	startTime = clock();
	insertionSort(testingArr, SIZE);
	endTime = clock();
	cout << "Insertion Sort Runtime: " << endTime - startTime << endl;
	/*cout << "Insertion Sort Result: " << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << testingArr[i] << ' ';
		if ((i + 1) % 10 == 0) cout << endl;
	}*/
}

//==================== Sorting functions ====================
void bubbleSort(int *arr, int size) {
	for (int i = 0; i < size - 2; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void insertionSort(int *arr, int size) {
	for (int i = 1; i < size; ++i) {
		int j = i;
		while (j != 0 && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			--j;
		}
	}
}

//==================== Helper functions ====================
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}