#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph {
    
    public:
    unordered_map<int , list<int>> adj;

    void addEdge(int u, int v, int direction){
        // if direction = 0 then the graph is Undirected
        // if direcion = 1 then the graph is Directed

        // Creating an edge from u to v
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }

    }

    void printAdjlist(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    } 
    
};



int main(){

    int n;
    cout<<"Enter the number of node: ";
    cin>> n;

    int m;
    cout<<"Enter the number of edge: ";
    cin>>m;

    Graph g;

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u >>v;
        //Creating a Undirected Graph
        g.addEdge(u, v, 0);
    }

    // Printing The adj list
    g.printAdjlist();

    return 0;
}