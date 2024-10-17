//Cycle Detection
//Undirected Graph - DFS

#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<string>
using namespace std;

class Graph {
    int V;
    list<int> * l;      
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];        
    }

    void addEdge(int u, int v) {   //u ---- v
        l[u].push_back(v);
        l[v].push_back(u); 
    }

    void print() {
        for(int u = 0; u < V; u++) {
            list<int> neighbours = l[u];
            cout << u << " : ";
            for(int v : neighbours) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool undirCycleHelper(int src, int par, vector<bool> &vis) {
        vis[src] = true;
        list<int> neighbours = l[src];

        for(int v : neighbours) {
            if(!vis[v]) {
                if(undirCycleHelper(v, src, vis)) {
                    return true;
                }
             } else {
                if(v != par) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycleUndir() {
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);

    cout << graph.isCycleUndir() << endl;
}