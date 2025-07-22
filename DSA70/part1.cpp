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

// Given an array nums of length n where:
// Each element is in the range [1, n]
// Some elements appear twice, others once
// Find all the numbers in the range [1, n] that do not appear in nums.
// Time: O(n), Space: O(1) (excluding output)
std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        auto index = abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index]; // Mark as visited by negation
        }
    }

    std::vector<int> results;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            results.emplace_back(i + 1);
        }
    }
    return results;
}

int main()
{
    //vector<int> nums = { 1, 2, 3, 4 };
    //cout << (containsDuplicate(nums) ? "True" : "False") << endl;

    //vector<int> nums = {3, 0, 1};
    //std::cout << "Missing number: " << missingNumber(nums) << std::endl;

    std::vector<int> nums = { 4,3,2,7,8,2,3,1 };
    std::vector<int> result = findDisappearedNumbers(nums);

    std::cout << "Missing numbers: ";
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
