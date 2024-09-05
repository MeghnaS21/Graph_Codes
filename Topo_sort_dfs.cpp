//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    //MISTAKE :- i haven't passed the stack by reference, that's why the code didn't worked
    //so please pass the stack by reference to make sure the changes are reflected back to the stack.
    void check_cycles(int start_node, int visited[], vector<int>adj[], stack<int> &topo_order){
        visited[start_node]=1;
        
        //check for the neighbour/adjacent nodes and call the dfs if univisted
        for(auto neighbour : adj[start_node]){
            if(!visited[neighbour])
              check_cycles(neighbour, visited, adj, topo_order);
        }
        topo_order.push(start_node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // handle all the components
	    //create a visited array
	    int visited[V]={0};
	    //store the topo sort in a stack
	    stack<int> topo_order;
	    
	    //later on pop and push the elememts in the vector
	    //traverse the entire nodes and call dfs for unvisited
	    for(int i=0 ; i<V; i++){
	        if(!visited[i])
	          check_cycles(i, visited, adj, topo_order);
	    }
	    
	    //pop and push all the tops until stack is empty into the vector ans
	    vector<int> topo_sort;
	    while(!topo_order.empty()){
	        int ans = topo_order.top();
	        topo_order.pop();
	        topo_sort.push_back(ans);
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
