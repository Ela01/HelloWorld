#include <iostream>
#include <vector>

// Given an integer array nums, rotate
// the array to the right by k steps, where k is non-negative.
// Example:
/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

using namespace std;

void rotate(vector<int> &nums, int k)
{

    k %= nums.size();
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.begin(), nums.end());
}
