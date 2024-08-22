//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   
    int find(int u,vector<int>&parent){
        if (parent[u]==u)return u;
        return parent[u]=find(parent[u],parent);
    }
    void unionbyrank(int u,int v, vector<int>&rank,vector<int>&parent){
        int parent_u=find(u,parent);
        int parent_v=find(v,parent);
        if (parent_u==parent_v) return;
        if (rank[parent_u]>rank[parent_v]){
            parent[parent_v]=parent_u;
        }else if(rank[parent_u]<rank[parent_v]){
              parent[parent_u]=parent_v;
        }else {
              parent[parent_u]=parent_v;
              rank[parent_v]++;
        }
            
        
        
    }
    
    int Solve(int n, vector<vector<int>>& edge) {
      vector<int>parent(n);
      vector<int>rank(n,0);
      for (int i=0;i<n;i++){
          parent[i]=i;
      }
      int extraedge=0;
      for (auto e:edge){
          int u=find(e[0],parent);
          int v=find(e[1],parent);
          if (u!=v){
              unionbyrank(e[0],e[1],rank,parent);
          }else extraedge++;
      }
      int nc=0;
      for (int i=0;i<n;i++){
          if (parent[i]==i)nc++;
      }
      int ans=nc-1;
      if (extraedge>=ans){
          return ans;
      }else return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends