//Bipartite Graph
//No edge connect vertices of same set

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

    bool isBipartite() {
        queue<int> q;
        vector<bool> vis(V, false);
        vector<int> color(V, -1);

        q.push(0);
        vis[0] = true;
        color[0] = 0;

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();

            list<int> neighbours = l[curr];

            for(int v : neighbours) {
                if(!vis[v]) {
                    vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                } else {
                    if(color[curr] == color[v]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    cout << graph.isBipartite() << endl;

}