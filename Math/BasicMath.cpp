#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintDivisor(int n) {
    for (int i = 1; i < n;i++) {
        if (n % i == 0) {
            cout << i << " is a divisor of " << n << endl;
        }
    }
}

void PrintDivisorOptimized(int n) {
    vector<int> list;
    // O(sqrt(n))
    for (int i = 1; i <= sqrt(n);i++) {
        if (n % i == 0) {
            list.emplace_back(i);
            if (n / i != 1) {
                list.emplace_back(n / i);
            }
        }
    }
    // O(no.of factors * log(no. of factors))
    sort(list.begin(), list.end());
    // O(no. of factors)
    for (auto item : list) {
        cout << item << " ";
    }
    cout << endl;
    // Total complexity is O(sqrt(n)) + O(no.of factors * log(no. of factors)) + O(no. of factors)
    // Which is still better than traversing through all the possibilities if the input is high
}

int main()
{
    std::cout << "\n###### START OF PROGRAM ######\n";

    // Digits

    // Revering a digit
    int n = 1234;
    //int n = 1221;
    int temp = n;
    int rev{ 0 };
    int count{ 0 };
    while (temp > 0) {
        cout << temp % 10 << endl;
        rev = rev * 10 + temp % 10;
        temp = temp / 10;
        count++;
    }
    cout << rev << endl;

    // Count the number of digits
    cout << "count: " << count << endl;
    // Optimized way is to use log10
    cout << "count: " << int(log10(n) + 1) << endl;

    // Palindrom
    if (n == rev) {
        cout << "Given number is a palindrome" << endl;
    }
    // Armstrong number : sum of cube = same number
    n = 153;
    int armstr = 0;
    temp = n;
    while (temp > 0) {
        armstr += (int)pow((temp % 10), 3);
        temp = temp / 10;
    }
    cout << armstr << endl;

    // Print all divisors
    // if i is divisible by O(n)
    n = 36;
    PrintDivisor(n);
    cout << endl;
    // if x is factors of n then n/x is also a factor, so we only need to loop till sqrt(n)
    PrintDivisorOptimized(n);

    std::cout << "\n###### END OF PROGRAM ######\n";
}
