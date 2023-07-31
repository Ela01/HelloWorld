#include <iostream>
#include <string>
#include <list>
#include <stack>

using namespace std;

// using a linked list to build stack - LIFO
// nullptr is pointing to the bottom of the stack.

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

// Pushing and Popping from a stack is O(1).
class Stack
{
private:
    Node *top;
    // do not need Node* bottom, since you are only adding and removing from the top.
    int height;

public:
    Stack(int value)
    {
        Node *newNode = new Node(value);
        top = newNode;
        height = 1;
    }
    void printStack()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getTop()
    {
        cout << "Top: " << top->value << endl;
    }

    void getHeight()
    {
        cout << "Height: " << height << endl;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop(int value)
    {

        if (height == 0)
            return INT_MIN;

        Node *temp = top;
        int poppedValue = top->value;
        top = top->next;
        delete temp;
        height--;
        return poppedValue;
    }

    string reverseStr(const string &str)
    {
        int size = str.length();
        string newStr = "";
        Node *pointer = top;
        for (long unsigned int i = 0; i < str.length(); i++)
        {
            newStr += pointer->value;
            pointer = pointer->next;
        }
        cout << newStr << endl;
        return newStr;
    }
    // LEETCODE
    string reverseString(const string &str)
    {
        stack<char> charStack;
        string reversedString;

        for (char c : str)
        {
            charStack.push(c);
        }

        while (!charStack.empty())
        {
            reversedString += charStack.top();
            charStack.pop();
        }

        cout << reversedString;
        return reversedString;
    }
};

// QUEUE FIFO
// Adding and removing from a Queue is O(1).

class Queue
{
private:
    Node *first;
    Node *last;
    int length;

public:
    Queue(int value)
    {
        Node *newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }
    void printQueue()
    {
        Node *temp = first;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getFirst()
    {
        cout << "First: " << first->value << endl;
    }

    void getLast()
    {
        cout << "Last: " << last->value << endl;
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void enqueue(int value)
    {

        Node *newNode = new Node(value);
        if (length == 0)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    int dequeue()
    {
        if (length == 0)
            return INT_MIN;

        Node *temp = first;
        int dequeuedValue = first->value;
        if (length == 1)
        {
            first = nullptr;
            last = nullptr;
        }

        else
        {
            first = first->next;
        }
        delete temp;
        length--;
        return dequeuedValue;
    }
};

int main()
{
    const string &a = "abcdefg";
    string reverseStr(a);

    // Queue *myQueue = new Queue(2);
    // myQueue->enqueue(1);
    // cout << "Dequeued value; " << myQueue->dequeue() << endl;
    // cout << "Dequeued value; " << myQueue->dequeue() << endl;

    // cout << myQueue->dequeue() << endl;
}