#include <iostream>
#include <vector>
#include <numeric>

#include <iterator>

using namespace std;

int wtrap(vector<int> &height)
{

    int start = 0;

    int end = height.size() - 1;

    while (height[start] == 0)
    {
        start++;
    }

    // cout << start << endl;

    while (height[end] == 0)
    {
        end--;
    }

    // cout << end << endl;

    int trueLength = end - start + 1;

    cout << "Length: " << trueLength << endl;

    int totalHeights = accumulate(height.begin(), height.end(), 0);

    cout << "totalHeights: " << totalHeights << endl;

    int maxHeight = *max_element(height.begin(), height.end());

    cout << "maxHeight: " << maxHeight << endl;

    int newTotalHeights = maxHeight * trueLength;

    cout << "newTotalHeights: " << newTotalHeights << endl;

    int trappedWater = newTotalHeights - totalHeights;

    // cout << totalHeights << endl;

    // int determineNewHeight = totalHeights / trueLength;

    // if (totalHeights % trueLength > 0)
    // {

    //     determineNewHeight += 1;
    // }

    // cout << "Width: " << determineNewHeight << endl;

    // int newTotalHeights = determineNewHeight * trueLength;

    // cout << "New Total of Blocks: " << newTotalHeights << endl;

    // int trappedWater = newTotalHeights - (determineNewHeight * totalHeights);

    // trappedWater = abs(trappedWater);

    cout << "Trapped Water: " << trappedWater << endl;

    return trappedWater;
}

int trap(vector<int> &height)
{

    // find first building and last building

    int start = 0;
    int end = 1;
    int lengthBtw = 0;
    int block = 0;
    int trappedWater = 0;

    while (height[start] == 0)
    {
        start++;
        cout << "Set Begin start: " << start << endl;
    }

    cout << "Begin start: " << start << endl;

    while (start < height.size())
    {
        while (height[end] == 0)
        {
            end++;
            cout << "End increments to: " << end << endl;
        }

        if (height[end] <= height[start])
        {
            lengthBtw = (end - 1) - (start + 1) + 1;
            block = height[end] * lengthBtw;
            for (int it = start + 1; it < end; it++)
            {
                block -= height[it];
                trappedWater += block;
                cout << "trappedWater: " << trappedWater << endl;
            }
        }

        if (height[end] > height[start])
        {
            lengthBtw = (end - 1) - (start + 1) + 1;
            block = height[start] * lengthBtw;
            for (int it = start + 1; it < end; it++)
            {
                block -= height[it];
                trappedWater += block;
                cout << "trappedWater: " << trappedWater << endl;
            }
        }
        start = end;
        cout << "New start: " << start << endl;
        end = start + 1;
        cout << "New end: " << end << endl;
    }
    cout << "trappedWater: " << trappedWater << endl;
    return trappedWater;

    // int p1 = 0;
    // int p2 = 1;
    // int p3 = 2

    // case 1: if (p1 > 0 && p2 == 0)
    // while (p2 == 0) p2++
    // if p2 < p1
}

int main()
{
    vector<int> num;

    num.push_back(4);
    num.push_back(2);
    num.push_back(0);
    num.push_back(3);
    num.push_back(2);
    num.push_back(5);
    // num.push_back(1);
    // num.push_back(3);
    // num.push_back(2);
    // num.push_back(1);
    // num.push_back(2);
    // num.push_back(1);

    wtrap(num);
}