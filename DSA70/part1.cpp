#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> seen;
    for (auto num : nums) {
        if (seen.count(num)) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

// Given an array nums containing n distinct numbers in the range [0, n], return the one number that is missing from the array.
int missingNumber(const vector<int>& nums) {
    auto n = nums.size();
    auto expectedSum = n * (n + 1) / 2;
    auto actualSum = 0;
    for (auto i : nums) {
        actualSum += i;
    }
    return expectedSum - actualSum;
}

int main()
{
    //vector<int> nums = { 1, 2, 3, 4 };
    vector<int> nums = {3, 0, 1};
    //cout << (containsDuplicate(nums) ? "True" : "False") << endl;
    std::cout << "Missing number: " << missingNumber(nums) << std::endl;
    return 0;
}
