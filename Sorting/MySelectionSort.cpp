#include <iostream>

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

int main()
{
    cout << "\n###### START OF PROGRAM ######\n";
    // Sorting
    // Selection Sort: Select minimums and swap it
    // Bubble Sort: Push the element to the last by adjcent swaps
    // Insertion Sort: Take an element & place it in its correct order
    int a[] = { 3,9,2,7,4,6,1 };
    int n = sizeof(a) / sizeof(int);
    //SelectionSort(a, n);
    //BubbleSort(a, n);
    insertionSort(a, n);
    for (auto it : a) {
        cout << it << " ";
    }
    cout << endl;

    cout << "\n###### END OF PROGRAM ######\n";
}
