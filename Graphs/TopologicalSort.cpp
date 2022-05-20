class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void sort(int node, stack<int> &s, vector<int> &visited,vector<int>adj[] ){
	    visited[node]=1;
	    for(auto nbr: adj[node]){
	        if(!visited[nbr]){
	            sort(nbr,s, visited, adj);
	        }
	    }
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> visited(V, 0);
	    stack<int> s;
	    
	    for(int i = 0; i<V;i++){
	        if(!visited[i]){
	            sort(i, s, visited, adj);
	        }
	    }
	    
	    vector<int>ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};
