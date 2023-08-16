#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    //   0|1|2|3|4| <-index
    // 2,3,4,5|temp=[1]
    //   3,4,5|temp=[1|2
    //     4,5|temp=[1,2|3
    //       5|temp=[1,2,3|4
    //        |temp=1,2,3,4|5

    int pivot = 0;

    int val = 1;

    int it = 1;

    int product = 0;

    // vector temp: holds excluded values
    vector<int> temp;

    // vector answer holds products
    vector<int> answer;

    while (pivot < nums.size())
    {
        if (pivot == nums.size() - 1)
        {
            val = 1;
            product = accumulate(begin(nums), end(nums) - 1, val, std::multiplies<int>());

            answer.push_back(product);

            for (int i = 0; i < answer.size(); i++)
            {
                cout << answer[i] << endl;
            }

            return answer;
        }
        else
        {
            // pivot       = 0 || 1 || 2 || 3 ||
            // iterator    = 1 || 2 || 3 || 4 ||
            // nums[pivot] = 1 || 2 || 3 || 4 ||
            // temp[pivot] = 1 || 2 || 3 || 4 ||
            temp.push_back(nums[pivot]);
            // nums.erase(begin(nums));
            // val = 1; iterator = 1  || val = 1 * 1; iterator = 2  || val = 1 * 1 * 2; iterator = 3 ||
            // answer[0] = 1(2*3*4*5) ||  answer[1] = 1 * 1(3*4*5)  || answer[2] = 1 * 1 * 2(4*5)    ||
            product = std::accumulate(begin(nums) + it, end(nums), val, std::multiplies<int>());
            answer.push_back(product);

            // temp[0] = 1           || temp[1] = 2               || temp[2] = 3                         || temp[3] = 4
            // val = 1 * temp[0] = 1 || 1 * temp[0] * temp[1] = 2 || 1 * temp[0] * temp[1] * temp[2] = 6 || 1 * temp[0] * temp[1] * temp[2] * temp[3] = 24
            val *= temp[pivot];

            it++;

            // iterator = 1 || 2 || 3 || 4 ||

            // pivot = 1 || 2 || 3 || 4 ||
            pivot++;
        }
    }
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
