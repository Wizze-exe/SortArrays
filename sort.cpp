#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

const int sizeArray = 10000;

//Заполнение массива
void fillArray(int list[], int listLength);
void fillArray(double list[], int listLength);

//Бубль сортировка
void bubbleSort(int list[], int listLength);
void bubbleSort(double list[], int listLength);

//Сортировка выбором
int findSmallestPosition(int list[], int startPosition, int listLength);
void selectionSort(int list[], int listLength);

//Сортировка вставками
void insertionSort(int list[], int listLength);

//Быстрая сортировка
int partition(int list[], int start, int pivot);
void quickSort(int list[], int start, int end);
int partition(double list[], int start, int pivot);
void quickSort(double list[], int start, int end);

//Сортировка слиянием
void merge(int list[], int start, int end, int mid);
void mergeSort(int list[], int start, int end);

//Сортировка Шелла
void shellSort(int list[], int listLength);

//Куча
void heapify(int list[], int listLength, int root);
void heapSort(int list[], int listLength);

int main()
{
	int iArray[sizeArray];
	double dArray[sizeArray];

	//Бубль сортировка целочисленного массива:
	fillArray(iArray, sizeArray);
	unsigned int startTime = clock();
	bubbleSort(iArray, sizeArray);
	unsigned int endTime = clock();
	cout << "Time of int bubble sort: " << endTime - startTime << " ms" << endl;

	//Быстрая сортировка целочисленного массива:
	random_shuffle(begin(iArray), end(iArray));
	startTime = clock();
	quickSort(iArray, 0, sizeArray - 1);
	endTime = clock();
	cout << "Time of int quick sort: " << endTime - startTime << " ms" << endl;

	//Сортировка выбором целочисленного массива:
	random_shuffle(begin(iArray), end(iArray));
	startTime = clock();
	selectionSort(iArray, sizeArray);
	endTime = clock();
	cout << "Time of int selection sort: " << endTime - startTime << " ms" << endl;

	//Сортировка вставками целочисленного массива:
	random_shuffle(begin(iArray), end(iArray));
	startTime = clock();
	insertionSort(iArray, sizeArray);
	endTime = clock();
	cout << "Time of int insertion sort: " << endTime - startTime << " ms" << endl;

	//Сортировка слиянием целочисленного массива: 
	random_shuffle(begin(iArray), end(iArray));
	startTime = clock();
	mergeSort(iArray, 0, sizeArray);
	endTime = clock();
	cout << "Time of int merge sort: " << endTime - startTime << " ms" << endl;

	//Сортировка Шелла целочисленного массива:
	random_shuffle(begin(iArray), end(iArray));
	startTime = clock();
	shellSort(iArray, sizeArray);
	endTime = clock();
	cout << "Time of int shell sort: " << endTime - startTime << " ms" << endl;

	//Сортировка кучей целочисленного массива:
	random_shuffle(begin(iArray), end(iArray));
	startTime = clock();
	heapSort(iArray, sizeArray);
	endTime = clock();
	cout << "Time of int heap sort: " << endTime - startTime << " ms" << endl;

	//Бубль сортировка вещественного массива:
	fillArray(dArray, sizeArray);
	startTime = clock();
	bubbleSort(dArray, sizeArray);
	endTime = clock();
	cout << "Time of double bubble sort: " << endTime - startTime << " ms" << endl;

	//Быстрая сортировка вещественного числа:
	random_shuffle(begin(dArray), end(dArray));
	startTime = clock();
	quickSort(dArray, 0, sizeArray - 1);
	endTime = clock();
	cout << "Time of double quick sort: " << endTime - startTime << " ms" << endl;

	//for (double &x : dArray) cout << ' ' << x;

	return 0;
}

void fillArray(int list[], int listLength) {
	srand(time(0));
	for (int i = 0; i < listLength; i++) {
		list[i] = rand() % 10000;
	}
}

void fillArray(double list[], int listLength) {
	srand(time(0));
	for (int i = 0; i < listLength; i++) {
		//list[i] = (double)(rand()) / RAND_MAX + (sizeArray - 0) + 0;
		list[i] = 0 + ((double)rand() / RAND_MAX) * 10000;
	}
}

void bubbleSort(int list[], int listLength) {
	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

void bubbleSort(double list[], int listLength) {
	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

int findSmallestPosition(int list[], int startPosition, int listLength) {
	int smallestPosition = startPosition;

	for (int i = startPosition; i < listLength; i++)
	{
		if (list[i] < list[smallestPosition])
			smallestPosition = i;
	}
	return smallestPosition;
}

void selectionSort(int list[], int listLength) {
	for (int i = 0; i < listLength; i++)
	{
		int smallestPosition = findSmallestPosition(list, i, listLength);
		swap(list[i], list[smallestPosition]);
	}
	return;
}

void insertionSort(int list[], int listLength) {
	for (int i = 1; i < listLength; i++)
	{
		int j = i - 1;
		while (j >= 0 && list[j] > list[j + 1])
		{
			swap(list[j], list[j + 1]);
			j--;
		}
	}
}

int partition(int list[], int start, int pivot) {
	int i = start;
	while (i < pivot)
	{
		if (list[i] > list[pivot] && i == pivot - 1)
		{
			swap(list[i], list[pivot]);
			pivot--;
		}

		else if (list[i] > list[pivot])
		{
			swap(list[pivot - 1], list[pivot]);
			swap(list[i], list[pivot]);
			pivot--;
		}

		else i++;
	}
	return pivot;
}

void quickSort(int list[], int start, int end) {
	if (start < end)
	{
		int pivot = partition(list, start, end);

		quickSort(list, start, pivot - 1);
		quickSort(list, pivot + 1, end);
	}
}

int partition(double list[], int start, int pivot) {
	int i = start;
	while (i < pivot)
	{
		if (list[i] > list[pivot] && i == pivot - 1)
		{
			swap(list[i], list[pivot]);
			pivot--;
		}

		else if (list[i] > list[pivot])
		{
			swap(list[pivot - 1], list[pivot]);
			swap(list[i], list[pivot]);
			pivot--;
		}

		else i++;
	}
	return pivot;
}

void quickSort(double list[], int start, int end) {
	if (start < end)
	{
		int pivot = partition(list, start, end);

		quickSort(list, start, pivot - 1);
		quickSort(list, pivot + 1, end);
	}
}

void mergeSort(int list[], int start, int end) {
	int mid;
	if (start < end) {

		mid = (start + end) / 2;
		mergeSort(list, start, mid);
		mergeSort(list, mid + 1, end);
		merge(list, start, end, mid);
	}
}

void merge(int list[], int start, int end, int mid) {
	int mergedList[sizeArray];
	int i, j, k;
	i = start;
	k = start;
	j = mid + 1;

	while (i <= mid && j <= end) {
		if (list[i] < list[j]) {
			mergedList[k] = list[i];
			k++;
			i++;
		}
		else {
			mergedList[k] = list[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		mergedList[k] = list[i];
		k++;
		i++;
	}

	while (j <= end) {
		mergedList[k] = list[j];
		k++;
		j++;
	}

	for (i = start; i < k; i++) {
		list[i] = mergedList[i];
	}
}

void shellSort(int list[], int listLength) {
	for (int step = listLength / 2; step > 0; step /= 2)
	{
		for (int i = step; i < listLength; i += 1)
		{
			int j = i;
			while (j >= step && list[j - step] > list[i])
			{
				swap(list[j], list[j - step]);
				j -= step;
			}
		}
	}
}

void heapify(int list[], int listLength, int root) {
	int largest = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;

	if (l < listLength && list[l] > list[largest])
		largest = l;

	if (r < listLength && list[r] > list[largest])
		largest = r;

	if (largest != root)
	{
		swap(list[root], list[largest]);
		heapify(list, listLength, largest);
	}
}

void heapSort(int list[], int listLength) {
	for (int i = listLength / 2 - 1; i >= 0; i--)
		heapify(list, listLength, i);

	for (int i = listLength - 1; i >= 0; i--)
	{
		swap(list[0], list[i]);
		heapify(list, i, 0);
	}
}
