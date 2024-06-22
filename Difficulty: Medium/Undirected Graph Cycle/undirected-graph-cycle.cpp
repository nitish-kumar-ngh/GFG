//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool isCycleBFS(vector<int> adj[],int u,vector<int>&visited){
    queue<pair<int,int> >que;
    que.push({u,-1});
    visited[u]=true;
    while (que.size()>0){
        auto ans=que.front();
        que.pop();
        int source=ans.first;
        int parent= ans.second;
        for (auto v:adj[source]){
            if (!visited[v]){
                que.push({v,source});
                visited[v]=true;
            }else if (v!=parent) {
                return true;
            }
        }
    }
    return false;
      
  }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,false);
        for (int i=0;i<V;i++){
            if (!visited[i] && isCycleBFS(adj,i,visited)) return true;
        }
        return false;
        // Code here
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