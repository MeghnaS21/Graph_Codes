//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>bfs;
        if(V==0 || V==1){
            bfs.push_back(V);
        }
        queue<int> nodesQueue;
        vector<bool>visited(V, false);
        
        nodesQueue.push(0);
        visited[0]=true;
        
        while(!nodesQueue.empty()){
            int currentNode = nodesQueue.front();
            nodesQueue.pop();
            bfs.push_back(currentNode);
            
            for(int neighbor : adj[currentNode]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    nodesQueue.push(neighbor);
                }
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
