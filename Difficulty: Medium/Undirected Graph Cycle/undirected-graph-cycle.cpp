//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool detect(int sr,vector<int> adj[],vector<int>&vis,vector<int>&parent,int v){
       vis[sr]=1;
       parent[sr]=v;
       
       for (auto v:adj[sr]){
           if (!vis[v]){
              if(detect(v,adj,vis,parent,sr))return true;
           }else{
               if(parent[sr]!=v)return true;
           }
           
       }
       return false;
   }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       vector<int>vis(V,0);
       vector<int>parent(V,-1);
       for (int i=0;i<V;i++){
           if (!vis[i]){
              if (detect(i,adj,vis,parent,-1)) return true;
           }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends