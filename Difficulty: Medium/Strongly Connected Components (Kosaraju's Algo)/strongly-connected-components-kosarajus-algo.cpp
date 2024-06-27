//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfsTraversal(int u,vector<vector<int>> &adjReverse,vector<bool>&visited){
	    visited[u]=true;
	    for (auto v:adjReverse[u]){
	        if (!visited[v]){
	           dfsTraversal(v,adjReverse,visited);
	        }
	    }
	    
	    
	    
	}
	void dfsFill(int u,vector<vector<int>>& adj,vector<bool>&visited,stack<int>&st){
	    visited[u]=true;
	    //iske neighbours pe jao
	    for (auto v:adj[u]){
	        if (!visited[v]){
	            dfsFill(v,adj,visited,st);
	        }
	    }
	    st.push(u);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //step 1 stack me order ko dalo
        stack<int>st;
        vector<bool>visited(V,false);
        for (int u=0;u<V;u++){
            if (!visited[u]){
                dfsFill(u,adj,visited,st);
            }
        }
    //step2 reverse karo
    vector<vector<int>> adjReverse(V);
    for(int u=0;u<V;u++){
        for(auto v:adj[u]){
            adjReverse[v].push_back(u);
        }
    }
    int countScc=0;
    visited=vector<bool>(V,false);
    //step 3 ek ek ko stalk se uthdkar traversal karo
      while (!st.empty()){
          int node=st.top();
          st.pop();
         if (!visited[node]){
             dfsTraversal(node,adjReverse,visited);
             countScc++;
         }
       
    }
    return countScc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends