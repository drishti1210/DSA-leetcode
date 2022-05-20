class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int src,vector<int> &visited , vector<int> adj[]){
        
        unordered_map<int, int>parent;
        parent[src]=-1;
        visited[src]=1;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto nbr : adj[front]){
                if(visited[nbr]==1 && nbr!=parent[front]){
                    return true;
                }
                else if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=1;
                    parent[nbr]=front;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
      
        
        vector<int> visited(V,0);
        for(int i = 0 ; i<V;i++){
            if(!visited[i]){
                bool ans = bfs(i,visited, adj);
                if(ans==true){ 
                    return true;
                       
                   }
            }
        }
        return false;
        
    }
};