#include <iostream>
using namespace std;

// For dealing with collisions in Hash Tables
// 1) Seperate chaining - Storing more than one item at one address
// 2) Linear Probing (A form of 'open addressing')- If a collision occurs, instead of using the Seperate chaining method, keep moving from one address to another
// until an empty address is found, that address is then used to store the item.
// Here we will be using the seperate chaining method by attaching a linked list to each address to hold the items at that specific memory location.

// Make your address space a prime number. If you have a prime number of addresses, your key value pairs will be distributed
// more randomly, meaning, fewer collisions.

// Hash Function Runtime: O(1), N -> # of key value pairs in the hash table, ***NOT***-> the # of char.'s in the key.
// Even though the keys are of variable length, as N -> infinity, it wouldn't matter if you had a key that was 100-char.'s long, 100 is insignificant if N = 1 million.
// Adding an item to the HashTable is O(1)
// Getting the item's index (provided the key of the item) IS TREATED AS O(1) since it's almost mathematically impossible to get a runtime of O(N) -- (SEE BELOW).
// (Getting the item's index (provided the key of the item) is technically dependent on whether that item is the first of the linked list at that index.
// *** HOWEVER ***, the chances that all items in a hashtable are all located at the same index, ergo, in one linked-list, is Billions : 1).
//
// Searching for the KEY is O(1), NOT Value.
//
// *** EX. INTERVIEW QUESTION ***
// Given two int. vectors, find out whether they have any common #'s -> vect1[1,3,5] , vect2[2, 4, 5].
// Doing this with two for-loops, the Runtime would be O(n^2) -- (A loop within a loop -- SEE BELOW).
//
// bool itemInCommon(vector<int> vect1, vector<int> vect2){
//     for (auto i : vect1){
//         for (auto j : vect2){
//             if (i == j) // Should it not be 'vect1[i] == vect2[j]'???
//                 return true;

//         }
//     }
//     return false;
// }
//  *** HOWEVER *** This is not what the interviewer is looking for (most likely because the Runtime is much slower as the size N of each vector -> infinity).
// SOLVE WITH A HASHTABLE:
// With a for-loop, copy each of the values from the first vector
// into a Hash Table.
// So we'll take that, number one and make it a key and a key value pair.
// make the value true (SEE BELOW).
// {
//     1: true,
//     3: true,
//     5: true,
// }
// Loop through the second vector, compare the int.'s to the keys in the Hash Table (Getting in Hash Tables -> O(1)).
// The Hash Table method's Runtime: O(n) (technically O(2n) -> drop constant), which is more efficient.
//
// CODE BELOW:
//
//
// #include <iostream>
// #include <unordered_map>
// #include <vector>
//
// bool itemInCommon(vector<int> vect1, vector<int> vect2)
// {
//     unordered_map<int, bool> myMap;
//     for (auto i : vect1)
//     {
//         myMap.insert({i, true});
//     }
//     for (auto j : vect2)
//     {
//         if (myMap[j])
//             return true;
//     }
//     return false;
// }

class Node
{
public:
    string key;
    int value;
    Node *next;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable
{
private:
    static const int SIZE = 7; // Naming convention for constant variables is ALL CAPS
    Node *dataMap[SIZE];

public:
    void printTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ":" << endl;
            if (dataMap[i])
            {
                Node *temp = dataMap[i];
                while (temp)
                {
                    cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }
    int hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE; // multiplying by 23 -- makes the results more random. (use prime numbers)
        }
        return hash;
    }

    void set(string key, int value)
    { // For setting a key value pair to your hash table.
        int index = hash(key);
        Node *newNode = new Node(key, value);
        if (dataMap[index] == nullptr)
        {
            dataMap[index] = newNode;
        }
        else
        {
            Node *temp = dataMap[index];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int get(string key)
    // This code works for the two folling conditions:
    // Node for specified key exists at the specified address
    // OR
    // it does not exists at that address.
    {
        int index = hash(key);
        Node *temp = dataMap[index];
        while (temp != nullptr)
        {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return 0;
    }

    vector<string> keys()
    // This function generate a vector with all the keys in the Hash Table.
    {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++)
        {
            Node *temp = dataMap[i];
            while (temp != nullptr)
            {
                allKeys.push_back(temp->key); // Adds the key into the back of the 'allKeys' vector.
                temp = temp->next;
            }
        }
        return allKeys;
    }
};

int main()
{
    HashTable *myHashTable = new HashTable();
    //                (KEY  , VALUE)
    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);
    myHashTable->set("bolts", 40);
    myHashTable->set("paint", 20);

    // Creating a vector of strings called 'myKeys' and setting it equal to 'myHashTable' keys.
    vector<string> myKeys = myHashTable->keys();

    // This for-loop prints out the keys in the 'myKeys' vector.
    for (auto key : myKeys)
    {
        cout << key << " ";
    }

    // myHashTable->set("screws", 140);
    // myHashTable->printTable();
    // cout << "Lumber: " << myHashTable->get("lumber") << endl;
    // cout << "Bolts: " << myHashTable->get("bolts") << endl;
}