//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool isCycleDFS(vector<int> adj[],vector<int>&visited,vector<int>&inRecurrsion,int u){
      visited[u]=true;
      inRecurrsion[u]=true;
      
      for(auto v:adj[u]){
          if (!visited[v] && isCycleDFS(adj,visited,inRecurrsion,v) ){
              
              return true;
              
          }else if (inRecurrsion[v]==true){//current call me hai
              return true;
          }
          
      }
      inRecurrsion[u]=false;
      return false;
      
      
      
      
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V,false);
        vector<int>inRecurrsion(V,false);//to check jisme call kiye usi me 
        for (int i=0;i<V;i++){
            if (!visited[i] && isCycleDFS(adj,visited,inRecurrsion,i)){
                return true;
            }
        }
        return false;
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