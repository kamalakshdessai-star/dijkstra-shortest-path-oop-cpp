#include <iostream>
#include <limits>
using namespace std;
const int MAX_NODES = 10;
class BaseGraph {
protected:
    int numNodes;
    int graph[MAX_NODES][MAX_NODES];
public:
    BaseGraph(int n) : numNodes(n) {
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                graph[i][j] = (i == j) ? 0 : INT_MAX;
            }
        }
    }
    virtual void addEdge(int u, int v, int weight) {
        if (u < 0 || u >= numNodes || v < 0 || v >= numNodes) {
            throw out_of_range("Source or destination is out of graph bounds.");
        }
        graph[u][v] = weight;
    }
    virtual ~BaseGraph() {
    }
};
class DijkstraGraph : public BaseGraph {
private:
    int distance[MAX_NODES];
    bool visited[MAX_NODES];
    int parent[MAX_NODES];
public:
    DijkstraGraph(int n) : BaseGraph(n) {
        for (int i = 0; i < numNodes; i++) {
            distance[i] = INT_MAX;
            visited[i] = false;
            parent[i] = -1;
        }
    }
    void addEdge(int u, int v, int weight) override {
        if (weight <= 0) {
            throw invalid_argument("Negative weights are not allowed for Dijkstra's algorithm.");
        }
        BaseGraph::addEdge(u, v, weight);
    }
    void calculateShortestPaths(int src) {
        distance[src] = 0;
        for (int count = 0; count < numNodes - 1; count++) {
            int u = findMinDistanceNode();
            visited[u] = true;
            for (int v = 0; v < numNodes; v++) {
                if (!visited[v] && graph[u][v] != INT_MAX && distance[u] != INT_MAX &&
                    distance[u] + graph[u][v] < distance[v]) {
                    parent[v] = u;
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
    }
    int findMinDistanceNode() {
        int min = INT_MAX, minIndex = -1;
        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && distance[v] < min) {
                min = distance[v];
                minIndex = v;
            }
        }
        return minIndex;
    }
    void printShortestPaths(int src) {
        for (int i = 0; i < numNodes; i++) {
            if (i != src) {
                cout << "Shortest path from " << static_cast<char>('A' + src) << " to "
                     << static_cast<char>('A' + i) << ": A ";
                if (distance[i] == INT_MAX) {
                    cout << "unreachable";
                } else {
                    printPath(i);
                    cout << "Distance: " << distance[i];
                }
                cout << endl;
            }
        }
    }
    void printPath(int j) {
        if (parent[j] == -1) return;
        printPath(parent[j]);
        cout << static_cast<char>('A' + j) << " ";
    }
    ~DijkstraGraph() override {
    }
};
int main() {
    try {
        int n;
        cout << "Enter the number of nodes (max " << MAX_NODES << "): ";
        cin >> n;
        if (n <= 0 || n > MAX_NODES) {
            throw out_of_range("Number of nodes must be between 1 and " + to_string(MAX_NODES));
        }
        DijkstraGraph g(n);
        for (int i = 0; i < n; i++) {
            int edges;
            cout << "Enter the number of edges from " << static_cast<char>('A' + i) << ": ";
            cin >> edges;

            for (int j = 0; j < edges; j++) {
                char dest;
                int dist;
                cout << "Enter destination node and distance (e.g., B 5): ";
                cin >> dest >> dist;
                g.addEdge(i, toupper(dest) - 'A', dist);
            }
        }
        g.calculateShortestPaths(0);
        g.printShortestPaths(0);
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
        return 1;
    }
    return 0;
}

