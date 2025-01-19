#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

// Bubble Sort
void bubbleSort(vector<int> &arr, int &comparisons, int &swaps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &arr, int &comparisons, int &swaps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}

// Insertion Sort
void insertionSort(vector<int> &arr, int &comparisons, int &swaps) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        comparisons++; 
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> array(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    vector<int> bubbleArray = array;
    vector<int> selectionArray = array;
    vector<int> insertionArray = array;

    // Bubble Sort
    int bubbleComparisons = 0, bubbleSwaps = 0;
    auto start = steady_clock::now();
    bubbleSort(bubbleArray, bubbleComparisons, bubbleSwaps);
    auto end = steady_clock::now();
    auto bubbleTime = duration_cast<duration<double, milli>>(end - start).count();

    // Selection Sort
    int selectionComparisons = 0, selectionSwaps = 0;
    start = steady_clock::now();
    selectionSort(selectionArray, selectionComparisons, selectionSwaps);
    end = steady_clock::now();
    auto selectionTime = duration_cast<duration<double, milli>>(end - start).count();

    // Insertion Sort
    int insertionComparisons = 0, insertionSwaps = 0;
    start = steady_clock::now();
    insertionSort(insertionArray, insertionComparisons, insertionSwaps);
    end = steady_clock::now();
    auto insertionTime = duration_cast<duration<double, milli>>(end - start).count();

    // Display Results
cout << "\nSorting Results:\n";
cout << left << setw(15) << "Algorithm"
     << setw(15) << "Time (ms)"
     << setw(15) << "Comparisons"
     << setw(15) << "Swaps" << endl;

cout << left << setw(15) << "Bubble Sort"
     << defaultfloat
     << setw(15) << bubbleTime
     << setw(15) << bubbleComparisons
     << setw(15) << bubbleSwaps << endl;

cout << left << setw(15) << "Selection Sort"
     << defaultfloat
     << setw(15) << selectionTime
     << setw(15) << selectionComparisons
     << setw(15) << selectionSwaps << endl;

cout << left << setw(15) << "Insertion Sort"
     << defaultfloat
     << setw(15) << insertionTime
     << setw(15) << insertionComparisons
     << setw(15) << insertionSwaps << endl;


    return 0;
}

