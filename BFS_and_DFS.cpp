#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // Print the Adj List
    void adjList() {
        for(int i=0; i<V; i++) {
            cout<<i<<": ";
            for(int neigh : l[i]) {
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }

    // Bfs Traversal
    void BFS() {
        queue<int> Q;
        vector<bool> vis(V, false);

        Q.push(0);
        vis[0] = true;

        while(Q.size() > 0) {
            int u = Q.front();
            Q.pop();
            cout<<u<<" ";

            for(int v : l[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout<<endl;
    }

    // DFS Traversal
    void dfsHelper(int u, vector<bool>& Vis) {
        cout<<u<<" ";
        Vis[u] = true;

        for(int v : l[u]) {
            if(!Vis[v]) {
                dfsHelper(v, Vis);
            }
        }
    }
    
    void dfs(){
        int src = 0;
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++){
            if(!vis[i]) {
                dfsHelper(i, vis);
            }
        }

        cout<<endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    // g.addEdge(2,3);
    g.addEdge(2,4);

    cout<<"ADJ List :"<<endl;
    g.adjList();
    cout<<endl;

    cout<<"BFS traversal: "<<endl;
    g.BFS();
    cout<<endl;

    cout<<"DFS Traversal: "<<endl;
    g.dfs();


    return 0;
}