#include <iostream>
#include <vector>

using namespace std;

// assign two pointers at index 0 and 1

// compare pointer 'after - 1' and pointer 'after' at 1

// set conditions for the minimum Candy while (after < ratings.size())

// if:
// #after-1 >= #after
// 5|4|3

// minCandy += 1

//
// # after-1 < after
// 3|4|5

// minCandy += 2

int candy(vector<int> &ratings)
{

    int minCandy = 1;
    int addCandy = 1;
    // cout << minCandy << endl;

    for (int after = 1; after < ratings.size(); after++)
    {

        if (ratings[after - 1] >= ratings[after])
        {
            minCandy += 1;

            cout << "Index [i - 1] >= [i], add 1" << endl;
            cout << minCandy << ":  #1" << endl; // ------------------
            cout << addCandy << ":  #2" << endl; // ----------------------------
        }

        else
        {
            cout << "Index [i - 1] < [i], add 2" << endl;
            minCandy += 2;                       // +=
            cout << minCandy << ":  #3" << endl; // ---------------------------
            cout << addCandy << ":  #4" << endl; // ----------------------------
        }
    }
    if (ratings[0] > ratings[1])
    {
        cout << "Index [0] > [1], add 1" << endl;
        minCandy += addCandy;

        cout << minCandy << ":  #5" << endl; // ----------------------------
        cout << addCandy << ":  #6" << endl; // ----------------------------
    }
    if (ratings[ratings.size() - 2] > ratings[ratings.size() - 1])
    {
        cout << "Index [last - 2] > [last], add 1" << endl;
        minCandy += addCandy;
        cout << minCandy << ":  #7" << endl; // ---------------------
        cout << addCandy << ":  #8" << endl; // ----------------------------
    }
    else
    {
        cout << "Index >= [last - 1], add 0" << endl;
        cout << minCandy << ":  #9" << endl;  // ----------------------------------
        cout << addCandy << ":  #10" << endl; // ----------------------------

        return minCandy;
    }

    cout << minCandy << ":  #11" << endl; // ----------------------------------
    cout << addCandy << ":  #12" << endl; // ----------------------------
    return minCandy;
}

int main()
{

    vector<int> num;

    num.push_back(1);
    num.push_back(3);
    num.push_back(2);
    num.push_back(2);
    num.push_back(1);

    candy(num);

    cout << "[1,3,2,2,1]" << endl;
}
