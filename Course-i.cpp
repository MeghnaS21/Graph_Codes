#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        // Create adjacency list
        std::vector<std::vector<int>> adj_list(numCourses);
        for (const auto& prerequisite : prerequisites) {
            adj_list[prerequisite[1]].push_back(prerequisite[0]);
        }

        // Calculate indegree
        std::vector<int> indegree(numCourses, 0);
        for (const auto& prerequisite : prerequisites) {
            indegree[prerequisite[0]]++;
        }

        // Initialize queue with nodes having zero indegree
        std::queue<int> tracker;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                tracker.push(i);
            }
        }

        // Topological sort
        int count = 0;
        while (!tracker.empty()) {
            int current_node = tracker.front();
            tracker.pop();
            count++;  // Count how many nodes are processed

            for (int neighbour : adj_list[current_node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    tracker.push(neighbour);
                }
            }
        }

        // If all courses are processed, return true; otherwise, return false (cycle exists)
        return count == numCourses;
    }
};
