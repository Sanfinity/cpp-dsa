#include<iostream>
#include<stack>
#include<sstream>
#include<vector>

using namespace std;

// User defined functions
bool isBalanced(string inputString);
int evaluatePostfix(string expr);
string convertInfixToPostfix(string infix);
string convertPrefixToInfix(string expr);
bool isOperator(char ch);
void reverseStack(stack<int>& s);
void calculateSpan(int A[], int n, int S[]);
int largestRectangleArea(vector<int>& heights);

template <typename T>
class Node {
public:
    Node<T>* next;
    T data;
    Node(T value) : next(nullptr), data(value) {}
};

template <typename T>
class DynamicStack {
private:
    Node<T>* top;
    int size;
    stack<T> minStack;

public:
    DynamicStack() {
        top = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(T data) {
        if (minStack.empty() || data < minStack.top()) {
            minStack.push(data);
        }
        Node<T>* newNode = new Node<T>(data);
        if (!top) {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
        size++;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!";
            return -1;
        }
        if (minStack.top() == top->data) {
            minStack.pop();
        }
        auto deleteNode = top;
        auto value = top->data;
        top = top->next;
        delete deleteNode;
        size--;
        return value;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack Underflow!";
            return -1;
        }
        return top->data;
    }

    int getSize() {
        return size;
    }

    T GetMinimum() {
        return minStack.top();
    }
};


// Question: How stacks can be used in checking balancing of symbols?
// Solution: Using Stacks to Check Balanced Symbols (Parentheses, Braces, Brackets)
void problem1() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
}

bool isBalanced(string inputString) {
    DynamicStack<char> s;
    for (char ch : inputString) {
        if (ch == '{' || ch == '[' || ch == '(') {
            s.push(ch);
        }
        else if (ch == '}' || ch == ']' || ch == ')') {
            if (s.isEmpty()) return false;
            auto top = s.peek();
            if ((ch == '}' && top == '{') ||
                (ch == ']' && top == '[') ||
                (ch == ')' && top == '(')) {
                s.pop();
            }
            else {
                return false;
            }
        }
    }
    return s.isEmpty();
}

// Question: Evaluating Postfix Expression Using Stack
// Solution: Using simple stack
void problem2() {
    string expr = "5 3 + 8 2 - *";
    cout << "Result: " << evaluatePostfix(expr) << endl;
}

int evaluatePostfix(string expr) {
    stack<int> s;
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            s.push(stoi(token));
        }
        else {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            switch (token[0]) {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            }
        }
    }
    return s.top();
}

// Question: Convert Infix Expression to Postfix Expression Using Stack
// Solution: Using simple stack
void problem3() {
    //string infix = "(A+B)*C";
    string infix = "(A+B)*C+(D*E)*F+G-H/J";
    cout << "Postfix: " << convertInfixToPostfix(infix) << endl;
}

int precedence(char inputOoperator) {
    switch (inputOoperator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

string convertInfixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Question: Prefix to Infix Conversion
// Solution: using simple stack (https://www.geeksforgeeks.org/prefix-infix-conversion/?ref=lbp)
void problem4() {
    string pre_exp = "*-A/BC-/AKL";
    cout << "Infix : " << convertPrefixToInfix(pre_exp) << endl;
}

string convertPrefixToInfix(string expr) {
    stack<string> s;
    auto length = expr.size();

    for (auto i = length - 1; i >= 0; i--) {
        if (isOperator(expr[i])) {
            string val1 = s.top(); s.pop();
            string val2 = s.top(); s.pop();
            string newExpr = "(" + val1 + expr[i] + val2 + ")"; // Prefix to postfix is same expect expr is at end = op1 + op2 + pre_exp[i];
            s.push(newExpr);
        }
        else {
            s.push(string(1, expr[i]));
        }
    }

    return s.top();
}

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' || ch == '^') {
        return true;
    }
    return false;
}

// Question: How to design a stack such that GetMinimum() should be O(1)
// Solution: Using simple stack
void problem5() {
    DynamicStack<int> s;
    s.push(4);
    s.push(7);
    cout << "Minimum value is " << s.GetMinimum() << endl;
    s.push(2);
    cout << "Minimum value is " << s.GetMinimum() << endl;
    s.pop();
    cout << "Minimum value is " << s.GetMinimum() << endl;
    s.push(6);
    s.push(5);
    s.push(3);
    cout << "Minimum value is " << s.GetMinimum() << endl;
    s.push(1);
    cout << "Minimum value is " << s.GetMinimum() << endl;
}

// Question: Given an array of characters formed with a's and b's. 
// The string is marked with character X which represents the middle 
// of the list (eg. ababaaXaababa).Check whether the string is a palindrome.
// Solution: Using simple stack
void problem6() {
    string expression = "aababaabaXabaababaaa";
    stack<char> s;
    bool foundX = false;
    for (char ch : expression) {
        if (ch == 'X') {
            foundX = true;
        }
        else if (foundX) {
            if (!s.empty() && s.top() == ch) {
                s.pop();
            }
            else {
                cout << "Given string \"" << expression << "\" is not a palindrome" << endl;
                return;
            }
        }
        else {
            s.push(ch);
        }
    }
    cout << "Given string \"" << expression << "\" is a palindrome" << endl;
}

// Question: Reverse the elements of the stack using only stack operations
// Solution: Using stack and recursion
void problem7() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseStack(s);

    cout << "Reversed Stack (Top to Bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

void insertAtBottom(stack<int>& s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }
    auto topElement = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(topElement);
}

void reverseStack(stack<int>& s)
{
    if (s.empty()) return;
    auto topElement = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, topElement);
}

// Question: Consider an empty stack of integers.
// Let the numbers 1,2,3,4,5,6 be pushed on to the stack in the order they appear from left to right.
// Let S indicate a push and X indicate a pop operation. Find the output of the stack
// Solution: Using simple stack approach
void problem8() {
    string expr = "SSSXXSSXSXXX";
    stack<char> s;
    string output = "";
    char count{ 1 };
    for (char ch : expr) {
        if (ch == 'S') {
            s.push(count++);
        }
        else if (ch == 'X') {
            output += to_string(static_cast<int>(s.top())); // NOTE: Else if I use simple typecast it is outputting the integer as hexadecimal
            s.pop();
        }
    }
    cout << "The output for expression " << expr << " is " << output << endl;
}

// Question: On a given machine, how do you check whether the stack grows up or down.
// Solution: By noting the address of a local variable and comparing it with the top element.
void problem9() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    int a{ 0 }, b{ 0 };
    cout << "The address of local variable a: " << reinterpret_cast<uintptr_t>(&a) << " and b: " << reinterpret_cast<uintptr_t>(&b) << endl;
    if (&b < &a) {
        cout << "The stack grows upwards" << endl;
    }
    else {
        cout << "The stack grows downwards" << endl;
    }
}


// Question: The span problem - stock market. 
// The span of an element A[i] in an array is the maximum number of consecutive elements 
// (including A[i] itself) before it that are less than or equal to A[i].
// Solution: Use a monotonic decreasing stack to efficiently compute spans.
void problem10() {
    int A[] = { 100, 80, 60, 70, 60, 75, 85 };
    int n = sizeof(A) / sizeof(A[0]);
    int S[7];

    calculateSpan(A, n, S);

    // Print the spans
    cout << "Span array: ";
    for (int i = 0; i < n; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}

void calculateSpan(int A[], int n, int S[]) {
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // Pop elements that are smaller than or equal to A[i]
        while (!st.empty() && A[st.top()] <= A[i])
        {
            st.pop();
        }
        S[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
}

// Question: Largest Rectangle in Histogram Problem. 
// Imagine you have bars of different heights placed next to each other, like a skyline. 
// We need to find the largest rectangle that we can draw inside the histogram.
// Solution: We use a stack to efficiently find the width of each possible rectangle.
void problem11() {
    vector<int> heights = { 2, 1, 5, 6, 2, 3 };
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
}

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea{ 0 };
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

/*********************************************************/
/*********************************************************/

int main() {
    cout << "\n###### Start of Program ######\n" << endl;
    problem11();
    cout << "\n######  End of Program  ######\n" << endl;
    return 0;
}

/*********************************************************/
/*********************************************************/