#include <iostream>

using namespace std;

// ***RECURSION***
// Recursion -> "A function that calls itself, until it doesn't."
// Rules:
// First, the process of opening each new box is the same or the process of doing whatever it is that
// you're doing has to be the same.
// Second, each time we open a box, we make the problem smaller.
// Third, the 'Base Case' has to be true at some point.
// Fourth, a return statement is required.

/* Pseudocode:

If the gift is a ball, return ball (return true),
If the gift is NOT a ball, the function 'openGiftBox' is called again and again until a 'ball' is produced/returned.
Ball* openGiftBox(){
    if (isBall) return ball;
    openGiftBox(); -> adds another instance of 'openGiftBox' on the 'call stack';
}

Base Case: If the box contains the ball -> you don't want to keep calling new instances of the function here.
Stack Overflow: Without a Base Case here you end up getting an infinite loop of adding new instances of the function to the call stack.
Recursive Case: If the box contains another gift box -> you need to call another instance of the function here.
*/

// ***CALL STACK***
// Call Stack -> Similar to a can of tennis balls -> LIFO: Last In First Out.

int factorial(int num)
{ // num!
    if (num == 1)
        return 1;                    // Base Case
    return num * factorial(num - 1); // Recursive Case
}

// ***BUBBLE SORT***
// Take first item and compare with the second item.
//
// IF (firstItem > secondItem) -> swap(firstItem, secondItem)
// ELSE -> Take second item and compare with the folowing items

// |4|2|6|5|1|3|
//  ^ ^
// |2|4|6|5|1|3|
//    ^ ^
// ...
// |2|4|5|1|3|6|
//            ^-- last item is now sorted.
// Repeat process with current first item, (2 will only need to be compared with items
// till second to last item in list, give that the last item is already marked as sorted.)
// Continue until we have individually compared all items in list to eachother.

void bubbleSort(int a[], int size)
{

    for (int end = size - 1; end > 0; end--)
    {
        for (int begin = 0; begin < end; begin++)
        {
            if (a[begin] > a[begin + 1])
            {
                // swap(a[begin], a[begin + 1]);
                // Swap Funtcion:
                int temp = a[begin];
                a[begin] = a[begin + 1];
                a[begin + 1] = temp;
            }
        }
    }
}

void selectionSort(int b[], int size)
{

    for (int startItr = 0; startItr < size; startItr++)
    {
        int minIndex = startItr;
        for (int nextItr = startItr + 1; nextItr < size; nextItr++)
        {
            if (b[minIndex] > b[nextItr])
            {
                minIndex = nextItr;
            }
        }
        if (startItr != minIndex)
        {
            int temp = b[startItr];
            b[startItr] = b[minIndex];
            b[minIndex] = temp;
        }
    }
}

void insertionSort(int a[], int size)
{
    for (int next = 1; next < size; next++)
    {
        int temp = a[next];
        int prev = next - 1;
        while (prev > -1 && temp < a[prev])
        { // The two conditions in the 'while' statement MUST be written in this order.
            a[prev + 1] = a[prev];
            a[prev] = temp;
            prev--;
        }
    }
}

int main()
{

    int array[] = {6, 4, 2, 5, 1, 3};
    // 'sizeof' function  returns the number of bytes in specified item.
    // Here, we divide the total number of bytes in the array by the number of bytes in an item, giving us the number of items,
    // given the assumption that all elements in the array are of the same type.
    int size = sizeof(array) / sizeof(array[0]);
    insertionSort(array, size);

    for (auto value : array)
    {
        cout << value << " ";
    }
}
