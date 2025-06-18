#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool findDuplicate(vector<int>& input) {
  set<int> temp;
  for (auto it : input) {
    temp.emplace(it);
  }
  if (temp.size() < input.size()) {
    return true;
  }
  return false;
}

int findMissingNumberInTheSequence(vector<int>& input) {
  //std::sort(input.begin(), input.end());
  //auto count = 0;
  //for (auto i : input) {
  //  if (count != i) {
  //    return count;
  //  }
  //  count++;
  //}
  //return count;

  auto expectedSum = (input.size() + 1) * input.size() / 2;
  auto actualSum{ 0 };
  for (int i : input) {
    actualSum += i;
  }
  return expectedSum - actualSum;
}

int main()
{
  // Find Duplicate in a array
  vector<int> input = { 3, 1, 2, 0 };
  cout << "Are duplicate present: " << findDuplicate(input) << endl;
  cout << "Missing number is: " << findMissingNumberInTheSequence(input) << endl;
  for (auto i : input) {
    cout << i << " ";
  }
  cout << endl;
}

