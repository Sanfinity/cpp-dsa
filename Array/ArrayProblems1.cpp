#include <iostream>
#include <vector>

using namespace std;


int main()
{
    cout << "\n###### START OF PROGRAM ######\n";
    // Array => DS - similar elements
    // Declaring inside main will have garbage values but when declared globally it will be filled with 0s
    // 10^6 is the max size of Array inside main and 10^7 globally
    int n = 5;
    int arr[5] = { 1,2,2,6,4 };
    // Largest element in an array = O(n)
    int max = arr[0];
    for (int i = 1; i < n;i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Largest element is " << max << endl;
    // Second Largest element
    // we can sort and then find the send largest but that'll be like brute force = O(2n)
    auto secLargest = -1;
    for (int i = 0; i < n;i++) {
        if (arr[i] > secLargest && arr[i] != max) {
            secLargest = arr[i];
        }
    }
    cout << "Second largest element is " << secLargest << endl;

    // Optimal method = O(n)
    max = arr[0];
    secLargest = -1;
    for (int i = 1; i < n;i++) {
        if (arr[i] > max) {
            secLargest = max;
            max = arr[i];
        }
        else if (arr[i] > secLargest && arr[i] < max) {
            secLargest = arr[i];
        }
    }
    cout << "Largest element is " << max << endl;
    cout << "Second largest element is " << secLargest << endl;

    // Second smallest element in an array
    vector<int> a = { 1,5,7,2,6,8,10 };
    int smallest = a[0];
    int secSmallest = INT_MAX;
    for (int i = 1; i < a.size();i++) {
        if (a[i] < smallest) {
            secSmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] > smallest && a[i] < secSmallest) {
            secSmallest = a[i];
        }
    }
    cout << "Smallest element is " << smallest << endl;
    cout << "Second Smallest element is " << secSmallest << endl;

    // Check if the array is sorted
    vector<int> b = { 1,2,3,4,4,5,6,7,8 };
    auto temp = b[0];
    auto isSorted = true;
    for (int i = 1; i < b.size(); i++) {
        if (temp > b[i]) {
            isSorted = false;
            break;
        }
        temp = b[i];
    }
    cout << "Is the array sorted: " << isSorted << endl;

    // Remove duplicates


    cout << "\n###### END OF PROGRAM ######\n";
}
