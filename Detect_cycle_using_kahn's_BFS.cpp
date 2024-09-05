//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//If this code doesn't works for you, then remove the codes from line 15 to 32

// } Driver Code Ends
class Solution {
  public:
  //MISTAKE: - 
  //I was calculating indegree wrongly
  //I have to calculate the indegree of neighbours right
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
      // code here
        //we will use bfs and calculate the size of the topo sort and if
        //it comes equal to the number of Vector then we don't have any cycle
        //else we will return false
        
        //INTUITION :-
        //topological sort of a graph, is only valid for acylclic directed graph
        //and if we are able to calculate the topological sort of a graph then 
        //that means we don't have a cycle in it.
        //hence we are going to sue kahn's algorithm(Topo using bfs)
        
        //KAHN'S ALGORTIH :-
        //We use queue
        //We calculate indegree of each nodes
        //Push all the nodes with indegree equals to zero into the queue.
        //then traverse it's neighbours and reduce the indegree. that is we are imaginarily, omitting the edges
        //and once the indegree reaches zero, we again push ti to the queue.
        //Before traversing the neighbours of the current node, extracted from the queue
        //We will push it into the answer topo sort vector

        
        // CODE STARTED
        //create the indegree array
        int indegree[V]={0};
        //calculate the indegree
                //---------------incorrect code 
                /*
                for(int i=0;i<V;i++){
                    indegree[i]++;
                }
                */
        //--------------------------correct code
        for(int i=0;i<V;i++){
            for(auto neighbour : adj[i])
               indegree[neighbour]++;
        }
        //create a queue
        queue<int> tracker;
        //push the zero indegrees into the queue
        for(int i=0;i<V;i++){
            if(indegree[i]==0) tracker.push(i);
        }
        //create a topo sort vector
        vector<int> topo_sort;
        
        //until our queue gets empty
        while(!tracker.empty()){
        //get the current node
        int current_node = tracker.front();
        //pop it from the queue
        tracker.pop();
        //push it into the topo sort answer
        topo_sort.push_back(current_node);
        //traverse current node's neighbours
        for(auto neighbour : adj[current_node]){
        //reduce neighbour's indegree
          indegree[neighbour]--;
        //if zero-indegree is encountered then
          if(indegree[neighbour]==0) tracker.push(neighbour);
        //push it into the queue
          }
        }
        
        
        //later on
        //if the size of the topo-sort vector is equal to the number of nodes
        if(topo_sort.size()==V) return false; else return true;
        //then no cycle exists, return false
        //else return true;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
