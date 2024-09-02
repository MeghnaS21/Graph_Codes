class Solution {
    private:
    bool check(int start, vector<int>&color, vector<vector<int>>& graph){
        color[start]=0;
        queue<int> tracker;
        tracker.push(start);

        while(!tracker.empty()){
            int current_node = tracker.front();
            tracker.pop();

            for(auto neighbour : graph[current_node]){
                if(color[neighbour]==-1){
                    color[neighbour]=!color[current_node];
                    tracker.push(neighbour);
                }
                else if(color[neighbour]== color[current_node]) return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(i, color, graph)==false)
                  return false;
            }
        }
        return true;
    }
};
