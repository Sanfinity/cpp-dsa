#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// TC: O(n^2)
void SelectionSort(int a[], int n) {
    for (int i = 0; i <= n - 2;i++) {
        int mini = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (a[j] < a[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            swap(a[i], a[mini]);
        }
    }
}

// TC: O(n^2)
// TC if sorted: O(n)
void BubbleSort(int a[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        bool isSwapped = false;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped) break;
    }
}

// TC: O(n^2)
// Best Case TC: O(n)
void insertionSort(int a[], int n) {
    for (int i = 1; i < n;i++) {
        int j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.emplace_back(arr[left]);
            left++;
        }
        else {
            temp.emplace_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.emplace_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.emplace_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// TC: O(n*log2(n))
// SC: O(n)
void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int qs(int a[], int low, int high) {
    auto pivot = a[low];
    auto i = low;
    auto j = high;

    while (i < j) {
        while (a[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (a[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[j]);
    return j;
}

// TC: O(nlogn)
// SC: O(1)
void QuickSort(int a[], int low, int high) {
    if (low < high) {
        int pivot = qs(a, low, high);
        QuickSort(a, low, pivot - 1);
        QuickSort(a, pivot + 1, high);
    }
}

int main()
{
    cout << "\n###### START OF PROGRAM ######\n";

    // Sorting
    // Selection Sort: Select minimums and swap it
    // Bubble Sort: Push the element to the last by adjcent swaps
    // Insertion Sort: Take an element & place it in its correct order
    // Merge Sort: Divide and conquor method
    // Quick Sort: Pick a pivot & place it in its correct place in the sorted array | Smaller on the left and larger on the right

    int a[] = { 3,9,2,7,4,6,1 };
    int n = sizeof(a) / sizeof(int);
    QuickSort(a, 0, n - 1);
    //SelectionSort(a, n);
    //BubbleSort(a, n);
    //insertionSort(a, n);
    vector<int> arr = { 2,5,8,3,7,4,9,1,6 };
    mergeSort(arr, 0, arr.size() - 1);
    for (auto it : a) {
        cout << it << " ";
    }
    cout << endl;

    cout << "\n###### END OF PROGRAM ######\n";
}
