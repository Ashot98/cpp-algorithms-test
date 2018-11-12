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

// ==================== Node Class ====================
struct Node {
	int data;
	Node *left, *right;

	Node() { data = 0; left = right = nullptr; }
	Node(int val) { data = val; left = right = nullptr; }
};

// ==================== Test Function ====================
void runTest();

// ==================== Sorting Functions ====================
void bubbleSort(int *, int);
void insertionSort(int *, int);
void mergeSort(int *, int, int);
void heapSort(int *, int);
void bstSort(int *, int);
void countingSort(int *, int, int);
void radixSort(int *, int, int);

// ==================== Helper Functions ====================
void swap(int &, int &);
void merge(int *, int, int, int);
int getParent(int);
int getLeftChild(int);
int getRightChild(int);
void shiftUp(int *, int);
void shiftDown(int *, int, int);
int extractMin(int *, int);
void addToTree(Node *, int);
void fillSorted(int *, Node *);

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
	cout << "Bubble Sort Runtime: " << endTime - startTime << endl << endl;
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
	cout << "Insertion Sort Runtime: " << endTime - startTime << endl << endl;
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
	cout << "Merge Sort Runtime: " << endTime - startTime << endl << endl;
	/*cout << "Merge Sort Result: " << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << testingArr[i] << ' ';
		if ((i + 1) % 10 == 0) cout << endl;
	}*/

	// ==================== Heap Sort ====================
	for (int i = 0; i < SIZE; ++i) {
		testingArr[i] = inputArr[i];
	}
	cout << "Starting Heap Sort" << endl;
	startTime = clock();
	heapSort(testingArr, SIZE);
	endTime = clock();
	cout << "Heap Sort Runtime: " << endTime - startTime << endl << endl;
	/*cout << "Heap Sort Result: " << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << testingArr[i] << ' ';
		if ((i + 1) % 10 == 0) cout << endl;
	}*/

	// ==================== BST Sort ====================
	for (int i = 0; i < SIZE; ++i) {
		testingArr[i] = inputArr[i];
	}
	cout << "Starting BST Sort" << endl;
	startTime = clock();
	bstSort(testingArr, SIZE);
	endTime = clock();
	cout << "BST Sort Runtime: " << endTime - startTime << endl << endl;
	/*cout << "BST Sort Result: " << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << testingArr[i] << ' ';
		if ((i + 1) % 10 == 0) cout << endl;
	}*/

	// ==================== Counting Sort ====================
	for (int i = 0; i < SIZE; ++i) {
		testingArr[i] = inputArr[i];
	}
	cout << "Starting Counting Sort" << endl;
	startTime = clock();
	countingSort(testingArr, SIZE, RANGE);
	endTime = clock();
	cout << "Counting Sort Runtime: " << endTime - startTime << endl << endl;
	/*cout << "Counting Sort Result: " << endl;
	for (int i = 0; i < SIZE; ++i) {
	cout << testingArr[i] << ' ';
	if ((i + 1) % 10 == 0) cout << endl;
	}*/

	// ==================== Radix Sort ====================
	for (int i = 0; i < SIZE; ++i) {
		testingArr[i] = inputArr[i];
	}
	cout << "Starting Radix Sort" << endl;
	startTime = clock();
	radixSort(testingArr, SIZE, RANGE);
	endTime = clock();
	cout << "Radix Sort Runtime: " << endTime - startTime << endl << endl;
	cout << "Radix Sort Result: " << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << testingArr[i] << ' ';
		if ((i + 1) % 10 == 0) cout << endl;
	}
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

void heapSort(int *arr, int size) {
	int *heapArr = new int[size];

	for (int i = 0; i < size; ++i) {
		heapArr[i] = arr[i];
		shiftUp(heapArr, i);
	}

	for (int i = 0; i < size; ++i) {
		arr[i] = extractMin(heapArr, size - i);
	}
}

void bstSort(int *arr, int size) {
	Node *root = new Node(arr[0]);

	for (int i = 1; i < size; ++i) {
		addToTree(root, arr[i]);
	}

	
	fillSorted(arr, root);
}

void countingSort(int *arr, int size, int maxElem) {
	int *counts = new int[maxElem];
	for (int i = 0; i < maxElem; ++i) {
		counts[i] = 0;
	}

	for (int i = 0; i < size; ++i) {
		++counts[arr[i]];
	}

	int index = 0;
	for (int i = 0; i < maxElem; ++i) {
		for (int j = 0; j < counts[i]; ++j) {
			arr[index++] = i;
		}
	}
}

void radixSort(int *arr, int size, int maxElem) {
	for (int i = 1; maxElem / i > 0; i *= 10) {
		int counts[10] = { 0 };

		for (int j = 0; j < size; ++j) {
			++counts[arr[j] / i % 10];
		}

		for (int j = 1; j < 10; ++j) {
			counts[j] += counts[j - 1];
		}

		int *outputArr = new int[size];
		for (int j = size - 1; j >= 0; --j) {
			outputArr[counts[arr[j] / i % 10] - 1] = arr[j];
			--counts[arr[j] / i % 10];
		}

		for (int j = 0; j < size; ++j) {
			arr[j] = outputArr[j];
		}
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

int getParent(int index) {
	return (index + 1) / 2 - 1;
}

int getLeftChild(int index) {
	return 2 * (index + 1 ) - 1;
}

int getRightChild(int index) {
	return 2 *(index + 1);
}

void shiftUp(int *heap, int i) {
	if (i == 0) return;

	int parentIndex = getParent(i);

	if (heap[parentIndex] > heap[i]) {
		swap(heap[parentIndex], heap[i]);
		shiftUp(heap, parentIndex);
	}
}

void shiftDown(int *heap, int i, int size) {
	int leftChildIndex = getLeftChild(i);
	int rightChildIndex = getRightChild(i);

	if (leftChildIndex < size && rightChildIndex < size) {
		int minIndex = (heap[leftChildIndex] < heap[rightChildIndex]) ? leftChildIndex : rightChildIndex;
		if (heap[i] > heap[minIndex]) {
			swap(heap[i], heap[minIndex]);
			shiftDown(heap, minIndex, size);
		}
	}
	else if (leftChildIndex < size && heap[i] > heap[leftChildIndex]) {
		swap(heap[i], heap[leftChildIndex]);
	}
	else if (rightChildIndex < size && heap[i] > heap[rightChildIndex]) {
		swap(heap[i], heap[rightChildIndex]);
	}
}

int extractMin(int *heap, int size) {
	swap(heap[0], heap[size - 1]);
	shiftDown(heap, 0, size - 1);

	return heap[size - 1];
}

void addToTree(Node *node, int value) {
	if (value < node->data) {
		if (node->left != nullptr) {
			addToTree(node->left, value);
		}
		else {
			node->left = new Node(value);
		}
	}
	else {
		if (node->right != nullptr) {
			addToTree(node->right, value);
		}
		else {
			node->right = new Node(value);
		}
	}
}

void fillSorted(int *arr, Node *node) {
	static int index = 0;

	if (node->left != nullptr) {
		fillSorted(arr, node->left);
	}
	arr[index++] = node->data;
	if (node->right != nullptr) {
		fillSorted(arr, node->right);
	}
}