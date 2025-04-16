#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>

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
    auto it = s.find(6); // returns s.end() as its > size()
    s.erase(2); // erase 2 from the set

    s.count(1); // If 1 in set then true else false
    s.erase(s.find(3));

    auto it = s.lower_bound(2);
    auto it = s.upper_bound(2);

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
    auto it = s.find(6); // returns s.end() as its > size()
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
    auto it = s.find(6); // returns s.end() as its > size()
    s.erase(2); // erase 2 from the set

    s.count(1);
    s.erase(s.find(3));

    // All operations takes O(1) 
    // upper_bound() and lower_bound() functions doesn't work
}

// Needs #include <map>
void explainMap() {
    map<int, int> m;
}

int main()
{
    cout << "\n#### Program Start here ####\n";
    explainSet();

    cout << "\n#### Program Ends here ####\n";
}

