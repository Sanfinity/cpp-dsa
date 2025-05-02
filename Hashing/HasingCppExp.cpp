#include <iostream>

using namespace std;


int main()
{
    cout << "\n###### START OF PROGRAM ######\n";
    // Hashing => Pre-Storing or Fetching
    // Max array size we can declare within main for int type array is 10^6 & globally is 10^7
    int n = 5;
    int arr[5] = { 1,2,2,6,4 };
    for (int it : arr) {
        cout << it << " ";
    }
    cout << endl;

    // Precompute
    int hash[10] = { 0 };
    for (int i = 0; i < n;i++) {
        hash[arr[i]] += 1;
    }

    // Querying
    int q;
    cin >> q;
    for (int i = 0; i < q;i++) {
        int number;
        cin >> number;
        cout << "Occurances: " << hash[number] << endl;
    }




    cout << "\n###### END OF PROGRAM ######\n";
}
