#include <iostream>
#include "node.h"
using namespace std;

class Graph
{
private:
    int n;
    node **adjList;

public:
    Graph(int n)
    {
        this->n = n;
        adjList = new node *[n];
        for (int i = 0; i < n; i++)
        {
            adjList[i] = NULL;
        }
    }
    void addEdge(int u, int v)
    {
        node *newNode = new node;
        newNode->vertex = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }
    void printGraph()
    {
        for (int i = 0; i < n; i++)
        {
            node *temp = adjList[i];
            cout << i << "->";
            while (temp != NULL)
            {
                cout << temp->vertex << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    // add vertex with edges into the adjacency list
    void add_vertex_with_edges(int vertex, int edges[], int size)
    {
        node *newNode = new node;
        newNode->vertex = vertex;
        newNode->next = NULL;
        adjList[vertex] = newNode;
        for (int i = 0; i < size; i++)
        {
            addEdge(vertex, edges[i]);
        }
    }

    // Modify task 3 to implement a function that removes an edge between two vertices.
    void removeEdge(int u, int v)
    {
        node *temp = adjList[u];
        node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->vertex == v)
            {
                if (prev == NULL)
                {
                    adjList[u] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        temp = adjList[v];
        prev = NULL;
        while (temp != NULL)
        {
            if (temp->vertex == u)
            {
                if (prev == NULL)
                {
                    adjList[v] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    void addEdgeUndirected(int u, int v)
    {
        node *newNode = new node;
        newNode->vertex = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;
        newNode = new node;
        newNode->vertex = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
    void weightedGraph(int u, int v, int weight)
    {

        node *newNode = new node;
        newNode->vertex = v;
        newNode->weight = weight;
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }
    // Write a code that prints the graph. The output should be a vertex and all the edges of that vertex.
};