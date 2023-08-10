#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int comparisons = 0;

int partition(vector<int>& arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (++comparisons && arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int randomizedQuicksort(vector<int>& arr) {
    comparisons = 0;
    quicksort(arr, 0, arr.size() - 1);
    return comparisons;
}

int main() {
    srand(time(0));
    
    vector<int> arr;
    for(int i = 0 ; i < 1000 ; i++) {
        arr.push_back(i + 1);
    }
    int comparisons = randomizedQuicksort(arr);
    
    cout << "Sorted array:";
    for (int num : arr) {
        cout << " " << num;
    }
    cout << "\nNumber of comparisons: " << comparisons << endl;

    return 0;
}
