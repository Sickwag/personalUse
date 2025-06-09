#include "Standard_template.cpp"
class test_functions {
public:
    void test_dijkstra() {
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(1, 2, 2);
        g.addEdge(2, 3, 3);
        g.addEdge(0, 3, 10);
        // AlgorithmTools tools;
        AlgorithmTools tools;
        vector<int> dist = tools.dijkstra(g, 0);
        for (int x : dist) {
            cout << x << " ";
        }
        // 期望输出: [0, 1, 3, 6]
    }  
};
int main() {
    test_functions tf;
    tf.test_dijkstra();
}