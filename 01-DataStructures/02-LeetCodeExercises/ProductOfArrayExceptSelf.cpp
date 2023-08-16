#include <iostream>
#include <vector>

using namespace std;

// 238. Product of Array Except Self

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> answer(nums.size(), 1);

    // Calculates the product of all elements before i
    int preProduct = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        // answer = 1|3|12|60|360
        answer[i] *= preProduct;
        preProduct *= nums[i];
    }

    // Calculates the product of all elements after i
    int postProduct = 1;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        // answer = 240   |60    |12     |2     |1
        //          240*1 | 60*3 | 12*12 | 60*2 | 360*1 |
        // answer = 240   |180   |144    |120   |360
        answer[i] *= postProduct;
        postProduct *= nums[i];
    }

    // COUT ANSWER:
    // for (int i = 0; i < answer.size(); i++)
    // {
    //     cout << answer[i] << endl;
    // }

    return answer;
}

int main()
{
    vector<int> testNums;

    testNums.push_back(3);
    testNums.push_back(4);
    testNums.push_back(5);
    testNums.push_back(6);
    testNums.push_back(2);

    productExceptSelf(testNums);

    return 0;
}

//____________________________________________________
// postProduct
// 0,   1,  2,  3,  4
// 3,   4,  5,  6,  2
// x    240
// 3    x  60

// 3    4   x   12
// 3    4   5   x   2

// preProduct

// 0,   1,  2,  3,  4
// 3,   4,  5,  6,  2
//              360 x
//          60  x   2

//      12  x   6   2
// 3    x   5   6   2
//_________________________________________________

// 0|1|2|3|4| <-index
//   4,5,6,2|         |3 - 240
//     5,6,2|        3|4 - 180
//       6,2|      3,4|5 - 144
//         2|  3,4,5,6|2 - 120
//          |3,4,5,6,2|  - 360
// __________________________________________________
