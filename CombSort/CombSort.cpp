#include "pch.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

void combSort(int arr[], int size)
{
	double fakt = 1.2473309;

	int gap = size;
	bool swapped = true;

	while (gap != 1 || swapped == true)
	{ 
		gap /= fakt;

		if (gap < 1) {
			gap = 1;
		}

		swapped = false;

		for (int i = 0; i < size - gap; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				swap(arr[i], arr[i + gap]);
				swapped = true;
			}
		}
	}
}

int main()
{
	const int size = 10000000;
	int* arr = new int[size];

	ifstream input;
	input.open("input10m.txt");

	for (int i = 0; i < size; i++) {
		input >> arr[i];
	}

	clock_t start = std::clock();

	combSort(arr, size);

	double duration = (std::clock() - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken: " << fixed << duration << " seconds." << endl;

	system("PAUSE");
	return 0;
}


