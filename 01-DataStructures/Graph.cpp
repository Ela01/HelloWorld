#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
GRAPHS:

You can use an adjacency matrix or adjacency list to store your Graph (ex.) HOWEVER, adjacency matricies unlike adjacency lists also store values indicating lack of endges, ergo:
A.M. SPACE COMPLEXITY: O(|V^2|), TIME COMPLEXITY (of adding a vertex): O(|V^2|), Adding an Edge: O(1), Removing and edge: O(1), Removing Vertex: O(|V^2|).
A.L. SPACE COMPLEXITY: O(|V|+|E|), TIME COMPLEXITY (of adding a vertex/edge): O(1), Removing and edge: O(1), Finding vertex: O(1), Removing vertex: O(|V|)-> you have to remove all
of the edges associated with the vertex you are removing.

ADJACENCY LIST IS BETTER TO USE - Space and Time Efficient.

 Adjacency Matrix:

  A  B  C  D  E <- Represents 'edges with: '
A
B
C    Fill in weights or 1/0 to show connectivity
D
E
^__ Represents vertices

Adjacency List:

{"Vertex": ["edge with", "edge with"]}
{
"A": ["B", "E"],
"B": ["A", "C"],
"C": ["B", "D"],
"D": ["C", "E"],
"E": ["A", "D"]
}

Unordered Sets are similar to Unordered Maps except that it DOES NOT CONTAIN 'values', IT CONTAINS 'keys'.
Sets have NO DUPLICATES
*/

class Graph
{
private:
    unordered_map<string, unordered_set<string> > adjList;

public:
    // void printGraph()
    // {
    //     // for (auto [vertex, edges] : adjList)
    //     // {
    //     //     cout << vertex << ": [ ";
    //     //     for (auto edge : edges)
    //     //     {
    //     //         cout << edge << " ";
    //     //     }
    //     //     cout << "]" << endl;
    //     // }
    // }

    void printGraph()
    {
        unordered_map<string, unordered_set<string> >::iterator kvPair = adjList.begin();
        while (kvPair != adjList.end())
        {
            cout << kvPair->first << ": [ "; // this prints out the vertex
            unordered_set<string>::iterator edge = kvPair->second.begin();
            while (edge != kvPair->second.end())
            {
                cout << edge->data() << " "; // this prints out edges
                edge++;
            }
            cout << "]" << endl;
            kvPair++;
        }
    }

    bool addVertex(string vertex)
    {
        // If adjacency list count for that vertex equals zero.
        // In other words, this vertex is not already in the adjacency list.

        if (adjList.count(vertex) == 0)
        {
            adjList[vertex];
            return true;
        }
        return false;
    }

    bool addEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }

    bool removeEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }

    bool removeVertex(string vertex)
    {
        if (adjList.count(vertex) == 0)
            return false;
        for (auto otherVertex : adjList.at(vertex))
        {
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }
};

int main()
{
    Graph *myGraph = new Graph();
    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");
    myGraph->addVertex("D");

    myGraph->addEdge("A", "B");
    myGraph->addEdge("A", "C");
    myGraph->addEdge("A", "D");
    myGraph->addEdge("B", "D");
    myGraph->addEdge("C", "D");

    myGraph->removeVertex("D");

    myGraph->printGraph();
}