class Solution {
 public:
    // Main function to find the order of courses
    vector<int> findOrder(int num_courses, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list = BuildAdjacencyList(num_courses, prerequisites);
        vector<int> indegree = CalculateIndegree(num_courses, adj_list);
        return PerformTopologicalSort(num_courses, adj_list, indegree);
    }

 private:
    vector<vector<int>> BuildAdjacencyList(int num_courses, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(num_courses);
        for (const auto& prereq : prerequisites) {
            adj_list[prereq[1]].push_back(prereq[0]);
        }
        return adj_list;
    }

    vector<int> CalculateIndegree(int num_courses, const vector<vector<int>>& adj_list) {
        vector<int> indegree(num_courses, 0);
        for (int i = 0; i < num_courses; ++i) {
            for (int neighbor : adj_list[i]) {
                ++indegree[neighbor];
            }
        }
        return indegree;
    }

    vector<int> PerformTopologicalSort(int num_courses, const vector<vector<int>>& adj_list, vector<int>& indegree) {
        queue<int> zero_indegree_queue;
        vector<int> topo_order;

        for (int i = 0; i < num_courses; ++i) {
            if (indegree[i] == 0) {
                zero_indegree_queue.push(i);
            }
        }

        while (!zero_indegree_queue.empty()) {
            int course = zero_indegree_queue.front();
            zero_indegree_queue.pop();
            topo_order.push_back(course);

            for (int neighbor : adj_list[course]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0) {
                    zero_indegree_queue.push(neighbor);
                }
            }
        }

        return topo_order.size() == num_courses ? topo_order : vector<int>{};
    }
};
