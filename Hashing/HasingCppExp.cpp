#include <iostream>
#include <map>
#include <unordered_map>

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
    
    // int q;
    // cin >> q;
    // for (int i = 0; i < q;i++) {
    //     int number;
    //     cin >> number;
    //     cout << "Occurances: " << hash[number] << endl;
    // }
    
    int q[] = {1,2,3,4,5,6};
    for (int it: q) {
        cout << "Occurances of "<< it <<": " << hash[it] << endl;
    }

    cout << endl;
    // Character Hashing
    string inputStr = "abcdabehf";
    for (char ch:inputStr){
        cout << ch << " ";
    }
    cout << endl;
    char queryStr[] = {'a','g','h','b','c'};
    
    // Pre compute
    int hashStr[256] = {0};
    for (char it : inputStr){
        hashStr[it] +=1;
    }
    for (char ch : queryStr) {
        cout << "Occurances of "<< ch << ": " << hashStr[ch] << endl;
    }
    cout << endl;
    // Number hashing = can't use just arrays in hasing as its limit to 10^6
    // So we go with using STL => map or unordered map 
    // map<int,int> to store key value pairs
    n = 7;
    int inputArrMap[] = {1,2,3,1,3,2,12};
    int queryArrMap[] = {1,2,4,3,12};
    // Pre Compute
    unordered_map<int,int> mpp;
    for (int it: inputArrMap){
        mpp[it]++;
    }
    
    for (int it: queryArrMap) {
        cout << "Occurances of "<< it <<": " << mpp[it] << endl;
    }
    cout << endl;
    // Map stores all the values in sorted order
    for (auto it: mpp){
        cout << it.first << " -> " << it.second << endl;
    }
    
    // Time Complexity of Map -> storing/fetching=> O(log(n))
    // Unordered map -> storing/fetching => O(1) very worst case O(n)
    // Hashing -> Division Method, Folding Method, Mid Square Method
    // In DIvision Method we just use arr[i]%10 and then we apply linear chaining in sorted order
    // Collision => if every number ends up in the same hash number then it causes the worst case to fetch and hence O(N) in case of unordered_map
    
    // We can use pair<int,int> as a key in map but in unordered_map we can only have std datatypes

    cout << "\n###### END OF PROGRAM ######\n";
}
