#include <iostream>
#include <list>

using namespace std;

// BINARY TREES

// In a full tree every node points to either 0 or 2 nodes.
// With a perfect tree, any level in the tree that has any nodes is completely filled all the way across.
// So with a complete tree, you are filling the tree from left to right with no gaps.
// A node with no children is called a "leaf".

// BST Best->Worst: O(logn)->O(n)

// You cannot have duplicate values in a BST.
// insert faster in linked list O(1), insert is O(n) in BST (both dynamic in size)
// lookup and remove O(n) in list and vector -> faster in BST O(logn)

// An organized tree such that values less than their parents are on the left and more than their parents are placed on the right.
// Adding an item into a BST:
// Omega (best case) and Theta (average case) are both (log n). However, worst case is O(n) and
// Big O measures worst case. Typically Binary Search Trees are treated as O(log n), but technically they are O(n).

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree()
    {
        root = nullptr;
    }

    bool insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        Node *temp = root;
        while (true)
        {
            if (newNode->value == temp->value)
                return false;
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }
    bool contains(int value)
    {
        // if (root == nullptr) unnecessary line
        // return false;
        Node *temp = root;
        while (temp) //  != nullptr
        {
            if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    BinarySearchTree *myBST = new BinarySearchTree();

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);

    cout << "Contains 27: " << myBST->contains(27) << endl;
    cout << "Contains 17: " << myBST->contains(17);
}