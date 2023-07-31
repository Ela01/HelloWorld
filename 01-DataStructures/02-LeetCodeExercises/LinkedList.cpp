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
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
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
    }
    ~LinkedList()
    {
        Node *temp = head;
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
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        return tail;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

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

    bool hasLoop()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
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