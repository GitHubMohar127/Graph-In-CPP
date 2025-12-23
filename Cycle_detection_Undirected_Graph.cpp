#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph {
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

    bool isCycleDFS(int src, int parent, vector<bool>& vis){
        vis[src] = true;
        list<int> neighbour = l[src];

        for(int v : neighbour) {
            if(!vis[v]) {
                if(isCycleDFS(v, src, vis)) return true;
            } else if (v != parent) {
                return true;
            }
        }
        return false;
    }

    bool cycleDetection() {
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(isCycleDFS(i, -1, vis)) return true;
            }
        }
        return false;
    }


    bool isCycleUnderBFS(int src, vector<bool>& vis) {
        queue<pair<int, int>> q;

        q.push({src, -1});
        vis[src] = true;

        while(q.size() > 0) {
            int u = q.front().first;
            int parU = q.front().second;

            q.pop();

            list<int> neighbours = l[u];
            for(int v : neighbours){
                if(!vis[v]) {
                    q.push({v, u});
                    vis[v] = true;
                } else if(v != parU) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleBFS(){
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(isCycleUnderBFS(i, vis)) return true;
            }
        }
        return false;
    }
};

int main(){
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);

    // cout<<g.cycleDetection();
    cout<<g.isCycleBFS();
    return 0;

}