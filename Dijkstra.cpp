//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // In dijkstra we weill be using min-heap, distance array
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tracker;
        //it will take distance, node
        
        vector<int> dist(V, 1e9);
        
        //mark source as 0 becuase source to source is always 0
        dist[S]=0;
        
        //push it into the heap
        tracker.push({0, S});
        
        //traverse the neighbours, get the top distance and node
        while(!tracker.empty()){
            int current_dist = tracker.top().first;
            int current_node = tracker.top().second;
            
            //pop it
            tracker.pop();
            
            //traverse the neighbours
            for(auto neighbour : adj[current_node]){
                int neighbour_weight = neighbour[1];
                int neighbour_node = neighbour[0];
                if(dist[current_node] + neighbour_weight < dist[neighbour_node]){
                    dist[neighbour_node] = neighbour_weight + dist[current_node];
                    tracker.push({dist[neighbour_node], neighbour_node});
                }
            }
        }
        
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
