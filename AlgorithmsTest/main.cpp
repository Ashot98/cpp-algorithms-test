#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using std::cout;
using std::endl;
using std::vector;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

// ==================== Test Function ====================
void runTest();

// ==================== Sorting Functions ====================
void bubbleSort(int *, int);
void insertionSort(int *, int);
void mergeSort(int *, int, int);

// ==================== Helper Functions ====================
void swap(int &, int &);
void merge(int *, int, int, int);

// ==================== MAIN ====================
int main() {

	runTest();

	system("pause");
	return 0;
}

// ==================== Test Function ====================
void runTest() {
	const int SIZE = 50000;
	const int RANGE = 500000;

	random_device rd;
	default_random_engine engine{ rd() };
	uniform_int_distribution<> range(0, RANGE);

	int startTime, endTime;
	int testingArr[SIZE];

	int inputArr[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		inputArr[i] = range(engine);
	}

	// ==================== Bubble Sort ====================
	for (int i = 0; i < SIZE; ++i) {
		testingArr[i] = inputArr[i];
	}

	cout << "Starting Bubble Sort" << endl;
	startTime = clock();
	bubbleSort(testingArr, SIZE);
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

	// ==================== Merge Sort ====================
	for (int i = 0; i < SIZE; ++i) {
		testingArr[i] = inputArr[i];
	}
	cout << "Starting Merge Sort" << endl;
	startTime = clock();
	mergeSort(testingArr, 0, SIZE - 1);
	endTime = clock();
	cout << "Merge Sort Runtime: " << endTime - startTime << endl;
	/*cout << "Merge Sort Result: " << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << testingArr[i] << ' ';
		if ((i + 1) % 10 == 0) cout << endl;
	}*/
}

// ==================== Sorting Functions ====================
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

void mergeSort(int *arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);

		merge(arr, start, mid, end);
	}
}

// ==================== Helper Functions ====================
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void merge(int *arr, int start, int mid, int end) {
	int leftArrSize = mid - start + 1;
	int rightArrSize = end - mid;

	int *leftArr = new int[leftArrSize];
	int *rightArr = new int[rightArrSize];

	for (int i = 0; i < leftArrSize; ++i) {
		leftArr[i] = arr[start + i];
	}
	for (int j = 0; j < rightArrSize; ++j) {
		rightArr[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = start;
	while (i < leftArrSize && j < rightArrSize) {
		if (leftArr[i] < rightArr[j]) {
			arr[k] = leftArr[i];
			++k;
			++i;
		}
		else {
			arr[k] = rightArr[j];
			++k;
			++j;
		}
	}

	while (i < leftArrSize) {
		arr[k] = leftArr[i];
		++k;
		++i;
	}

	while (j < rightArrSize) {
		arr[k] = rightArr[j];
		++k;
		++j;
	}
}