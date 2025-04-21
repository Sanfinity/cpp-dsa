#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

// No imports required
void explainPairs() {
    pair<int, int> p = { 1,2 };
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> q = { 1,{2,3} };
    cout << q.first << " " << q.second.first << " " << q.second.second << endl;

    pair<int, int> arr[] = { {1,2}, {2,3}, {3,4} };
    cout << arr[1].second << endl;
}

// Needs #include <vector>
void explainVector() {
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> v2;
    v2.push_back({ 1,2 });
    v2.emplace_back(1, 2);

    vector<int> v5(5, 100); // {100,100,100,100,100}
    vector<int> v3(5); // {0,0,0,0,0}
    vector<int> v4(v);

    vector<int>::iterator it = v.begin();

    it++;
    cout << *(it) << " " << endl;
    vector<int>::iterator it2 = v.end();
    vector<int>::reverse_iterator it3 = v.rend();
    vector<int>::reverse_iterator it4 = v.rbegin();

    cout << v[0] << " " << v.at(0) << endl;
    cout << v.back() << endl;

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;

    v.erase(v.begin()); // delete element at 1st index
    v.erase(v.begin(), v.begin() + 1); // start, end+1

    vector<int> v6(2, 100); // {100,100}
    v6.insert(v6.begin(), 300); // {300,100,100}
    v6.insert(v6.begin() + 1, 2, 10); // {300, 10, 10, 100, 100} (we can use to copy vector)

    cout << "size is " << v6.size() << endl;
    v6.pop_back();
    v.swap(v6);
    v.clear();
    cout << v.empty() << endl;

}

// Needs #include <list>
void explainList() {
    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(3);
    ls.emplace_front(4);

    for (auto it : ls) {
        cout << it << " ";
    }
    cout << endl;

    // Insert in vectors is costly but in list its very cheap as it maintains a DLL
    // rest same as vectors
    // begin, end, rbegin, rend, clear, insert, size, swap
}

// Needs #include <deque>
void explainDeque() {
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);
    dq.emplace_front(4);

    for (auto it : dq) {
        cout << it << " ";
    }
    cout << endl;

    dq.pop_back();
    dq.pop_front();

    for (auto it : dq) {
        cout << it << " ";
    }
    cout << endl;


    cout << "back:" << dq.back() << " front: " << dq.front() << endl;
    // rest are same
}

// Needs #include <stack>
void explainStack() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.emplace(6);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << s.size() << endl;
    cout << s.empty() << endl;
    stack<int> s1, s2;
    s1.swap(s2);

    // All operations are O(1) time complexity
}

// Needs #include <queue>
void explainQueue() {
    queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.emplace(6);

    cout << s.back() << " " << s.front() << endl;
    s.pop();
    cout << s.back() << " " << s.front() << endl;

    cout << s.size() << endl;
    cout << s.empty() << endl;

    // All operations are O(1) time complexity
}

// Needs #include <queue>
void explainPQ() {
    // Max Heap
    priority_queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(9);
    s.emplace(6);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << s.size() << endl;
    cout << s.empty() << endl;

    // This is a linear DS inside which a tree DS is maintained

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(2);
    pq2.push(1);
    pq2.push(3);
    pq2.push(5);
    cout << pq2.top() << endl;

    // Push, Pop -> Log(n) | top -> O(1)
}

// Needs #include <set>
void explainSet() {
    set<int> s;
    s.insert(1); // {1}
    s.emplace(2); // {1,2}
    s.emplace(2); // {1,2}
    s.emplace(4); // {1,2,4}
    s.emplace(3); // {1,2,3,4}
    cout << s.size() << endl;

    auto it = s.find(3); // returns a iterator
    it = s.find(6); // returns s.end() as its > size()
    s.erase(2); // erase 2 from the set

    s.count(1); // If 1 in set then true else false
    s.erase(s.find(3));

    it = s.lower_bound(2);
    it = s.upper_bound(2);

    // All operations takes log(n) 
    // Sets are always sorted and unique
}

// Needs #include <set>
void explainMultiSet() {
    // Just sorted but not unique
    multiset<int> s;
    s.insert(1); // {1}
    s.emplace(2); // {1,2}
    s.emplace(2); // {1,2,2}
    s.emplace(4); // {1,2,2,4}
    s.emplace(3); // {1,2,2,3,4}
    cout << s.size() << endl;

    auto it = s.find(3); // returns a iterator
    it = s.find(6); // returns s.end() as its > size()
    s.erase(3); // erase 2 from the set

    auto cnt = s.count(5);
    s.erase(s.find(3));
}

// Needs #include <unordered_set>
void explainUnorderedSet() {
    unordered_set<int> s;
    // Just unique and no order
    s.insert(1); // {1}
    s.emplace(2); // {1,2}
    s.emplace(2); // {1,2}
    s.emplace(4); // {1,2,4}
    s.emplace(3); // {1,2,4,3}
    cout << s.size() << endl;

    auto it = s.find(3); // returns a iterator
    it = s.find(6); // returns s.end() as its > size()
    s.erase(2); // erase 2 from the set

    s.count(1);
    s.erase(s.find(3));

    // All operations takes O(1) 
    // upper_bound() and lower_bound() functions doesn't work
}

// Needs #include <map>
void explainMap() {
    // Key value pairs
    // Map stores unique keys in sorted order
    map<int, int> m;
    m[1] = 2; // Key 1 = value 2
    m.emplace(2, 3);
    m.insert({ 3, 5 });
    cout << m[3] << endl;

    for (auto it : m) {
        cout << it.first << " " << it.second << endl;
    }

    auto it = m.find(3);
    cout << it->second << endl;

    // Multi Map
    // Everything is same except it can store multiple keys and map[key] can't be used
    // Unordered Map
    // Same as set and unordered_set difference
}

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) {
        return true;
    }
    if (p1.second > p2.second) {
        return false;
    }

    if (p1.first > p2.first) {
        return true;
    }
    return false;
}

// Needs #include <algorithm>
void explainExtra() {
    int a[] = { 1,3,6,2,4,8,5 };
    sort(a, a + 4); // start, end+1
    sort(a, a + 4, greater<int>());

    for (auto it : a) {
        cout << it << " " << endl;
    }

    pair<int, int> b[] = { {1,2}, {8,9}, {6,7}, {3,4} };
    sort(b, b + 4, comp);
    for (auto it : b) {
        cout << it.first << "," << it.second << " " << endl;
    }

    // Works only with Gcc/Clang compilers
    //int num = 8;
    //int cnt = __builtin_popcount(num);
    //cout << "Number of set bits in " << num << " is: " << cnt << endl;

    //long long num2 = 231545641651;
    //cnt = __builtin_popcountll(num2);
    //cout << "Number of set bits in " << num2 << " is: " << cnt << endl;

    // This can be used to find different permuatation for a given string
    string s = "123";
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    int maxi = *max_element(a, a + 7);
    cout << "max element is " << maxi << endl;
}

int main()
{
    cout << "\n#### Program Start here ####\n";
    // Change this to get different results accordingly
    explainExtra();

    cout << "\n#### Program Ends here ####\n";
}

