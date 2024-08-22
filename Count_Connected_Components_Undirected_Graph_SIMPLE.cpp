#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS and mark all nodes in the current component as visited
void bfsTraversal(int startNode, vector<bool>& visited, const vector<vector<int>>& adjacencyList) {
    queue<int> nodesQueue;
    nodesQueue.push(startNode);
    visited[startNode] = true;

    while (!nodesQueue.empty()) {
        int currentNode = nodesQueue.front();
        nodesQueue.pop();

        // Explore all the neighbors of the current node
        for (int neighbor : adjacencyList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                nodesQueue.push(neighbor);
            }
        }
    }
}

// Function to count the number of connected components in the graph
int countConnectedComponents(int numNodes, const vector<vector<int>>& adjacencyList) {
    vector<bool> visited(numNodes, false);
    int componentCount = 0;

    // Iterate over all nodes and start a BFS for each unvisited node
    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {
            ++componentCount;
            bfsTraversal(i, visited, adjacencyList);
        }
    }

    return componentCount;
}

int main() {
    int numNodes, numEdges;

    // Input the number of nodes and edges
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> adjacencyList(numNodes);

    // Input the edges
    cout << "Enter the edges (node1 node2) pairs:" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int node1, node2;
        cin >> node1 >> node2;

        // Add edge to the adjacency list
        adjacencyList[node1].push_back(node2);
        adjacencyList[node2].push_back(node1);
    }

    // Count the number of connected components and print the result
    int componentCount = countConnectedComponents(numNodes, adjacencyList);
    cout << "Number of connected components: " << componentCount << endl;

    return 0;
}
