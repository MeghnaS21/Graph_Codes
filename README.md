# Graph_Codes
This repository contains, codes for Graphs data structure. Level will be leetcode medium and hard.

By focusing on 
## better error handling, 
## code readability, and efficient use of data structures, you can significantly enhance the quality and robustness of your code. Keep practicing clean coding techniques, and continue refining your approach to edge cases and scalability concerns.

# IMPORTANT THINGS TO NOTE HERE :-

## How can you differentiate between vector<vector<int>> matrix and vector<vector<int>> adjacency_list?
## You’re right in pointing out that `vector<vector<int>>` can look like a matrix, but whether it's a matrix or an **adjacency list** depends on how it’s used.

In the case of a **graph**, the structure `vector<vector<int>> adjList` represents an **adjacency list**, not a matrix. Let’s clarify how:

### Adjacency List vs. Adjacency Matrix

1. **Adjacency List**:  
   In an adjacency list representation, each node (vertex) of the graph points to a list of its neighbors. The `i`-th index of the outer vector represents a node, and the inner vector at index `i` contains the nodes that are adjacent to node `i`.

   - Example for a graph with 4 nodes:
     ```cpp
     vector<vector<int>> adjList = {
         {1, 2},  // Node 0 is connected to nodes 1 and 2
         {0},     // Node 1 is connected to node 0
         {0, 3},  // Node 2 is connected to nodes 0 and 3
         {2}      // Node 3 is connected to node 2
     };
     ```
   Here, the graph looks like:
   ```
   0 - 1
   | 
   2 - 3
   ```

2. **Adjacency Matrix**:  
   In an adjacency matrix, `vector<vector<int>>` would store 0s and 1s (or weights), where a 1 at position `(i, j)` means there’s an edge between node `i` and node `j`.

   - Example for the same graph with 4 nodes:
     ```cpp
     vector<vector<int>> adjMatrix = {
         {0, 1, 1, 0},  // Node 0 is connected to nodes 1 and 2
         {1, 0, 0, 0},  // Node 1 is connected to node 0
         {1, 0, 0, 1},  // Node 2 is connected to nodes 0 and 3
         {0, 0, 1, 0}   // Node 3 is connected to node 2
     };
     ```
   This is a **matrix representation**, where the rows and columns represent the nodes, and the values represent connections.

### Why `vector<vector<int>>` is Used for Adjacency List
The `vector<vector<int>> adjList` structure:
- Each index `i` in the outer vector corresponds to a node.
- Each inner vector at `adjList[i]` holds the nodes adjacent to node `i` (its neighbors).
  
This makes it an **adjacency list**, even though the type `vector<vector<int>>` is also used for matrix representations.

### Why Adjacency List is More Efficient
For **sparse graphs** (few edges compared to nodes), the adjacency list is more space-efficient because you only store edges that exist. An adjacency matrix would consume space even for edges that do not exist (storing zeros).

### Summary
- **Adjacency List**: `vector<vector<int>> adjList` where each node points to its neighbors.
- **Adjacency Matrix**: `vector<vector<int>> adjMatrix` stores connections in a matrix format (0s and 1s).

In the code I provided, `vector<vector<int>> adjList` is indeed an **adjacency list**, even though the type looks like a 2D array.
