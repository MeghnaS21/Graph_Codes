//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
    
private:
    bool detect(int source, vector<int> adj[], vector<int>& vis) {
        vis[source] = 1;
        queue<pair<int, int>> tracker;
        tracker.push({source, -1});
        
        while (!tracker.empty()) {
            int current_node = tracker.front().first;
            int parent = tracker.front().second;
            tracker.pop();
            
            for (auto neighbour : adj[current_node]) {
                if (!vis[neighbour]) {
                    vis[neighbour] = 1;
                    tracker.push({neighbour, current_node});
                } 
                else if(neighbour!=parent) return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
         


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
