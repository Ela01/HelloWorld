#include <iostream>
#include <string>
#include <list>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
    void getHead()
    {
        cout << head->value << endl;
    }

    void getTail()
    {
        cout << tail->value << endl;
    }

    void getLength()
    {
        cout << length << endl;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);

        if (length == 0)
        { // or if (head == nullptr)
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    {

        if (length == 0)
        {
            return;
        }
        Node *temp = tail;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        length++;
    }

    void deleteFirst()
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
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }
    Node *get(int index)
    {
        if (index < 0 || index >= length)
        {
            return nullptr;
        }
        Node *temp = head;
        if (index < length / 2)
        {

            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp;
        }
        else
        {
            temp = tail;
            for (int j = length - 1; j > index; j--)
            {
                temp = temp->prev;
            }
            return temp;
        }
    }

    bool set(int index, int value)
    {

        Node *temp = get(index);

        if (temp)
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
        Node *before = get(index - 1);
        Node *after = before->next;

        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;
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
            return deleteLast();
        }
        Node *before = get(index - 1);
        Node *temp = before->next;
        Node *after = temp->next;
        before->next = after;
        after->prev = before;

        //----------------------
        /*
        temp->next->prev = temp->prev;
        temp->prev->next= temp->next;

        */

        delete temp;
        length--;
    }

    bool isPalidrome()
    {
        int i = 0;
        int j = length - 1;
        Node *temp = head;
        Node *end = tail;

        if (length <= 1)
        {
            return;
        }

        while (i < j)
        {
            if (temp->value != end->value)
            {
                cout << "false";

                return false;
            }
            else
            {
                temp = temp->next;
                tail = tail->prev;
                i++;
                j--;
            }
        }
        cout << "true";
        return true;
    }
};

int main()
{
    DoublyLinkedList *mDLL = new DoublyLinkedList(1);

    mDLL->prepend(5);
    mDLL->append(3);
    mDLL->append(3);
    mDLL->append(1);

    mDLL->isPalidrome();

    // mDLL->printList();
}