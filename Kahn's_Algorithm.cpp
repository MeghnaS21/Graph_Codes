//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  //MISTAKE : Don't get confused with the top of queue and stack
  //to get the top of stack you will use, stack_name.top()
  //but in queue, it is first in first out, so logically you have to extract the front
  //that is using queue_name.front()
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //We will use kahn's algorithm to find the topo sort using bfs
	    //we will be using queue and indegree array
	    int indegree[V]={0};
	    //traverse accross all the neighbours of nodes and calculate the indegree of it
	    for(int i=0;i<V;i++){
	        for(auto neighbour : adj[i]){
	            indegree[neighbour]++;
	        }
	    }
	    
	    //create a queue
	    //push all the nodes with zero indegree
	    queue<int> tracker;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) tracker.push(i);
	    }
	    
	    vector<int>topo_sort;
	    
	    while(!tracker.empty()){
	        
	        int current_node = tracker.front();
	        tracker.pop();
	        //push the poped node into the ans topo_sort
	        topo_sort.push_back(current_node);
	        //traverse the neighbours and reduce the indegree
	        for(auto neighbour : adj[current_node]){
	            indegree[neighbour]--;
	            if(indegree[neighbour]==0) tracker.push(neighbour);
	        }
	    }
	    return topo_sort;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
