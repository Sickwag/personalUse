#include<unordered_set>
#include<unordered_map>
#include<limits>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
class Graph {
public:
    int vertex;
    vector<vector<pii>> adjacent;// weight, to_point
    Graph(int v) : vertex(v), adjacent(vertex) {};
    void addEdge(int u, int v, int weight) {
        adjacent[u].emplace_back(weight, v);
        adjacent[v].emplace_back(weight, u);
    }
};
class AlgorithmTools {
public:
    /// @brief dijkstra accomplish, if you wanna index start from 0, you should adjust the logic: <br>
    /// 
    /// adjacent[u - 1].emplace_back(weight, v - 1);
    /// pq.emplace(0, source - 1);
    /// dist[source - 1]
    ///
    /// @param graph a Graph obj, check whether the graph is Bidirectional before directly use.
    /// @param source the startpoint
    /// @return a table list of cost from startpoint to otherpoints
    pair<vector<int>, vector<int>> dijkstra(Graph& graph, int source) {
        int v = graph.vertex;
        priority_queue <pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, source);
        vector<int> dist(v, numeric_limits<int>::max()), hops(v, -1);
        dist[source] = 0, hops[source] = 0;
        while (!pq.empty()) {
            int current_dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (current_dist > dist[u]) {
                continue;
            }
            for (auto& edge : graph.adjacent[u]) {
                int weight = edge.first;
                int v = edge.second;
                if (dist[u] + weight < dist[v]) {
                    hops[v] += 1;
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return { dist,hops };
    }
};
class DFS_get_vertex {
public:
    int vertex;
    vector<vector<int>> adjacent;
    vector<bool> visited;
    DFS_get_vertex(int v) : vertex(v), adjacent(v), visited(v, false) {}
 
    void addEdge(int u, int v) {
        adjacent[u].push_back(v);
        adjacent[v].push_back(u); // your graph is Bidirectional
    }
    void dfs(int node) {
        visited[node] = true;
        for (int neighbor : adjacent[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    }
};

class DFS_get_routine_nodes {
public:
    unordered_map<int, vector<int>> adjacent;
    unordered_set<int> visited;
    int dfs(int start, int end) {
        if (start == end) return 1;
        visited.insert(start);
        int minNodes = INT_MAX;
        for (int neighbor : adjacent[start]) {
            if (!visited.contains(neighbor)) {
                int node = dfs(neighbor, end);
                if (node != -1) {
                    minNodes = min(minNodes, node + 1);
                }
            }
        }
        visited.erase(start);
        return minNodes == INT_MAX ? -1 : minNodes;
    }
    int minPathNodes(int start, int end) {
        return dfs(start, end);
    }
};