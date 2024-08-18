//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool dfs(int u, vector<int> adj[],vector<int>&vis){
      vis[u]=1;
      //neighbour
      for (auto v:adj[u]){
          if (vis[v]==0){
              if (dfs(v,adj,vis))return true;
          }else if (vis[v]==1)return true;
      }
      vis[u]=2;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int>vis(V,0);
       for (int i=0;i<V;i++){
           if (!vis[i]){
              if (dfs(i,adj,vis)) return true;
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