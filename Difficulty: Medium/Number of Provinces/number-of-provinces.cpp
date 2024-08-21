//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int find(int u,vector<int>&parent){
      if (u==parent[u])return u;
      return parent[u]=find(parent[u],parent);
  }
  void unionbyrank(int u,int v,vector<int>&parent,vector<int>&rank){
      int parent_u=find(u,parent);
      int parent_v=find(v,parent);
      if (parent_u == parent_v)return;
      if (rank[parent_u]>rank[parent_v]){
          parent[parent_v]=parent_u;
      }else if (rank[parent_u]<rank[parent_v]){
          parent[parent_u]=parent_v;
      }else{
           parent[parent_u]=parent_v;
           rank[parent_v]++;
          
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>parent(V+1);
         vector<int>rank(V+1,0);
        for (int i=0;i<V+1;i++){
            parent[i]=i;
        }
       
       for (int i=0;i<adj.size();i++){
           for(int j=0;j<adj[0].size();j++){
               if (adj[i][j]==1&& i!=j){
                       unionbyrank(i+1,j+1,parent,rank);
                   
               }
         }
       }
      int cnt=0;
       for (int i=1;i<V+1;i++){
           if (parent[i]==i)cnt++;
       }
      return cnt;
      }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends