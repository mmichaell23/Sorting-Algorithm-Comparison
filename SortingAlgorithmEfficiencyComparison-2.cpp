#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace chrono;

// Quick Sort
int quickSortComparisons = 0;
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            quickSortComparisons++;
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Counting Sort
int countingOperations = 0;
void countingSort(vector<int> &arr) {
    if (arr.empty()) return;
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    vector<int> output(arr.size());

    for (int num : arr) {
        countingOperations++;
        count[num - minVal]++;
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        countingOperations++;
        count[arr[i] - minVal]--;
    }

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}

// Radix Sort
int radixOperations = 0;
void countingSortForRadix(vector<int> &arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; ++i) {
        radixOperations++;
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        radixOperations++;
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int> &arr) {
    if (arr.empty()) return;
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of elements must be greater than 0." << endl;
        return 1;
    }

    vector<int> array(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    vector<int> quickArray = array;
    vector<int> countingArray = array;
    vector<int> radixArray = array;

    // Quick Sort
    auto start = high_resolution_clock::now();
    quickSort(quickArray, 0, n - 1);
    auto end = high_resolution_clock::now();
    auto quickTime = duration_cast<duration<double, milli>>(end - start).count();

    // Counting Sort
    start = high_resolution_clock::now();
    countingSort(countingArray);
    end = high_resolution_clock::now();
    auto countingTime = duration_cast<duration<double, milli>>(end - start).count();

    // Radix Sort
    start = high_resolution_clock::now();
    radixSort(radixArray);
    end = high_resolution_clock::now();
    auto radixTime = duration_cast<duration<double, milli>>(end - start).count();

    // Display Results
    cout << "\nSorting Results:\n";
    cout << left << setw(15) << "Algorithm"
         << setw(15) << "Time (ms)"
         << setw(30) << "Metric" << endl;

    cout << left << setw(15) << "Quick Sort"
         << fixed << setprecision(3)
         << setw(15) << quickTime
         << setw(30) << "Comparisons: " + to_string(quickSortComparisons) << endl;

    cout << left << setw(15) << "Counting Sort"
         << fixed << setprecision(3)
         << setw(15) << countingTime
         << setw(30) << "Operations: " + to_string(countingOperations) << endl;

    cout << left << setw(15) << "Radix Sort"
         << fixed << setprecision(3)
         << setw(15) << radixTime
         << setw(30) << "Operations: " + to_string(radixOperations) << endl;

    return 0;
}
