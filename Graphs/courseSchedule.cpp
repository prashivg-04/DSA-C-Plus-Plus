//Course Schedule
//For given courses & their pre-requisities, return if it is possible to finish them or not
//prerequisites[i] = [ai, bi]
//For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.  (v, u)

#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& graph) {
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0; i < graph.size(); i++) {
            int u = graph[i][1];
            int v = graph[i][0];
            if(src == u) {
                if(!vis[v]) {
                    if(isCycle(v, vis, recPath, graph)) {
                        return true;
                    }
                } else {
                    if(recPath[v]) {
                        return true;
                    }
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int V = numCourses;
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(isCycle(i, vis, recPath, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<int>> graph = {{1, 0}, {0, 1}};
    int numCourses = 2;

    Solution s;
    cout << s.canFinish(numCourses, graph) << endl;
}