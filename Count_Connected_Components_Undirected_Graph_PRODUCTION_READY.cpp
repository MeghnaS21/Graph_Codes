#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

// Function to validate the input edge
bool isValidEdge(int sourceNode, int destinationNode, int numNodes) {
    if (sourceNode < 0 || sourceNode >= numNodes || destinationNode < 0 || destinationNode >= numNodes) {
        cerr << "Error: Edge (" << sourceNode << ", " << destinationNode << ") is out of bounds for a graph with " 
             << numNodes << " nodes." << endl;
        return false;
    }
    return true;
}

// BFS Traversal function to explore a component
void bfsTraversal(int startNode, vector<int>& visited, const vector<vector<int>>& adjacencyList) {
    queue<int> nodesQueue;
    visited[startNode] = 1;
    nodesQueue.push(startNode);

    while (!nodesQueue.empty()) {
        int currentNode = nodesQueue.front();
        nodesQueue.pop();

        for (int neighbor : adjacencyList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                nodesQueue.push(neighbor);
            }
        }
    }
}

// Function to count the number of connected components
int countComponents(int numNodes, const vector<vector<int>>& adjacencyList) {
    vector<int> visited(numNodes, 0);
    int componentCount = 0;

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            componentCount++;
            bfsTraversal(i, visited, adjacencyList);
        }
    }
    return componentCount;
}

int main() {
    int numNodes, numEdges;

    // Input the number of nodes
    cout << "Enter the number of nodes: ";
    if (!(cin >> numNodes) || numNodes <= 0) {
        cerr << "Error: The number of nodes must be a positive integer." << endl;
        return -1;
    }

    // Input the number of edges
    cout << "Enter the number of edges: ";
    if (!(cin >> numEdges) || numEdges < 0) {
        cerr << "Error: The number of edges must be a non-negative integer." << endl;
        return -1;
    }

    vector<vector<int>> adjacencyList(numNodes);
    cout << "Enter the edges (source destination) pairs:" << endl;

    for (int i = 0; i < numEdges; i++) {
        int sourceNode, destinationNode;
        if (!(cin >> sourceNode >> destinationNode)) {
            cerr << "Error: Invalid input for edge. Please provide two integers." << endl;
            return -1;
        }

        // Validate edge input
        if (!isValidEdge(sourceNode, destinationNode, numNodes)) {
            return -1;
        }

        // Add the edge to the adjacency list
        adjacencyList[sourceNode].push_back(destinationNode);
        adjacencyList[destinationNode].push_back(sourceNode);
    }

    // Count and print the number of connected components
    try {
        int result = countComponents(numNodes, adjacencyList);
        cout << "Number of connected components: " << result << endl;
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return -1;
    }

    return 0;
}
