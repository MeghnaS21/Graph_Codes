//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Initial configuration
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> tracker;
        vector<int> visited(V, 0);
        int sum = 0;
        tracker.push({0, 0});
        
        //Prim's algorithm
        while(!tracker.empty()){
            //pick the top & pop it.
            auto it = tracker.top(); //pair with minium weight
            tracker.pop();
            
            //separate them
            int node = it.second;
            int weight = it.first;
            
            if(visited[node]==1) continue;
            visited[node] = 1;
            sum += weight;
                
                //traverse the neighbours
                for(auto neighbour : adj[node]){
                    int current_node = neighbour[0];
                    int current_weight = neighbour[1];
                    
                    if(!visited[current_node])
                       tracker.push({current_weight, current_node});
                }
            
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
