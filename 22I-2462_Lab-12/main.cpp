#include<iostream>
#include<string>
#include "Graph.h"
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    Graph g(n);
    int choice;
    do{
        cout<<"1. Add edge directed"<<endl;
        cout<<"2. Add edge undirected"<<endl;
        cout<<"3. Add vertex with edges"<<endl;
        cout<<"4. Print graph"<<endl;
        cout<<"5. Remove edge"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                int u,v;
                cout<<"Enter the vertices: ";
                cin>>u>>v;
                g.addEdge(u,v);
                break;
            }
            case 2:{
                int u,v;
                cout<<"Enter the vertices: ";
                cin>>u>>v;
                g.addEdgeUndirected(u,v);
                break;
            }
            case 3: {
                int vertex;
                cout << "Enter the vertex: ";
                cin >> vertex;
                int size;
                cout << "Enter the number of edges: ";
                cin >> size;
                int* edges = new int[size];
                cout << "Enter the edges: ";
                for (int i = 0; i < size; i++) {
                    cin >> edges[i];
                }
                g.add_vertex_with_edges(vertex, edges, size);
                delete[] edges; // Free the dynamically allocated memory
                break;
            }
            case 4:{
                g.printGraph();
                break;
            }
            case 5:{
                int u,v;
                cout<<"Enter the vertices: ";
                cin>>u>>v;
                g.removeEdge(u,v);
                break;
            }
            case 6:{
                cout<<"Exiting..."<<endl;
                break;
            }
            default:{
                cout<<"Invalid choice"<<endl;
            }
        }
    }
    while(choice!=6);
    return 0;

}