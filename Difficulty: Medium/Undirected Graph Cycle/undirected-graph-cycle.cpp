//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool detect(int sr,vector<int>adj[], vector<bool>&vis,vector<int>p[]){
        queue<int>q;
     q.push(sr);
     p[sr].push_back(-1);
     vis[sr]=1;
     while(!q.empty()){
         int node=q.front();
         q.pop();
         //neighbour
         for (auto v:adj[node]){
             
             if (!vis[v]){
                 p[v].push_back(node);
                 
                 q.push(v);
                 vis[v]=1;
             }else{
                 if (p[node][0]!=v)return true;
             }
         }
     }
     
     
     return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
     vector<bool>vis(V,0);
     vector<int>p[V];
     for (int i=0;i<V;i++){
         if (!vis[i]){
           if (detect(i,adj,vis,p))return true;
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