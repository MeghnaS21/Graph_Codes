class Solution {
public:
    // Function to find the order of courses based on prerequisites using BFS (Kahn's Algorithm)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList = buildAdjacencyList(numCourses, prerequisites);  // Step 1: Build graph
        vector<int> indegree = calculateIndegree(numCourses, adjList);                // Step 2: Calculate indegree

        return performTopologicalSort(numCourses, adjList, indegree);                 // Step 3: Topological Sort (BFS)
    }

private:
    // Step 1: Build adjacency list from prerequisites
    vector<vector<int>> buildAdjacencyList(int numCourses, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (const auto& prereq : prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
        }
        return adjList;
    }

    // Step 2: Calculate indegree for each course
    vector<int> calculateIndegree(int numCourses, const vector<vector<int>>& adjList) {
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int neighbor : adjList[i]) {
                indegree[neighbor]++;
            }
        }
        return indegree;
    }

    // Step 3: Perform BFS for topological sort and detect if there is a cycle
    vector<int> performTopologicalSort(int numCourses, const vector<vector<int>>& adjList, vector<int>& indegree) {
        queue<int> zeroIndegreeQueue;
        vector<int> topoOrder;

        // Initialize the queue with nodes having zero indegree
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                zeroIndegreeQueue.push(i);
            }
        }

        // BFS for topological sort
        while (!zeroIndegreeQueue.empty()) {
            int course = zeroIndegreeQueue.front();
            zeroIndegreeQueue.pop();
            topoOrder.push_back(course);

            // Process all neighbors and reduce their indegree
            for (int neighbor : adjList[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    zeroIndegreeQueue.push(neighbor);
                }
            }
        }

        // Check if all courses are included in the topological order
        if (topoOrder.size() == numCourses) {
            return topoOrder;  // Valid order found
        } else {
            return {};  // Cycle detected, return empty vector
        }
    }
};
