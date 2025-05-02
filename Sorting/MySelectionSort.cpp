#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int a[],int n){
    for (int i = 0; i <= n-2;i++){
        int mini = i;
        for (int j = i+1; j<= n-1; j++){
            if (a[j]<a[mini]){
                mini = j;
            }
        }
        if (i!=mini){
            swap(a[i], a[mini]);    
        }
    }
}

int main()
{
    cout << "\n###### START OF PROGRAM ######\n";
    // Sorting
    // Selection Sort: Select minimums and swap it
    int a[] = {3,9,2,7,4,6};
    int n = sizeof(a)/sizeof(int);
    SelectionSort(a,n);
    for (auto it: a) {
        cout << it << " ";
    }
    cout << endl;

    cout << "\n###### END OF PROGRAM ######\n";
}#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int a[],int n){
    for (int i = 0; i <= n-2;i++){
        int mini = i;
        for (int j = i+1; j<= n-1; j++){
            if (a[j]<a[mini]){
                mini = j;
            }
        }
        if (i!=mini){
            swap(a[i], a[mini]);    
        }
    }
}

int main()
{
    cout << "\n###### START OF PROGRAM ######\n";
    // Sorting
    // Selection Sort: Select minimums and swap it
    int a[] = {3,9,2,7,4,6};
    int n = sizeof(a)/sizeof(int);
    SelectionSort(a,n);
    for (auto it: a) {
        cout << it << " ";
    }
    cout << endl;

    cout << "\n###### END OF PROGRAM ######\n";
}
