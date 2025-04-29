#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsPrime(int n) {
    int count{ 0 };
    for (int i = 1;i * i <= n;i++) {
        if (n % i == 0) {
            count++;
            if (n / i != i) {
                count++;
            }
        }
    }
    if (count == 2) {
        return true;
    }
    return false;
}

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

    // Find whether given number is prime or not -> only two factors which are one and itself
    // O(sqrt(n))
    n = 13;
    cout << n << " is prime: " << IsPrime(n) << endl;

    // GCD | HCF
    // n1 & n2 -> GCD/HCF = largest number that divides both n1 and n2
    int n1 = 9, n2 = 12;

    // O(min(n1,n2)
    for (int i = min(n1, n2); i > 0; i--) {
        if (n1 % i == 0 && n2 % i == 0) {
            cout << "GCD is " << i << endl;
            break;
        }
    }
    // Euclidean Algorithm
    // gcd(a,b) = gcd(a-b,b) where a>b => gcd(a%b,b)
    // O(log(min(n1,n2))
    int a = n1, b = n2;
    while (a > 0 && b > 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0) cout << "GCD is " << b << endl;
    else cout << "GCD is " << a << endl;


    std::cout << "\n###### END OF PROGRAM ######\n";
}
