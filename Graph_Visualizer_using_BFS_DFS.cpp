#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Node structure to represent individuals in the social network
struct Node 
{
    int id;
    vector<int> friends;
};

class SocialNetwork 
{
private:
    vector<Node> graph;
    int numNodes;

public:
    // Constructor to initialize the graph with a given number of nodes
    SocialNetwork(int n) : numNodes(n) 
    {
        graph.resize(n);
        for (int i = 0; i < n; ++i) 
        {
            graph[i].id = i;
        }
    }

    // Function to add an edge between two nodes (individuals)
    void addEdge(int u, int v) {
        graph[u].friends.push_back(v);
        graph[v].friends.push_back(u); // Assuming undirected graph
    }

    // BFS algorithm to find the shortest path between two individuals
    vector<int> bfs(int src, int dest) 
    {
        vector<bool> visited(numNodes, false);
        vector<int> distance(numNodes, -1);
        queue<int> q;

        q.push(src);
        visited[src] = true;
        distance[src] = 0;

        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();

            for (int v : graph[u].friends) 
            {
                if (!visited[v]) 
                {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    q.push(v);
                }
            }
        }

        // Reconstructing the shortest path
        vector<int> shortestPath;
        int u = dest;
        while (u != src) {
            shortestPath.push_back(u);
            for (int v : graph[u].friends) {
                if (distance[v] == distance[u] - 1) {
                    u = v;
                    break;
                }
            }
        }
        shortestPath.push_back(src);

        string reverse(shortestPath.begin(), shortestPath.end());
        return shortestPath;
    }

    // DFS algorithm to check connectivity and identify connected components
    void dfsUtil(int u, vector<bool>& visited) 
    {
        visited[u] = true;
        cout << u << " ";

        for (int v : graph[u].friends) 
        {
            if (!visited[v]) {
                dfsUtil(v, visited);
            }
        }
    }

    void dfs(int src) 
    {
        vector<bool> visited(numNodes, false);
        cout << "Connected components:\n";
        dfsUtil(src, visited);

        // Check if any node remains unvisited (connected components)
        for (int i = 0; i < numNodes; ++i) {
            if (!visited[i]) {
                cout << "\n";
                dfsUtil(i, visited);
            }
        }
    }
};

int main() 
{
    int numNodes, numEdges;
    cout << "Enter the number of individuals in the social network: ";
    cin >> numNodes;

    SocialNetwork network(numNodes);

    cout << "Enter the number of friendships: ";
    cin >> numEdges;

    cout << "Enter friendships (individual IDs):" << endl;
    for (int i = 0; i < numEdges; ++i) 
    {
        int u, v;
        cin >> u >> v;
        network.addEdge(u, v);
    }

    // Query for shortest path between individuals
    int src, dest;
    cout << "Enter source and destination nodes for shortest path: ";
    cin >> src >> dest;

    vector<int> shortestPath = network.bfs(src, dest);
    cout << "Shortest path: ";
    for (int node : shortestPath) 
    {
        cout << node << " ";
    }
    cout << "\n";

    // Query for connectivity and connected components
    int startNode;
    cout << "Enter a node to perform DFS from: ";
    cin >> startNode;
    cout << "DFS traversal:\n";
    network.dfs(startNode);

    return 0;
}
