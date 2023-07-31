#include <iostream>
#include <string>
#include <list>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value; // if param is 'val', this line would be 'value = val;' However, current code inline is the standard convention.
        next = nullptr;      // don't need to write 'next = nullptr;' because 'next' is not a parameter in this Node function.
    }
};

// some classes like the Linked List class,
// has a written destructor, but the 'Node' class does not.
// So if you don't actually write a destructor for a class, it is the default destructor that will be
// run when you delete an instance of that class.
// To delete the LinkedList ex. LinkedList* myLinkedList = new LinkedList(4);
// Do: delete myLinkedList;
// Problematic: The default destructor will only know how to delete:
// Head & Tail Pointers & the var. length of the LinkedList. remaing nodes will still reside in memory.
class LinkedList
{
    // classes are by default private -> No need for 'private' header, but makes code more readable.
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    ~LinkedList()
    {
        // Head & Tail Pointers & the var. length will be deleted by the default destructor.
        Node *temp = head;
        // while (head != nullptr)
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    void printList()
    {
        Node *temp = head;
        while (temp)
        { // same as 'while(temp != nullptr)'
            // the value of the node the 'temp' is pointing to.
            // So if you have a variable that is pointing to a node, you have access to the attributes and that node
            //  (the attributes are 'value' and 'next').
            cout << temp->value << endl;
            temp = temp->next; // loops till temp = nullptr
        }
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        { // Alternative condition: is head/tail = nullptr
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() // O(n)
    {
        if (length == 0)
        {
            return;
        }
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *previous = head;
            while (temp->next)
            {
                previous = temp;
                temp = temp->next;
            }
            tail = previous;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value)
    {

        Node *newNode = new Node(value);

        if (length == 0)
        { // if the LinkedList is empty, set the head and tail pointers to the newNode.
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head; // points the newNode at the first Node where the head pointer is positioned at.
            head = newNode;
        }
        length++;
    }

    void deleteFirst() // O(1)
    {

        // 1-node
        // empty linkedList

        if (length == 0)
        {
            return;
        }
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
    }

    Node *get(int index) // O(n)
    {
        if (index < 0 || index >= length)
        {
            return nullptr;
        }

        Node *temp = head;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value)
    {

        Node *temp = get(index); // checks whether (index < 0 || index >= length).
        if (temp)                // if temp is pointing to a node
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > length)
        {
            return false;
        }
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }

        Node *newNode = new Node(value);
        Node *temp = get(index - 1);

        // Instructions in exercise provide incorrect guidance for the following lines as such:
        // temp->next = newNode->next;
        // newNode = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index >= length)
        {
            return;
        }
        if (index == 0)
        {
            return deleteFirst();
        }
        if (index == length - 1)
        {
            return deleteLast(); // O(n)
        }

        Node *prev = get(index - 1); // get() is O(n)
        Node *temp = prev->next;     // O(1)
        prev->next = temp->next;
        delete temp;
        length--;
    }

    void reverse()
    {
        Node *temp = head;
        head = tail;
        tail = temp;
        Node *after = nullptr;
        Node *before = nullptr;

        for (int i = 0; i < length; ++i)
        {
            after = temp->next;
            temp->next = before; // reverses arrow of node of temp. Now it's pointing to nullptr.
            before = temp;       // the before node is now pointing to same node temp is pointing to.
            temp = after;        // temp is now pointing to the node that after is pointing to.
        }
    }

    // ***LEETCODE***
    Node *findKthFromEnd(int k)
    {
        Node *slow = head;
        Node *fast = head;
        for (int i = 0; i < k; ++i)
        {
            if (fast == nullptr)
            {
                return nullptr;
            }
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    Node *findMiddleNode()
    {
        Node *fast = head;
        Node *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void reverseBetween(int m, int n)
    {
        if (head == nullptr)
        { // length == 0
            return;
        }

        Node *d = new Node(0);

        d->next = head;

        Node *p = d;

        for (int i = 0; i < m; i++)
        {

            p = p->next;
        }

        Node *c = p->next;

        for (int j = 0; j < n - m; j++)
        {

            Node *t = c->next;

            c->next = t->next;

            t->next = p->next;

            p->next = t;
        }

        head = d->next;

        delete d;
    }
};

int main()
{
    // ***TESTING***

    LinkedList *myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);

    myLinkedList->reverseBetween(1, 3);
    myLinkedList->printList();
}