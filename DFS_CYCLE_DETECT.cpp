class Solution {
    private: 
    
    bool cycle_detect_dfs(int node, int parent, vector<int> adj[], vector<bool> visited){
        visited[node]=true;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
             if(cycle_detect_dfs(neighbour, node, adj, visited )==true) return true;
            }
            else if(neighbour != parent) return true;
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V, false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycle_detect_dfs(i, -1, adj, visited)==true) return true;
            }
        }
        
        return false;
    }
};
